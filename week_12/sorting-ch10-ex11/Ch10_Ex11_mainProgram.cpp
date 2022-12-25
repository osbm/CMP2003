
//Data:  34 77 26 51 39 8 12 67 4 98 123 10 42 -999

#include <iostream>

#include "arrayListType.h"

using namespace std;

void printListInfo(arrayListType<int>& list);

int main()
{
	arrayListType<int> intList;

	int num;

	cout << "Enter numbers ending with -999" << endl;
	cin >> num;

	while (num != -999)
	{
		intList.insert(num);
		cin >> num;
	}

	cout << "The list you entered is: " << endl;
	printListInfo(intList);

	intList.heapSort();

	cout << "The list after sorting: " << endl;
	printListInfo(intList);

	return 0;
}

void printListInfo(arrayListType<int>& list)
{
	cout << "List: ";
	list.print();
}