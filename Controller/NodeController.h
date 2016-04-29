/*
 * NodeController.h
 *
 *  Created on: Jan 27, 2016
 *      Author: tjar2074
 */

#ifndef CONTROLLER_NODECONTROLLER_H_
#define CONTROLLER_NODECONTROLLER_H_

#include <iostream>
#include<string>

#include "../Model/Node.h"

#include "../Model/ArrayNode.cpp"
#include "../Model/CTECBinaryTree.h"
#include "../Model/CTECBinaryTree.cpp"
#include "../Model/ArrayNode.h"
#include "../Model/CTECArray.h"
#include "../Model/Timer.h"
#include "../Model/CTECList.cpp"

using namespace std;

class NodeController
{
private:
    CTECList<int> * numbers;
	Timer arrayTimer;
	void testList();
    void sortData();
    void searchList();
    
    void swap(int first, int second);
    int partition(int first, int last);
    void doQuick();
    void quickSort(int first, int last);

    int * mergeData;
    void doMergeSort();
    void mergeSort(int data[], int size);
    void merge(int data [], int sizeOne, int sizeTwo);
    
    void tryGraph();
    void tryTree();
public:
	NodeController();
	virtual ~NodeController();
	void start();
 


};

#endif /* CONTROLLER_NODECONTROLLER_H_ */
