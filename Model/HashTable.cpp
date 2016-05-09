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
}


template <class Type>
void HashTable<Type> :: add(const Type& value)
{
    if(!contains(value))
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