//
//  Parser.hpp
//  AlgoHW2
//
//  Created by Buğra Ekuklu on 02.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#pragma once

#include "../PrefixHeader.pch"

#include "../Containers/Array.hpp"
#include "../Models/Line.hpp"

class Parser {
public:
    Parser(String fileName);
    
    Container::Array<Line> getLines() const noexcept;
    
private:
    Container::Array<Line> lines;
};
