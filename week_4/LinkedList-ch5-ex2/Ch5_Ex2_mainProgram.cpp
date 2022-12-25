//Programming Exercise 2: Test Program

#include <iostream>
#include "unorderedLinkedList.h"

using namespace std;

int main()
{
	unorderedLinkedList<int> list;
	int num;

	cout << "Enter numbers ending with -999" << endl;
	cin >> num;

	while (num != -999)
	{
		list.insertLast(num);
		cin >> num;
	}

	cout << endl;

	cout << "List: ";
	list.print();
	cout << endl;
	cout << "Length of the list: " << list.length() << endl;

	cout << "Enter all occurrences the number to be deleted: ";
	cin >> num;
	cout << endl;

	list.deleteAll(num);

	cout << "List after deleting all occurences of " << num << endl;

	list.print();
	cout << endl;
	cout << "Length of the list: " << list.length() << endl;

	list.deleteSmallest();
	cout << "List after deleting the smallest element" << endl;

	list.print();
	cout << endl;
	cout << "Length of the list: " << list.length() << endl;

	return 0;
}



