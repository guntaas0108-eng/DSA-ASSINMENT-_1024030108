#include <iostream>
using namespace std;

int q1[100], q2[100];
int front1 = 0, rear1 = -1, size1 = 0;
int front2 = 0, rear2 = -1, size2 = 0;

bool isEmpty1() { return size1 == 0; }
bool isFull1() { return size1 == 100; }

bool isEmpty2() { return size2 == 0; }
bool isFull2() { return size2 == 100; }

void enqueue1(int x)
{
    if (isFull1())
        return;
    rear1 = (rear1 + 1) % 100;
    q1[rear1] = x;
    size1++;
}

void dequeue1()
{
    if (isEmpty1())
        return;
    front1 = (front1 + 1) % 100;
    size1--;
}