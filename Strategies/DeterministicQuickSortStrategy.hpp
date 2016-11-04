//
//  DeterministicQuickSortStrategy.hpp
//  AlgoHW2
//
//  Created by Buğra Ekuklu on 31.10.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#pragma once

#include "QuickSortingStrategy.hpp"

namespace Container {
    
    template <typename T, class InfectableContainer = Array<T>>
    class DeterministicQuickSortStrategy : public QuickSortingStrategy<T, InfectableContainer> {
    public:
        DeterministicQuickSortStrategy();
        DeterministicQuickSortStrategy(const InfectableContainer &object);
        
        InfectableContainer array;
        
        void sort() noexcept override;
        
    protected:
        void supervisor(const Int startIndex, const Int endIndex) noexcept override;
        Size worker(const Int startIndex, const Int endIndex) noexcept override;
    };
}




