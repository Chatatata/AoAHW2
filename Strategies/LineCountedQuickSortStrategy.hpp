//
//  LineCountedQuickSortStrategy.hpp
//  AlgoHW2
//
//  Created by Buğra Ekuklu on 04.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#pragma once

#include "DeterministicQuickSortStrategy.hpp"
#include "../Models/Line.hpp"

namespace Container {
    
    template <class InfectableContainer = Array<Line>>
    class LineCountedQuickSortStrategy : public DeterministicQuickSortStrategy<Line, InfectableContainer> {
    private:
        AtomicUInt64 counter;
        const UInt64 counterBreakpoint = 0;
        const UInt64 lineIndex = 0;
        
    public:
        LineCountedQuickSortStrategy(const InfectableContainer &object, const UInt64 counterBreakpoint, const UInt64 lineIndex);
        
        const AtomicUInt64 &getCounter() const noexcept;
        
        void supervisor(const Int startIndex, const Int endIndex) noexcept override;
    };
}
