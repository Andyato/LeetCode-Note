//########### Design Circular Deque ################//

/*
Design your implementation of the circular double-ended queue (deque).
Your implementation should support following operations:

MyCircularDeque(k): Constructor, set the size of the deque to be k.
insertFront(): Adds an item at the front of Deque. Return true if the operation is successful.
insertLast(): Adds an item at the rear of Deque. Return true if the operation is successful.
deleteFront(): Deletes an item from the front of Deque. Return true if the operation is successful.
deleteLast(): Deletes an item from the rear of Deque. Return true if the operation is successful.
getFront(): Gets the front item from the Deque. If the deque is empty, return -1.
getRear(): Gets the last item from Deque. If the deque is empty, return -1.
isEmpty(): Checks whether Deque is empty or not. 
isFull(): Checks whether Deque is full or not.
*/

#include<vector>
using namespace std;

class MyCircularDeque
{
    private:
        const int capacity;
        int head;
        int tail;
        int size;
        vector<int> data;

    public:
        MyCircularDeque(int k) : capacity(k), data(capacity), head(1), tail(-1), size(0) {}
        bool insertFront(int value);
        bool insertLast(int value);
        bool deleteFront();
        bool deleteLast();
        int getFront();
        int getRear();
        bool isEmpty();
        bool isFull();
};

bool MyCircularDeque::insertFront(int value)
{
    if(isFull()) return false;
    head = (head - 1 + capacity) % capacity;
    if(size == 0) tail = head;
    data[head] = value;
    ++size;
    return true;
}

bool MyCircularDeque::insertLast(int value)
{
    if(isFull()) return false;
    tail = (tail + 1 + capacity) % capacity;
    if(size == 0) head = tail;
    data[tail] = value;
    ++size;
    return true;
}

bool MyCircularDeque::deleteFront()
{
    if(isEmpty()) return false;
    head = (head + 1 + capacity) % capacity;
    --size;
    return true;
}

bool MyCircularDeque::deleteLast()
{
    if(isEmpty()) return false;
    tail = (tail - 1 + capacity) % capacity;
    --size;
    return true;
}

int MyCircularDeque::getFront()
{
    if(isEmpty()) return -1;
    return data[head];
}

int MyCircularDeque::getRear()
{
    if(isEmpty()) return -1;
    return data[tail];
}

bool MyCircularDeque::isEmpty()
{
    return size == 0;
}

bool MyCircularDeque::isFull()
{
    return size == capacity;
}

int main()
{
    int k = 10, value1 = 5, value2 = 6;
    MyCircularDeque obj(k);
    bool param_1 = obj.insertFront(value1);
    bool param_2 = obj.insertLast(value2);
    bool param_3 = obj.deleteFront();
    bool param_4 = obj.deleteLast();
    int param_5 = obj.getFront();
    int param_6 = obj.getRear();
    bool param_7 = obj.isEmpty();
    bool param_8 = obj.isFull();
    return 0;
}