/*
 * CTECList.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: tjar2074
 */
#include "CTECList.h"
#include <assert.h>
using namespace std;

using namespace CTECData;

template<class Type>
CTECList<Type>::CTECList()
{
    this->size = 0;
    this->head = nullptr;
    this->end = nullptr;
    
}

template<class Type>
CTECList<Type>::~CTECList()
{
    
    ArrayNode<Type> * current = head;
    
    for (int deleteCount = 0; deleteCount < size; deleteCount++)
    {
        ArrayNode<Type> * temp = current;
        
        current = current->getNext();
        head = current;
        delete temp;
    }
    
    while (current->getNext() != nullptr)
    {
        ArrayNode<Type> * temp = current;
        
        current = current->getNext();
        head = current;
        delete temp;
    }
    
    delete head;
    head = nullptr;
    end = nullptr;
    size = 0;
}

template<class Type>
void CTECList<Type>::addToFront(const Type& value)
{
    ArrayNode<Type> * newStuff = new ArrayNode<Type>(value, head);
    head = newStuff;
    if(size == 0)
    {
        end = head;
    }
    
    calculateSize();
}

template<class Type>
void CTECList<Type>::addToEnd(const Type& value)
{
    ArrayNode<Type> * newStuff;
    if(end == nullptr)
    {
        addToFront(value);
    }
    else
    {
        newStuff = new ArrayNode<Type>(value);
        end->setNext(newStuff);
    }
    end = newStuff;
    
    calculateSize();
}

template<class Type>
void CTECList<Type>::addAtIndex(int index, const Type& value)
{
    assert(index < size && index >= 0);
    
    if(index == 0)
    {
        addToFront(value);
    }
    if(index == size-1)
    {
        addToEnd(value);
    }
    else
    {
        ArrayNode<Type> * insertedNode = new ArrayNode<Type>(value);
        ArrayNode<Type> * current = head;
        for (int position = 0; position < index; position++)
        {
            current = current->getNext();
        }
        
        insertedNode->setNext(current->getNext());
        current->setNext(insertedNode);
    }
    calculateSize();
    
}

template<class Type>
Type CTECList<Type>::removeFromFront()
{
    Type returnValue;
    
    assert(size > 0);
    ArrayNode<Type> * newHead;
    newHead = this->head->getNext();
    
    returnValue = this->head->getValue();
    delete this->head;
    this->head = newHead;
    this->calculateSize();
    
    return returnValue;
}

template<class Type>
Type CTECList<Type>::getFront()
{
    return head->getValue();
}

template<class Type>
Type CTECList<Type>::getEnd()
{
    return end->getValue();
}

template<class Type>
Type CTECList<Type>::getFromIndex(int index)
{
    assert(size > 0 && index >= 0 && index < size);
    Type returnValue;
    ArrayNode<Type> * current = head;
    
    for(int spot = 0; spot <= index; spot++)
    {
        if(spot == index)
        {
            returnValue = current->getValue();
        }
        current = current->getNext();
    }
    return returnValue;
}

template<class Type>
Type CTECList<Type>::removeFromIndex(int index)
{
    assert(this->size > 0);

    assert(index >= 0 && index < size);
    
    Type thingToRemove;

    ArrayNode<Type> * previous;
    ArrayNode<Type> * deleteMe;
    ArrayNode<Type> * newNext;
    
    if (index == 0)
    {
        thingToRemove = removeFromFront();
    }
    else if (index == size - 1)
    {
        thingToRemove = removeFromEnd();
    }
    else
    {
        ArrayNode<Type> * current = head;
        for (int spot = 0; spot < index + 1; spot++)
        {
            if (spot == index - 1)
            {
                previous = current;
            }
            else if (spot == index)
            {
                deleteMe = current;
                newNext = current->getNext();
            }
        }
        
        thingToRemove = deleteMe->getValue();
        previous->setNext(newNext);
        delete deleteMe;
        
        this->calculateSize();
    }
    return thingToRemove;
}

template<class Type>
Type CTECList<Type>::removeFromEnd()
{
    assert(size > 0);
    
    Type returnValue;
    
    if (size == 1)
    {
        ArrayNode<Type> * toRemove = end;
        returnValue = removeFromFront();
        end = nullptr;
        head = nullptr;
        delete toRemove;
    }
    else
    {
        ArrayNode<Type> * current = head;
        for (int index = 0; index < size - 1; index++)
        {
            current = current->getNext();
        }
        returnValue = end->getValue();
        delete end;
        current = end;
        current->setNext(nullptr);
    }
    
    calculateSize();
    
    return returnValue;
}

template<class Type>
void CTECList<Type>::calculateSize()
{
    assert(size >= 0);
    
    int count = 0;
    if (head == nullptr)
    {
        size = count;
    }
    else
    {
        count++;
        ArrayNode<Type> * current = head;
        while (current->getNext() != nullptr)
        {
            count++;
            current = current->getNext();
        }
        size = count;
    }
    
}

template <class Type>
int CTECList<Type> :: indexOf(Type searchValue)
{
    assert(this->size >0);
    
    int index = 0;
    
    ArrayNode<Type> * searchPointer;
    
    for(searchPointer = head; searchPointer != nullptr; searchPointer = searchPointer->getNext())
    {
        if(searchValue == searchPointer->getValue())
        {
            return index;
        }
        index++;
    }
    index = -1;
    return index;
}

template <class Type>
int CTECList<Type> :: nextIndexOf(int startingIndex, Type searchValue)
{
    assert(this->size > 0);
    assert(startingIndex >= 0 && startingIndex < this->size);
    
    ArrayNode<Type> * current = head;
    int indexNotFound = -1;
    
    for(int index = 0; index<startingIndex; index++)
    {
        current = current->getNext();
    }
    
    for(int index = startingIndex; index < this->size; index++)
    {
        if(current->getValue() == searchValue)
        {
            return index;
        }
        else
        {
            current = current->getValue();
        }
    }
    
    return indexNotFound;
}

template<class Type>
Type CTECList<Type>::set(int index, const Type& value)
{

    assert(index < size && index >= 0);
    
    Type returnValue;
    ArrayNode<Type> * current = head;
    for (int spot = 0; spot <= index; spot++)
    {
        if (spot != index)
        {
            current = current->getNext();
        }
        else
        {
            returnValue = current->getValue();
            current->setValue(value);
        }
    }
    
    return returnValue;
    
}

template <class Type>
void CTECList<Type> :: swap(int indexOne, int indexTwo)
{
    assert(indexOne < size && indexTwo < size);
    
    Type temp = getFromIndex(indexOne);
    set(indexOne, getFromIndex(indexTwo));
    set(indexTwo, temp);
}

template <class Type>
void CTECList<Type> :: selectionSort()
{
    for(int outerLoop = 0; outerLoop < this->size - 1; outerLoop++)
    {
        int selectedMinimum = outerLoop;
        
        for(int innerLoop = outerLoop + 1; innerLoop < size; innerLoop++)
        {
            if(getFromIndex(innerLoop) < getFromIndex(selectedMinimum))
            {
                selectedMinimum = innerLoop;
            }
        }
        
        if(selectedMinimum != outerLoop)
        {
            swap(selectedMinimum, outerLoop);
        }
    }
}




