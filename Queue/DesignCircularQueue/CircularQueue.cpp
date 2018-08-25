#include<vector>
using namespace std;

class MyCircularQueue
{
private:
    vector<int> data;
    const int capacity;
    int size;
    int tail;

public:
    /** Initialize your data structure here. Set the capacity of the queue to be k. */
    MyCircularQueue(int k) : data(k), capacity(k), size(0), tail(-1) {}

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value)
    {
        if(isFull()) return false;
        ++size;
        tail = (tail + 1) % capacity;
        data[tail] = value;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue()
    {
        if(isEmpty()) return false;
        --size;
        return true;
    }

    /** Get the front item from the queue. */
    int Front()
    {
        if(isEmpty()) return -1;
        int front =  (tail + capacity - size + 1) % capacity;
        return data[front];
    }

    /** Get the last item from the queue. */
    int Rear()
    {
        if(isEmpty()) return -1;
        return data[tail];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty()
    {
        return size == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull()
    {
        return size == capacity;
    }
};

int main()
{
    MyCircularQueue circularQueue(3); // set the size to be 3
    circularQueue.enQueue(1);                               // return true
    circularQueue.enQueue(2);                               // return true
    circularQueue.enQueue(3);                               // return true
    circularQueue.enQueue(4);                               // return false, the queue is full
    circularQueue.Rear();                                   // return 3
    circularQueue.isFull();                                 // return true
    circularQueue.deQueue();                                // return true
    circularQueue.enQueue(4);                               // return true
    circularQueue.Rear();                                   // return 4

    return 0;
}