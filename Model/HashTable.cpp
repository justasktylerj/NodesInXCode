//
//  HashTable.cpp
//  NodesInXCode
//
//  Created by Jarrard, Tyler on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "HashTable.h"
#include <cmath>

template <class Type>
HashTable<Type> :: HashTable()
{
    this->capacity = 101;
    this->efficiencyPercentage = .667;
    this->size;
    this->internalStorage = new HashNode<Type>*[capacity];
    this->tableStorage = new CTECList<HashNode <Type>>[capacity];
}

template <class Type>
HashTable<Type> :: ~HashTable()
{
    delete [] internalStorage;
    delete [] tableStorage;
}

template <class Type>
int HashTable<Type> :: getSize()
{
    return this->size();
}

template <class Type>
void HashTable<Type> :: addToTable(HashNode<Type> currentNode)
{
    if (this->size/this->capacity >= this->efficiencyPercentage)
    {
        updateTableCapacity();
    }
    //Find where to put the value
    int positionToInsert = findPosition(currentNode);
    //If the spot is empty, make a new list and add the node
    if (tableStorage[positionToInsert] == nullptr)
    {
        CTECList<HashNode<Type>> hashList;
        tableStorage[positionToInsert] = hashList;
        hashList.addEnd(currentNode);
    }
    else //Add the node
    {
        tableStorage[positionToInsert].addEnd(currentNode);
    }
}

template <class Type>
void HashTable<Type> :: add(HashNode<Type> currentNode)
{
    if (!contains(currentNode))
    {
        if (this->size/this->capacity >= this->efficiencyPercentage)
        {
            updateSize();
        }
        
        int positionToInsert = findPosition(currentNode);
        
        if (internalStorage[positionToInsert] != nullptr)
        {
            while (internalStorage[positionToInsert] != nullptr)
            {
                positionToInsert = (positionToInsert + 1) % capacity;
            }
            internalStorage[positionToInsert] = &currentNode;
        }
        
        internalStorage[positionToInsert] = &currentNode;
        size++;
    }
}


template <class Type>
int HashTable<Type> :: findPosition(HashNode<Type> currentNode)
{
    //We are going to "hash" the key the of HashNode to find its storage spot.
    int position = 0;
    
    position = currentNode.getKey() % capacity;
    
    return position;
}


template <class Type>
void HashTable<Type> :: updateSize()
{
    int updatedCapacity = getNextPrime();
    HashNode<Type> ** updatedStorage = new HashNode<Type>*[updatedCapacity];
    
    int oldCapacity = capacity;
    capacity = updatedCapacity;
    
    for (int index = 0; index < oldCapacity; index++)
    {
        if (internalStorage[index] != nullptr)
        {
            int updatedPosition = findPosition(*internalStorage[index]);
            updatedStorage[updatedPosition] = internalStorage[index];
        }
    }
    
    internalStorage = updatedStorage;
}

template <class Type>
void HashTable<Type> :: updateTableCapacity()
{
    int updatedCapacity = getNextPrime();
    CTECList<HashNode<Type>> * updateTable = new CTECList<HashNode<Type>>[updatedCapacity];
    
    int oldTableCapacity = capacity;
    capacity = updatedCapacity;
    
    for (int index = 0; index < oldTableCapacity; index++)
    {
        if (tableStorage[index] != nullptr)
        {
            CTECList<HashNode<Type>> temp = tableStorage[index];
            for (int innerIndex = 0; innerIndex < tableStorage[index].getSize(); innerIndex++)
            {
                int updatedTablePosition = findPosition(temp.get(index));
                if (updateTable[updatedTablePosition] == nullptr)
                {
                    CTECList<HashNode<Type>> updatedList;
                    updatedList.addEnd(temp.get(index));
                }
                else
                {
                    updateTable[updatedTablePosition].addEnd(temp.getFromIndex(index));
                }
            }
        }
    }
    
    tableStorage = updateTable;
}

template <class Type>
int HashTable<Type> :: getNextPrime()
{
    int nextPrime = (capacity * 2) + 1;
    
    while (!isPrime(nextPrime))
    {
        nextPrime++;
    }
    
    return nextPrime;
}

template <class Type>
bool HashTable<Type> :: isPrime(int candidateNumber)
{
    bool isPrime = true;
    
    if (candidateNumber < 1)
    {
        return false;
    }
    else if (candidateNumber == 2 || candidateNumber == 3)
    {
        isPrime = true;
    }
    else if (candidateNumber % 2 == 0)
    {
        isPrime = false;
    }
    else
    {
        for (int next = 0; next <= sqrt(candidateNumber) + 1; next += 2)
        {
            if (candidateNumber % next == 0)
            {
                isPrime = false;
                break;
            }
        }
    }
    
    return isPrime;
}

template <class Type>
bool HashTable<Type> :: contains(HashNode<Type> currentNode)
{
    bool isInTable = false;
    
    int index = findPosition(currentNode);
    
    while (internalStorage[index] != nullptr && !isInTable)
    {
        if (internalStorage[index]->getValue() == currentNode.getValue())
        {
            isInTable = true;
        }
        else
        {
            index = (index + 1) % capacity;
        }
    }
    
    return isInTable;
}

template <class Type>
bool HashTable<Type> :: remove(HashNode<Type> currentNode)
{
    bool wasRemoved = false;
    if (contains(currentNode))
    {
        int index = findPosition(currentNode);
        
        while (internalStorage[index] != nullptr && !wasRemoved)
        {
            if (internalStorage[index].getValue() == currentNode.getValue())
            {
                wasRemoved = true;
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
int HashTable<Type> :: handleCollision(HashNode<Type> currentNode)
{
    int reHashedPosition = findPosition(currentNode);
    int random = rand();
    reHashedPosition = (random + (reHashedPosition * reHashedPosition)) % capacity;
    
    return reHashedPosition;
}



