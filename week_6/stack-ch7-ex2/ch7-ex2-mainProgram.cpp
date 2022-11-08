//Test Program 

#include <iostream>
#include "linkedStack.h"

using namespace std;

int main()
{
	linkedStackType<int> stack1;
	linkedStackType<int> stack2;
	linkedStackType<int> stack3;
	int x;

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

	cout << "**** After pop and push operation on stack2 ****" << endl;
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

