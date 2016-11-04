//
//  Parser.cpp
//  AlgoHW2
//
//  Created by Buğra Ekuklu on 02.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#include "Parser.hpp"

#include <fstream>
#include <algorithm>
#include <sstream>
#include <istream>
#include <iterator>
#include <functional>

#include "../Models/SemanticWord.hpp"

static const String tokenDelimiter = "_";

Array<String> tokenize(String string, const String delimiter) {
    Array<String> tokens;
    
    Size start = string.find_first_not_of(delimiter);
    Size end = start;
    
    while (start != std::string::npos) {
        end = string.find(delimiter, start);
        
        tokens.push_back(string.substr(start, end - start));
        
        start = string.find_first_not_of(delimiter, end);
    }
    
    return tokens;
}

Parser::Parser(String fileName)
: lines()
{
    std::ifstream inputFile(fileName.data());
    
    String line;
    
    while (std::getline(inputFile, line)) {
        std::stringstream stream(line);
        
        std::istream_iterator<String> iterator(stream);
        std::istream_iterator<String> end;
        std::vector<std::string> components(iterator, end);
        
        auto eraseFirstAndLastCharacterAndTokenize = [] (String string) {
            string.erase(0, 1);
            string.erase(string.size() - 1, 1);
            
            return tokenize(string, tokenDelimiter);
        };
        
        Array<Word> words = eraseFirstAndLastCharacterAndTokenize(components[1]);
        
        auto stringWordOrders = eraseFirstAndLastCharacterAndTokenize(components[2]);
        
        Array<UInt32> wordOrders;
        
        for (auto &stringWordOrder : stringWordOrders) {
            wordOrders.push_back(std::atoi(stringWordOrder.data()));
        }
        
        Array<SemanticWord> semanticWords;
        
        for (Size i = 0; i < wordOrders.size(); ++i) {
            semanticWords.push_back(SemanticWord(words[i], wordOrders[i]));
        }
        
        lines.push_back(Line(std::atol(components[0].data()),
                             semanticWords));
    }
    
    
}

Container::Array<Line>
Parser::getLines() const noexcept
{
    return lines;
}
