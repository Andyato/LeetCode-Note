#include<vector>
using namespace std;

class MyCircularDeque
{
private:
    vector<int> data;
    const int capacity;
    int size;
    int head;
    int tail;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) : data(k), capacity(k), size(0), head(-1), tail(1) {}

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value)
    {
        if(isFull()) return false;
        head = (head + 1 + capacity) % capacity;
        data[head] = value;
        if(size == 0) tail = head;
        ++size;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value)
    {
        if(isFull()) return false;
        tail = (tail - 1 + capacity) % capacity;
        data[tail] = value;
        if(size == 0) head = tail;
        ++size;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront()
    {
        if(isEmpty()) return false;
        --size;
        head = (head - 1 + capacity) % capacity;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast()
    {
        if(isEmpty()) return false;
        --size;
        tail = (tail + 1 + capacity) % capacity;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront()
    {
        if(isEmpty()) return -1;
        return data[head];
    }

    /** Get the last item from the deque. */
    int getRear()
    {
        if(isEmpty()) return -1;
        return data[tail];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty()
    {
        return size == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull()
    {
        return size == capacity;
    }
};

int main()
{
    MyCircularDeque circularDeque(3); // set the size to be 3
    circularDeque.insertLast(1);                            // return true
    circularDeque.insertLast(2);                            // return true
    circularDeque.insertFront(3);                           // return true
    circularDeque.insertFront(4);                           // return false, the queue is full
    circularDeque.getRear();                                // return 32
    circularDeque.isFull();                                 // return true
    circularDeque.deleteLast();                             // return true
    circularDeque.insertFront(4);                           // return true
    circularDeque.getFront();                               // return 4
    return 0;
}