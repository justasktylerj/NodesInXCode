/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: tjar2074
 */
#include "NodeController.h"
#include <iostream>
#include <stdlib.h>

NodeController::NodeController()
{
	myIntArray = new CTECArray<int>(5);
}

NodeController::~NodeController()
{

}

void NodeController :: testLists()
{
    CTECList<int> numbers;
    numbers.addToFront(3);
    numbers.addToEnd(8);
    numbers.addToFront(0);
    numbers.addToEnd(2);
    cout << "head should be 0 and is " << numbers.getFront() << endl;
    cout << "end should be 2 and is " << numbers.getEnd() << endl;
    cout << "size should be 4 and is " << numbers.getSize() << endl;
    
    numbers.AddAtIndex(1,2);
    cout << "index 1 should be 2 and is " << numbers.getFromIndex(1) << endl;
    
    numbers.removeFromFront();
    numbers.removeFromEnd();
    cout << "head should be 2 and is:" << numbers.getFront() << endl;
    cout << "end should be 8 and is:" << numbers.getEnd() << endl;
    
    numbers.removeFromIndex(1);
    cout << "index of value should be 1 and is:" << numbers.indexOf(8) << endl;
    cout << "size should be 2 and is:" << numbers.getSize() << endl;
    
}
void NodeController :: start()
{
    doQuick();

void NodeController::searchTest()
{
    
}
void NodeController::doMergesort()
{
    mergeData = new int[500000000];
    
    for(int spot = 0; spot < 500000000; spot++)
    {
        int myRandom = rand() % 1000;
        mergeData[spot] = myRandom;
    }
    for (int spot =0; spot < 5000; spot++)
    {
        cout << mergeData[spot] << ", " ;
    }
    
    Timer mergeTimer;
    mergeTimer.startTimer();
    mergesort(mergeData, 500000000);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
    
    for (int spot =0; spot < 5000; spot++)
    {
        cout << mergeData[spot] << ", " ;
    }
    
    delete [] mergeData;
}
void NodeController :: tryTree()
{
    
}

void NodeController::mergeSort(int data[], int size )
{
    int sizeOne;
    int sizeTwo;
    
    if(size > 1)
    {
        sizeOne = size/2;
        sizeTwo = size-sizeOne;
        
        mergeSort(data, sizeOne);
        mergeSort((data+sizeOne), sizeTwo);
        
        merge(data, sizeOne, sizeTwo);
    }
}

void NodeController::merge(int data[], int sizeOne, int sizeTwo)
{
    int * temp;
    int copied = 0;
    int copied = 0;
    int copied2 = 0;
    int index;
    
    temp = new int[sizeOne + sizeTwo];
    
    while ((copied1 < sizeOne) && (copied2 < sizeTwo))
    {
        if(data[copied1] < (data + sizeOne)[copied2])
        {
            temp[copied++] = data[copied1++];
        }
        else
        {
            temp[copied++] = (data + sizeOne)[copied2++]
        }
    }
    while (copied1 < sizeOne)
    {
        temp[copied++] = data[copied1++];
    }
    while(copied2 < sizeTwo)
    {
        temp[copied++] = (data + sizeOne + sizeTwo); index++)
    }
    
    for(index = 0; index < sizeOne + sizeTwo; index++)
    {
        data[index] = temp[index];
    }
    delete [] temp;
}

void NodeController::quickSort(int data[], int size)
{
    int pivotIndex;
    int sizeOne;
    int sizeTwo;
    
    if(size > 1)
    {
        partition(data, size, pivotIndex);
        
        sizeOne = pivotIndex;
        sizeTwo = size - sizeOne - 1;
        
        quickSort(data, sizeOne);
        quickSort((data + pivotIndex + 1), sizeTwo);
        
    }
}
void NodeController:: swap(int first, int last)
{
    int temp = mergeData[first];
    mergeDate[first] = mergeDAta[last];
    mergeData[last] = temp
}

void NodeController::partition(int first, int last)
{
    int pivot;
    
    int index, smallIndex;
    swap(first, (first + last)/2);
    
    pivot= mergeData[first];
    smallIndex = first;
    
    for(index = first + 1; index <= last; index++)
    {
        if(mergeData[index] < pivot)
        {
            smallIndex++;
            swap(smallIndex, index);
        }
    }
    swap(first, smallIndex);
    
    return smallInd
}

void NodeController::doQuick()
{
    mergeData = new int[1000000000];
    
    for(int spot = 0; spot < 1000000000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    Timer mergeTimer;
    mergeTimer.startTimer();
    quicksort(0, 1000000000-1);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
    
    delete [] mergeData;
}

void NodeController::tryGraphs()
{
    CTECGraph<int> testerGraph;
    testerGraph.addVertex(7)
    testerGraph.addVertex(18)
    testerGraph.addEdge(0, 1);
    testerGraph.addEdge(1, 0);
    testerGraph.addEdge(9, 9);
    
    testerGraph.breadthFirstTraversal(testerGraph, 0);
    
    
}
 
    
    
    
    
    
    

