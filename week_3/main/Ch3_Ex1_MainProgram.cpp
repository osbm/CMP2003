/*The function removeAt of the class arrayListType removes an element
from the list by shifting the elements of the list. However, if the element to be
removed is at the beginning of the list and the list is fairly large, it could take a
lot of computer time. Because the list elements are in no particular order, you
could simply remove the element by swapping the last element of the list with
the item to be removed and reducing the length of the list. Rewrite the
definition of the function removeAt using this technique.
*/

#include <iostream>

#include "arrayListType.h"

using namespace std;

int main()
{
    arrayListType<char> intList(100);

    int counter;
    char number;
    int position;

    cout << "Enter 5 integers: ";

    for (counter = 0; counter < 5; counter++)
    {
        cin >> number;
        intList.insertAt(counter, number);
    }

    cout << endl;
    cout << "The list you entered is: ";
    intList.print();
    cout << endl;

    cout << "Enter the position of item to be deleted: ";
    cin >> position;
    //intList.removeAt(position);
    intList.removeAtEx1(position);
    cout << "After removing element at " << position
        << ", the list is:" << endl;
    intList.print();

    return 0;
}
