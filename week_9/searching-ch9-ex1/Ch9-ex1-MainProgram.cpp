
#include <iostream>

#include "arrayListType.h"

using namespace std;

void printListInfo(arrayListType<int>& listInfo);

int main()
{
	arrayListType<int> intList;

	int num;
	int loc;

	cout << "Enter numbers ending with -999" << endl;
	cin >> num;

	while (num != -999)
	{
		intList.insert(num);
		cin >> num;
	}

	cout << "The list you entered is: " << endl;
	printListInfo(intList);

	cout << "Enter search item: ";
	cin >> num;
	cout << endl;

	loc = intList.recursiveSeqSearch(num);

	if (loc != -1)
		cout << "Item found at " << loc + 1 << endl;
	else
		cout << "Item not in the list" << endl;

	return 0;
}

void printListInfo(arrayListType<int>& listInfo)
{
	cout << "List: ";
	listInfo.print();
	cout << "List Size: " << listInfo.listSize() << endl;
}