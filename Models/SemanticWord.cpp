//
//  SemanticWord.cpp
//  AlgoHW2
//
//  Created by Buğra Ekuklu on 02.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#include "SemanticWord.hpp"

SemanticWord::SemanticWord(Word word,
                           Int order)
: Word(word), order(order)
{
    
}

Int
SemanticWord::getOrder() const noexcept
{
    return order;
}

Boolean
SemanticWord::operator < (const SemanticWord &candidate) const noexcept
{
    return order < candidate.order;
}
    
Boolean
SemanticWord::operator <= (const SemanticWord &candidate) const noexcept
{
    return order <= candidate.order;
}
    
Boolean
SemanticWord::operator >= (const SemanticWord &candidate) const noexcept
{
    return order >= candidate.order;
}
