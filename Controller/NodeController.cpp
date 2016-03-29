/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: tjar2074
 */
#include "NodeController.h"

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
	testLists();

	arrayTimer.startTimer();

	for(int index = 0; index < myIntArray->getSize(); index++)
	{
		myIntArray->set(index, (2* index));
	}

	for(int index = 0; index < myIntArray->getSize(); index++)
	{
		cout << "not hipster ints at index " << index << " contains " << myIntArray->get(index) << endl;
	}

	arrayTimer.stopTimer();
	arrayTimer.displayTimerInformation();
}

void NodeController::checkSorts()
{
    CTECArray<int> sortNumberArray(5);
    CTECList<int> sortNumberList;
    for(int spot = 0; spot < 5000; spot++)
    {
        int randomValue = rand();
        numbersInArray.set(spot, randomValue);
        numbersInList.addToEnd(randomValue);
    }
    
    Timer sortTimer;
    sortTimer.startTimer();
    numbersInList.selectionSort();
    sortTimer.stopTimer();
    sortTimer.displayTimerInformation()
    
    sortTimer.resetTimer();
    
}

