/*Add the function min to the class arrayListType to return the smallest
element of the list. Also, write the definition of the function min and a
program to test this function.
*/

#include <iostream>

#include "arrayListType.h"

using namespace std;

int main()
{
    arrayListType<int> intList(100);

    int counter;
    int number;

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

    cout << "The smallest element in the list is: " << intList.min()
        << endl;

    return 0;
}
