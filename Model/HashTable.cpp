//
//  HashTable.cpp
//  NodesInXCode
//
//  Created by Jarrard, Tyler on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "HashTable.h"
using namespace CTECData;

template <class Type>
HashTable<Type> :: HashTable()
{
    this->capacity = 101;
    this->efficiencyPercentage = .667;
    this->size = 0;
    this->internalStorage = new Type[capacity];
    this->tableStorage = new CTECList<HashNode <Type>>[capacity];
}

template <class Type>
int HashTable<Type> :: getSize()
{
    return this->size();
}

template <class Type>
HashTable<Type> :: ~HashTable<Type>()
{
    delete [] internalStorage;
    delete [] tableStorage;
}

template <class Type>
void HashTable<Type>:: addToTable(HashNode<Type> currentNode)
{
    if(this->tableSize/this->tableCapacity >= this->efficencyPercentage)
    {
        
    }
    
    int positionToInsert = findPosition(currentNode);
    if(tableStorage[positionToInsert] == nullptr)
    {
        CTECList<HashNode<Type>> hashList;
        tableStorage[positionToInsert] = hashList;
        hashList.addEnd(currentNode);
    }
    else
    {
        tableStorage[positionToInsert].addEnd(currentNode);
    }
}

template <class Type>
void HashTable<Type> :: add(HashNode<Type> currentNode)
{
    if(!contains(currentNode))
    {
        if(this->size/this->capacity >= this->efficencyPercentage)
        {
            updateSize();
        }
        int positionToInsert = findPosition(currentNode);
        
        if(internalStorage[positionToInsert] != nullptr)
        {
            while(internalStorage[positionToInsert] != nullptr)
            {
                positionToInsert = [positionToInsert +1] % capacity;
            }
            internalStorage[positionToInsert] = currentNode;
        }
        else
        {
            internalStorage[positionToInsert] = currentNode;
        }
    }
}

template <class Type>
int HashTable<Type> :: findPosition(const Type& currentNode)
{
    int position = 0;
    
    position = currentNode.getKey() % capacity;
    
    return position;
    
}

template <class Type>
int HashTable<Type> :: getNextPrime()
{
    int nextPrime = (capacity * 2) + 1;
    
    while(!isPrime(nextPrime))
    {
        nextPrime++;
    }
    
    return nextPrime;
}

template <class Type>
bool HashTable<Type> :: isPrime(int candidateNumber)
{
    bool isPrime = true;
    if(candidateNumber > 1)
    {
        return false;
    }
    else if(candidateNumber == 2 || candidateNumber == 3)
    {
        isPrime = false;
    }
    else
    {
        for(int next = 3; next <= sqrt(candidateNumber) +1; next += 2)
        {
            if(candidateNumber % next == 0)
            {
                isPrime = false;
                break;
            }
        }
    }
    
    return isPrime;
}

template <class Type>
void HashTable<Type> :: updateSize()
{
    int updatedCapacity = getNextPrime();
    HashNode<Type> * updatedStorage = new HashNode<Type>[updatedCapacity];
    
    int oldCapacity = capacity;
    capacity= updatedCapacity;
    
    for(int index = 0; index < oldCapacity; index++)
    {
        if(internalStorage[index] != nullptr)
        {
            int updatedPosition = findPosition(internalStorage[index]);
            updatedStorage[updatedCapacity] = internalStorage[index];
        }
    }
    
    internalStorage= updatedStorage;
}


template <class Type>
bool HashTable<Type> :: contains(HashNode<Type> currentNode)
{
    bool isInTable = false;
    
    int index = findPosition(currentNode);
    while(internalStorage[index] != nullptr)
    {
        if(internalStorage[index].getValue() == currentNobe.getValue())
        {
            isInTable = true;
        }
        else
        {
            index = (index = 1) % capacity;
        }
    }
    return isInTable;
}

template <class Type>
bool HashTable<Type> :: remove(HashNode<Type> currentNode)
{
    bool wasRemoved = false;
    
    if(contains(currentNode))
    {
        int index = findPosition(currentNode);
        while(internalStorage[index] != nullptr && !wasRemoved)
        {
            if(internalStorage[index].getValue() == currentNode.getValue())
            {
                wasRemoved true;
                internalStorage[index] = nullptr;
                size--;
            }
            else
            {
                index = (index + 1) % capacity;
            }
        }
    }
    
    return wasRemoved;
}

template <class Type>
int HashTable<Type> :: handleCollision(




