
//22 34 56 2 89 90 0 -999
//14 56 11 43 55 -999

#include <iostream>
#include "orderedLinkedList.h"

using namespace std;

int main()
{
	orderedLinkedList<int> newList, list1, list2;

	int num;

	cout << "Enter numbers, for list1, ending with -999" << endl;
	cin >> num;

	while (num != -999)
	{
		list1.insert(num);
		cin >> num;
	}

	cout << "list1: ";
	list1.print();
	cout << endl;
	cout << "Length of list1: " << list1.length() << endl;


	cout << "Enter numbers, for list2, ending with -999" << endl;
	cin >> num;

	while (num != -999)
	{
		list2.insert(num);
		cin >> num;
	}

	cout << endl;

	cout << "list2: ";
	list2.print();
	cout << endl;
	cout << "Length of list2: " << list2.length() << endl;

	newList.mergeLists(list1, list2);

	cout << "newList after merging lis1 and list2" << endl;
	newList.print();
	cout << endl;
	cout << "Length of the newList: " << newList.length() << endl;
	cout << "Last item of the newList: " << newList.back() << endl;

	return 0;
}



