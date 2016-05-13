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
	
}

NodeController::~NodeController()
{

}

void NodeController :: testList()
{
    CTECList<int> numbers;
    numbers.addToFront(3);
    numbers.addToEnd(8);
    numbers.addToFront(0);
    numbers.addToEnd(2);
    cout << "head should be 0 and is " << numbers.getFront() << endl;
    cout << "end should be 2 and is " << numbers.getEnd() << endl;
    cout << "size should be 4 and is " << numbers.getSize() << endl;
    
    numbers.addAtIndex(1,2);
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
}
void NodeController::searchList()
{
    
}
void NodeController::doMergeSort()
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
    mergeSort(mergeData, 500000000);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
    
    for (int spot =0; spot < 5000; spot++)
    {
        cout << mergeData[spot] << ", " ;
    }
    
    delete [] mergeData;
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
    int copied1 = 0;
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
            temp[copied++] = (data + sizeOne)[copied2++];
        }
    }
    while (copied1 < sizeOne)
    {
        temp[copied++] = data[copied1++];
    }
    while(copied2 < sizeTwo)
    {
        temp[copied++] = (data + sizeOne)[copied2++];
    }
    
    for(index = 0; index < sizeOne + sizeTwo; index++)
    {
        data[index] = temp[index];
    }
    delete [] temp;
}

void NodeController :: quickSort(int first, int last)
{
    int pivotIndex;

    if(first < last)
    {
        pivotIndex = partition(first, last);
        quickSort(first, pivotIndex - 1);
        quickSort(pivotIndex + 1, last);
        
    }
}
void NodeController:: swap(int first, int last)
{
    int temp = mergeData[first];
    mergeData[first] = mergeData[last];
    mergeData[last] = temp;
}

int NodeController :: partition(int first, int last)
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
    
    return smallIndex;
}

void NodeController :: doQuick()
{
    mergeData = new int[1000000000];
    
    for(int spot = 0; spot < 1000000000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    Timer mergeTimer;
    mergeTimer.startTimer();
    quickSort(0, 1000000000-1);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
    
    delete [] mergeData;
}

void NodeController :: tryTree()
{
    CTECBinaryTree<int> testTree;
    testTree.insert(7);
    testTree.insert(18);
    testTree.insert(-5);
    testTree.insert('4');
    
    cout << testTree.contains('7');
    cout << "\nInOrderTraversal " << endl;
    testTree.inOrderTraversal(testTree.getRoot());
    cout << "\nPreOrderTraversal " << endl;
    testTree.preOrderTraversal(testTree.getRoot());
    cout << "\nPostOrderTraversal " << endl;
    testTree.postOrderTraversal(testTree.getRoot());
    cout << "\nTrees " << endl;
}

void NodeController :: tryGraph()
{
    CTECGraph<int> testGraph;
    testGraph.addVertex(7);
    testGraph.addVertex(18);
    
    testGraph.addEdge(0, 1);
    testGraph.addEdge(1, 0);
    testGraph.addEdge(9, 9);
    
}

void NodeController::testHashTable()
{
    CTECHashTable<int> tempTable;
    HashNode<int> tempArray[10];
    for(int spot = 0; spot < 10; spot++)
    {
        int randomValue = rand();
        int randomKey = rand();
        HashNode<int> tempArray
    }
}
 

