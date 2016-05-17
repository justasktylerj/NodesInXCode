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
    
    int findPosition(HashNode<Type> currentNode);//Done
    int findTablePosition(HashNode<Type>);//Done
    int handleCollision(HashNode<Type> currentNode);//Done
    void updateSize();//Done
    void updateTableCapacity();//Done
    int getNextPrime();//Done
    bool isPrime(int candidateNumber);//Done
public:
    HashTable();//Done
    ~HashTable();//Done
    int getSize();//Done
    void add(HashNode<Type> currentNode);//Done
    void addToTable(HashNode<Type> currentNode);//Done
    bool remove(HashNode<Type> currentNode);//Done
    bool contains(HashNode<Type> currentNode);//Done
};



#endif /* HashTable_h */
