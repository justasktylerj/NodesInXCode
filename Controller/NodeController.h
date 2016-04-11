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
#include "../Model/ArrayNode.h"
#include "../Model/CTECArray.h"
#include "../Model/Timer.h"
#include "../Model/CTECList.h"

using namespace std;

class NodeController
{
private:
    CTECList<int> * numbers;
	Timer arrayTimer;
	void testLists();
    void sortData();
    void searchTest();
    
    void swap(int indexOne, int indexTwo);
    int * mergeData;
    void doMergeSort();
    void mergeSort(int [] dataArray, int size);
    void merge(int data [], int sizeOne, int sizeTwo);
    void quickSort(int data[], int size);
    void partition(int first, in last);
public:
	NodeController();
	virtual ~NodeController();
	void start();
 


};

#endif /* CONTROLLER_NODECONTROLLER_H_ */
