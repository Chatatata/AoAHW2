//
//  QuickSortingStrategy.hpp
//  AlgoHW2
//
//  Created by Buğra Ekuklu on 04.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#pragma once

#include "../PrefixHeader.pch"
#include "../Containers/Array.hpp"

namespace Container {
    
    template <typename T, class InfectableContainer = Array<T>>
    class QuickSortingStrategy {
    public:
        virtual ~QuickSortingStrategy() { }
        
        virtual void sort() noexcept = 0;
        
    protected:
        virtual void supervisor(const Int startIndex, const Int endIndex) noexcept = 0;
        virtual Size worker(const Int startIndex, const Int endIndex) noexcept = 0;
    };
}
