//
//  LineCountedQuickSortStrategy.cpp
//  AlgoHW2
//
//  Created by Buğra Ekuklu on 04.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#include "LineCountedQuickSortStrategy.hpp"

#include <iostream>

using Container::LineCountedQuickSortStrategy;

template <class InfectableContainer>
LineCountedQuickSortStrategy<InfectableContainer>::LineCountedQuickSortStrategy(const InfectableContainer &array,
                                                                                  const UInt64 counterBreakpoint,
                                                                                  const UInt64 lineIndex)
: DeterministicQuickSortStrategy<Line, InfectableContainer>(array), counterBreakpoint(counterBreakpoint), lineIndex(lineIndex)
{
    
}

template <class InfectableContainer>
const AtomicUInt64 &
LineCountedQuickSortStrategy<InfectableContainer>::getCounter() const noexcept
{
    return counter;
}


template <class InfectableContainer>
void
LineCountedQuickSortStrategy<InfectableContainer>::supervisor(const Int startIndex,
                                                               const Int endIndex) noexcept
{
    counter += 1;
    
    if (counter.load() == counterBreakpoint) {
        std::cout << DeterministicQuickSortStrategy<Line, InfectableContainer>::array[lineIndex].id << std::endl;
    }
    
    DeterministicQuickSortStrategy<Line, InfectableContainer>::supervisor(startIndex, endIndex);
}
