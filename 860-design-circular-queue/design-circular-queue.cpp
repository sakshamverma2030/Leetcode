#include <vector>

class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int count;
    int capacity;

public:
    MyCircularQueue(int k) : data(k), head(0), count(0), capacity(k) {}

    bool enQueue(int value) 
    {
        if (isFull()) return false;
        int tail = (head + count) % capacity;
        data[tail] = value;
        count++;
        return true;
    }

    bool deQueue() 
    {
        if (isEmpty()) return false;
        head = (head + 1) % capacity;
        count--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return data[head];
    }

    int Rear() {
        if (isEmpty()) return -1;
        int tail = (head + count - 1) % capacity;
        return data[tail];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */