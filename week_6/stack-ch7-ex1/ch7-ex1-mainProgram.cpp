//Program to test the various operations of a stack

#include <iostream>
#include "myStack.h"

using namespace std;



int main()
{
	stackType<int> stack1(50);
	stackType<int> stack2(50);
	stackType<int> stack3(100);
	int x;

	stack1.initializeStack();
	stack1.push(23);
	stack1.push(45);
	stack1.push(38);

	stack2 = stack1;

	
	if (stack1 == stack2)
		cout << "stack1 and stack2 are identical" << endl;
	else
		cout << "stack1 and stack2 are not identical" << endl;

	x = stack2.top();
	stack2.pop();
	stack2.push(32);

	cout << "**** After pop and push operations on stack2 ****"
		<< endl;
	if (stack1 == stack2)
		cout << "stack1 and stack2 are identical" << endl;
	else
		cout << "stack1 and stack2 are not identical" << endl;

	stack2.push(11);

	cout << "**** After another push operation on stack2 ****" << endl;
	if (stack1 == stack2)
		cout << "stack1 and stack2 are identical" << endl;
	else
		cout << "stack1 and stack2 are not identical" << endl;

	return 0;
}


