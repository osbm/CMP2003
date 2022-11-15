//Test Program Queue as Array

#include <iostream>
#include "QueueAsArray.h"

using namespace std;

void testCopyConstructor(queueType<int> otherQueue);

int main()
{
	queueType<int> queue1, queue2;
	int x, y;

	x = 4;
	y = 5;
	queue1.addQueue(x);
	queue1.addQueue(y);
	x = queue1.front();
	queue1.deleteQueue();
	queue1.addQueue(x + 5);
	queue1.addQueue(16);
	queue1.addQueue(x);
	queue1.addQueue(y - 3);

	testCopyConstructor(queue1);

	queue2 = queue1;

	cout << "queue1: ";

	while (!queue1.isEmptyQueue())
	{
		cout << queue1.front() << " ";
		queue1.deleteQueue();
	}

	cout << endl;

	cout << "queue2: ";

	while (!queue2.isEmptyQueue())
	{
		cout << queue2.front() << " ";
		queue2.deleteQueue();
	}

	cout << endl;

	return 0;
}

void testCopyConstructor(queueType<int> otherQueue)
{
	if (!otherQueue.isEmptyQueue())
	{
		cout << "Other Queue is not empty" << endl;
		cout << "Front element of Other Queue : "
			<< otherQueue.front() << endl;
		otherQueue.deleteQueue();
		cout << "Front element of Other Queue after deletion : "
			<< otherQueue.front() << endl;
	}
}