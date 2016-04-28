/*
 * CTECArray.h
 *
 *  Created on: Feb 2, 2016
 *      Author: tjar2074
 */

#ifndef MODEL_CTECARRAY_H_
#define MODEL_CTECARRAY_H_

#include "ArrayNode.h"

namespace CTECData
{
    template <class Type>
    class CTECArray
    {
    private:
        int size;
        ArrayNode<Type> * head;
        void swap(int indexOne, int indexTwo);
    public:
        CTECArray(int size);
        virtual ~CTECArray();
        int getSize();
        void set(int position, const Type& value);
        Type get(int position);
        int indexOf(Type searchValue);
        int nextIndexOf(int startingIndex, Type searchValue);
        void selectionSort();
        
    };
}

#endif /* MODEL_CTECARRAY_H_ */
