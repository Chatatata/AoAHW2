//
//  DeterministicQuickSortStrategy.cpp
//  AlgoHW2
//
//  Created by Buğra Ekuklu on 31.10.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#include "DeterministicQuickSortStrategy.hpp"

#include <algorithm>
#include <utility>

using Container::DeterministicQuickSortStrategy;

template <typename T, class InfectableContainer>
DeterministicQuickSortStrategy<T, InfectableContainer>::DeterministicQuickSortStrategy()
: array(InfectableContainer())
{
    //  Intentionally left blank
}

template <typename T, class InfectableContainer>
DeterministicQuickSortStrategy<T, InfectableContainer>::DeterministicQuickSortStrategy(const InfectableContainer &object)
: array(object)
{
    //  Intentionally left blank
}

template <typename T, class InfectableContainer>
inline
void
DeterministicQuickSortStrategy<T, InfectableContainer>::sort() noexcept
{
    //  Instantiate algorithm manifest
    supervisor(0, array.size() - 1);
}

template <typename T, class InfectableContainer>
void
DeterministicQuickSortStrategy<T, InfectableContainer>::supervisor(const Int startIndex,
                                                    const Int endIndex) noexcept
{
    if (startIndex < endIndex) {
        auto pivot = worker(startIndex, endIndex);
        
        supervisor(startIndex, pivot - 1);
        supervisor(pivot + 1, endIndex);
    }
}

template <typename T, class InfectableContainer>
Size
DeterministicQuickSortStrategy<T, InfectableContainer>::worker(const Int startIndex,
                                         const Int endIndex) noexcept
{
    auto pivotValue = array[endIndex];

    auto i = startIndex - 1;
    
    for (auto j = startIndex; j < endIndex; ++j) {
        if (array.at(j) <= pivotValue) {
            i += 1;
            
            std::swap(array[i], array[j]);
        }
    }
    
    std::swap(array[i + 1], array[endIndex]);
    
    return i + 1;
}








