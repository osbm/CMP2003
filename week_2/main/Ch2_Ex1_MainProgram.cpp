//Program that uses the class extClockType

#include <iostream>
#include "extClockType.h"

using namespace std;

int main()
{
	extClockType time1(5, 10, 34, CST);
	extClockType time2;

	cout << "Time 1: ";
	time1.printTime();
	cout << endl;

	cout << "Time 2: ";
	time2.printTime();
	cout << endl;

	time2.setTime(12, 45, 59, PST);

	cout << "Time 2: ";
	time2.printTime();
	cout << endl;

	time2.incrementSeconds();

	cout << "After incrementing time2 by one second, Time 2: ";
	time2.printTime();
	cout << endl;

	return 0;
}//end main
