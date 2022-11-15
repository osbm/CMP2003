//Test Program linked queue

#include <iostream>
#include "linkedQueue.h"

using namespace std;

void testCopyConstructor(linkedQueueType<int> otherQueue);

int main()
{
    linkedQueueType<int> queue1, queue2;
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

void testCopyConstructor(linkedQueueType<int> otherQueue)
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


