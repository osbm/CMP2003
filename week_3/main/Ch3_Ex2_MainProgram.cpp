/*The function remove of the class arrayListType removes only the first
occurrence of an element. Add the function removeAll to the class
arrayListType that would remove all occurrences of a given element. Also,
write the definition of the function removeAll and a program to test this function.
*/

#include <iostream>

#include "arrayListType.h"

using namespace std;

int main()
{
    arrayListType<int> intList(100);

    int counter;
    int number;

    cout << "Processing the integer list"
        << endl;
    cout << "Enter 10 integers: ";

    for (counter = 0; counter < 10; counter++)
    {
        cin >> number;
        intList.insertAt(counter, number);
    }

    cout << endl;
    cout << "The list you entered is: ";
    intList.print();
    cout << endl;

    cout << "Enter the item (all occurrences) to be deleted: ";
    cin >> number;
    intList.removeAll(number);
    cout << "After removing " << number << ", the list is: "
        << endl;
    intList.print();
    cout << endl;

    cout << "Enter the item to be deleted: ";
    cin >> number;
    intList.remove(number);
    cout << "After removing " << number << ", the list is: "
        << endl;
    intList.print();
    cout << endl;

    return 0;
}
