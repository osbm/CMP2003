#include <iostream>
#include <cstdlib>
#include <ctime>
#include "arrayListType.h"

using namespace std;

int size = 10000;

void fill(arrayListType<int>& list);

int main()
{
	arrayListType<int> list(10000);
	arrayListType<int> temp(10000);

	clock_t startTime1, endTime1;
	clock_t startTime2, endTime2;
	clock_t startTime3, endTime3;
	clock_t startTime4, endTime4;

	fill(list);

	temp = list;

	//Quick sort: The pivot is the middle element
	startTime1 = clock();
	list.quickSort();
	endTime1 = clock();

	//Quick sort: The pivot is the median element
	list = temp;
	startTime2 = clock();
	list.quickSortMedianPivot();
	endTime2 = clock();

	//Quick sort with insertion sort 
	//The pivot is the middle element
	list = temp;
	startTime3 = clock();
	list.quickSortWithInsertionSort();
	endTime3 = clock();

	//Quick sort with insertion sort 
	//The pivot is the median element
	list = temp;
	startTime4 = clock();
	list.quickSortMedianWithInsertionSort();
	endTime4 = clock();

	cout << "Quick sort time, with pivot middle element: "
		<< endTime1 - startTime1 << endl;
	cout << "Quick sort time, with pivot median element: "
		<< endTime2 - startTime2 << endl;
	cout << "Quick sort and insertion sort time, with pivot "
		<< "middle element: " << endTime3 - startTime3 << endl;
	cout << "Quick sort and insertion sort time, with pivot "
		<< "median element: " << endTime4 - startTime4 << endl;

	return 0;
}

void fill(arrayListType<int>& list)
{
	int i = 0;

	while (i < list.maxListSize())
	{
		list.insertEnd((rand() + time(0)) % 100000);
		i++;
	}
}
