//
//  HashTable.hpp
//  NodesInXCode
//
//  Created by Jarrard, Tyler on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include "HashNode.cpp"
#include "CTECList.cpp"
#include <stdio.h>

#endif /* HashTable_h */

namespace CTECData
{
    template <class Type>
    class HashTable
    {
    private:
        int tableCapacity;

        double efficiencyPercentage;
        int tableSize;
        HashNode<Type> * internalStorage;
        CTECList<HashNode <Type>> * tableStorage;
        
        int findPosition(HashNode<Type> currentNode);
        int handleCollision(HashNode<Type> currentNode);
        void updateSize();
        
        int getNextPrime();
        bool isPrime(int candidateNumber);
        
    public:
        HashTable();
        ~HashTable();
        
        void add(HashNode<Type> currentNode);
        void addToTable(HashNode<Type> currentNode);
        
        bool remove(HashNode<Type> currentNode);
        bool contains(HashNode<Type> currentNode);
        int getSize();
    };
}