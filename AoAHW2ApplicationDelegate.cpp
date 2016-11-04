//
//  AoAHW2ApplicationDelegate.cpp
//  AlgoHW2
//
//  Created by Buğra Ekuklu on 04.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#include "AoAHW2ApplicationDelegate.hpp"

#include <cassert>
#include <iostream>
#include <sstream>
#include <iterator>
#include <fstream>

#include "Strategies/LineCountedQuickSortStrategy.cpp"
#include "Strategies/RandomizedQuickSortStrategy.cpp"
#include "IO/Parser.hpp"

static const Boolean enableAssertions = false;

UInt16
AoAHW2ApplicationDelegate::applicationDidStart(const Container::Array<String> &arguments) const noexcept
{
    if (std::atoi(arguments[1].data()) == 1) {
        using Container::LineCountedQuickSortStrategy;
        using Container::RandomizedQuickSortStrategy;
        using Container::Array;
        
        Parser reader("mobydick.txt");
        std::ofstream outputFile("novel.txt");
        
        LineCountedQuickSortStrategy<> lines(reader.getLines(), std::atol(arguments[2].data()), std::atol(arguments[3].data()));
        
        lines.sort();
        
        for (auto &line : lines.array) {
            RandomizedQuickSortStrategy<SemanticWord> sortableArray(line.semanticWords);
            
            sortableArray.sort();
            
            for (auto &word : sortableArray.array) {
                outputFile << word << " ";
            }
                
            outputFile << std::endl;
        }
    } else if (std::atoi(arguments[1].data()) == 2) {
        using Container::DeterministicQuickSortStrategy;
        
        Array<UInt64> array;
        std::ifstream inputFile("numbers_to_sort.txt");
        std::ofstream outputFile("numbers.txt");
        String string;
        
        for (Size i = 0; i < static_cast<Size>(std::atoi(arguments[2].data())) && std::getline(inputFile, string); ++i) {
            array.push_back(std::atol(string.data()));
        }
        
        DeterministicQuickSortStrategy<UInt64> dqsa(array);
        
        dqsa.sort();
        
        for (auto &number : dqsa.array) {
            outputFile << number << std::endl;
        }
        
        if (enableAssertions) {
            for (Int i = 0; i < static_cast<Int>(dqsa.array.size() - 1); ++i) {
                assert(dqsa.array[i + 1] >= dqsa.array[i]);
            }
        }
    }
    
    return 0;
}
