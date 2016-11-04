//
//  SemanticWord.hpp
//  AlgoHW2
//
//  Created by Buğra Ekuklu on 02.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#pragma once

#include "Word.hpp"

class SemanticWord : public Word {
private:
    Int order = 0;
    
public:
    SemanticWord(Word word, Int order);
    
    Int getOrder() const noexcept;
    Boolean operator < (const SemanticWord &candidate) const noexcept;
    Boolean operator <= (const SemanticWord &candidate) const noexcept;
    Boolean operator >= (const SemanticWord &candidate) const noexcept;
};
