//
//  HashTable.hpp
//  NodesInXCode
//
//  Created by Jarrard, Tyler on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include <stdio.h>

#endif /* HashTable_h */

namespace CTECData
{
    template <class Type>
    class HashTable
    {
    private:
        int capacity;
        double efficiencyPercentage;
        int size;
        Type * internalStorage;
        
        int findPosition(const Type& value);
        int handleCollision(const Type& value);
        void updateSize();
        
    public:
        MorningHashTable();
        ~MorningHashTable();
        void add(const Type& value);
        bool remove(const Type& value);
        bool contains(const Type& value);
    };
}