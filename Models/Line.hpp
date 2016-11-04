//
//  Line.hpp
//  AlgoHW2
//
//  Created by Buğra Ekuklu on 02.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#pragma once

#include "../PrefixHeader.pch"

#include "../Containers/Array.hpp"
#include "SemanticWord.hpp"

using Container::Array;

class Line {
public:
    Line(const Int id, const Array<SemanticWord> &semanticWords);
    
    Int id;
    Array<SemanticWord> semanticWords;
    
public:
    Int getID() const noexcept;
    Boolean operator < (const Line &candidate) const noexcept;
    Boolean operator <= (const Line &candidate) const noexcept;
    Boolean operator >= (const Line &candidate) const noexcept;
};
