//
//  Line.cpp
//  AlgoHW2
//
//  Created by Buğra Ekuklu on 02.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#include "Line.hpp"

Line::Line(const Int id,
           const Array<SemanticWord> &semanticWords)
: id(id), semanticWords(semanticWords)
{

}

Int
Line::getID() const noexcept
{
    return id;
}

Boolean
Line::operator < (const Line &candidate) const noexcept
{
    return id < candidate.id;
}
    
Boolean
Line::operator <= (const Line &candidate) const noexcept
{
    return id <= candidate.id;
}

Boolean
Line::operator >= (const Line &candidate) const noexcept
{
    return id >= candidate.id;
}
