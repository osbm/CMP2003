
//Data:  7 12 18 20 23 27 30 32 38 45 66 68 72 85 -999

#include <iostream>

#include "orderedArrayListType.h"

using namespace std;

void printListInfo(orderedArrayListType<int>& listInfo);

int main()
{
	orderedArrayListType<int> intList;

	int num;
	int loc;

	cout << "Enter positive integers,"
		<< "ending with -999" << endl;
	cin >> num;

	while (num != -999)
	{
		intList.insertOrd(num);
		cin >> num;
	}

	cout << "The list you entered is: " << endl;
	printListInfo(intList);

	cout << "Enter search item: ";
	cin >> num;
	cout << endl;

	loc = intList.recursiveBinarySearch(num);

	if (loc != -1)
		cout << "Item found at position " << loc+1 << endl;
	else
		cout << "Item not in the list" << endl;


	return 0;
}

void printListInfo(orderedArrayListType<int>& listInfo)
{
	cout << "List: ";
	listInfo.print();

	cout << "List Size: " << listInfo.listSize() << endl;
	cout << "Max List Size: " << listInfo.maxListSize() << endl;

}