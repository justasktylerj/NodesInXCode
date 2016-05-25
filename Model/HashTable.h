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
#include "CTECList.h"

template <class Type>
class HashTable
{
private:
    int size;
    int capacity;
    double efficiencyPercentage;
    HashNode<Type> ** internalStorage;
    CTECList<HashNode <Type>> * tableStorage;
    
    int findPosition(HashNode<Type> currentNode);
    int findTablePosition(HashNode<Type>);
    int handleCollision(HashNode<Type> currentNode);
    void updateSize();
    void updateTableCapacity();
    int getNextPrime();
    bool isPrime(int candidateNumber);
public:
    HashTable();
    ~HashTable();
    int getSize();
    void add(HashNode<Type> currentNode);
    void addToTable(HashNode<Type> currentNode);
    bool remove(HashNode<Type> currentNode);
    bool contains(HashNode<Type> currentNode);
};



#endif /* HashTable_h */
