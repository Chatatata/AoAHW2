//
//  RandomizedQuickSortStrategy.cpp
//  AlgoHW2
//
//  Created by Buğra Ekuklu on 04.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#include "RandomizedQuickSortStrategy.hpp"

#include <cstdlib>

using Container::RandomizedQuickSortStrategy;

template <typename T, class InfectableContainer>
RandomizedQuickSortStrategy<T, InfectableContainer>::RandomizedQuickSortStrategy(const Array<T> &object)
: DeterministicQuickSortStrategy<T, InfectableContainer>(object)
{
    std::srand(255);
}

template <typename T, class InfectableContainer>
Size
RandomizedQuickSortStrategy<T, InfectableContainer>::worker(const Int startIndex, const Int endIndex) noexcept
{
    auto i = (std::rand() % (endIndex - startIndex)) + startIndex;
    
    std::swap(DeterministicQuickSortStrategy<T, InfectableContainer>::array[endIndex],
              DeterministicQuickSortStrategy<T, InfectableContainer>::array[i]);
    
    return DeterministicQuickSortStrategy<T, InfectableContainer>::worker(startIndex, endIndex);
}
