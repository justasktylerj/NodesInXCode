/*
 * CTECArray.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: tjar2074
 */
#include "CTECArray.h"

#include <assert.h>
using namespace std;
using namespace CTECData;

template <class Type>
CTECArray<Type>::CTECArray(int size)
{
    this->size = size;
    this->head = nullptr;
    
    assert(size > 0);
    
    for (int index = 0; index < size; index++)
    {
        if (head != nullptr)
        {
            ArrayNode<Type> * nextNode = new ArrayNode<Type>();
            nextNode->setNext(head);
            this->head = nextNode;
        }
        else
        {
            ArrayNode<Type> * firstNode = new ArrayNode<Type>();
            this->head = firstNode;
        }
    }
}

template <class Type>
CTECArray<Type>::~CTECArray()
{
    ArrayNode<Type> * deleteMe = head;
    for (int index = 0; index < size; index++)
    {
        if (deleteMe->getNext() != nullptr)
        {
            head = deleteMe->getNext();
            deleteMe->setNext(nullptr);
        }
        
        delete deleteMe;
        deleteMe = head;
        
    }
}

template <class Type>
int CTECArray<Type>::getSize()
{
	return this->size;
}

template <class Type>
Type CTECArray<Type>:: get(int position)
{
    ArrayNode<Type> * current = head;
    for (int spot = 0; spot <= position; spot++)
    {
        if (spot != position)
        {
            current = current->getNext();
        }
        else
        {
            return current->getValue();
        }
    }
    return current->getValue();

}

template <class Type>
void CTECArray<Type>:: set(int position, const Type& value)
{
	assert(position < size && position >= 0);

		ArrayNode<Type> * current = head;
		for (int spot = 0; spot <= position; spot++)
		{
				if (spot != position)
			{
				current = current->getNext();
			}
			else
			{
				current->setValue(value);
			}
		}
}

template <class Type>
int CTECArray<Type> :: indexOf(Type searchValue)
{
    assert(this->size > 0);
    
    ArrayNode<Type> * current = head;
    int indexNotFound = -1;
    
    for(int index = 0; index < this->size; index++)
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

template <class Type>
int CTECArray<Type> :: nextIndexOf(int startingIndex, Type searchValue)
{
    assert(this->size > 0);
    assert(startingIndex >= 0 && startingIndex < this->size);
    
    int indexNotFound = -1;
    
    ArrayNode<Type> * current = head;
    for(int index = 0; index < startingIndex; index++)
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
            current = current->getNext();
        }
    }
    return indexNotFound;
}

template <class Type>
void CTECArray<Type> :: swap(int indexOne, int indexTwo)
{
    assert(indexOne < size && indexTwo < size);
    
    Type temp = get(indexOne);
    set(indexOne, get(indexTwo));
    set(indexTwo, temp);
}

template <class Type>
void CTECArray <Type> :: selectionSort()
{
    for(int outerLoop = 0; outerLoop < size - 1; outerLoop++)
    {
        int selectedMinimum = outerLoop;
        
        for(int innerLoop = outerLoop + 1; innerLoop < size; innerLoop++)
        {
            if(get(innerLoop) < get(selectedMinimum))
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