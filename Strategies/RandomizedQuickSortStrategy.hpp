//
//  RandomizedQuickSortStrategy.hpp
//  AlgoHW2
//
//  Created by Buğra Ekuklu on 04.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#pragma once

#include "DeterministicQuickSortStrategy.cpp"

namespace Container {
    
    template <typename T, class InfectableContainer = Array<T>>
    class RandomizedQuickSortStrategy : public DeterministicQuickSortStrategy<T, InfectableContainer> {
    public:
        RandomizedQuickSortStrategy(const Array<T> &object);
        
    private:
        Size worker(const Int startIndex, const Int endIndex) noexcept override;
    };
}
