// https://leetcode.com/problems/design-circular-queue/

#include <bits/stdc++.h>
using namespace std;

    class MyCircularQueue {
    private:
        int front, rear, capacity;
        bool reset = false;
        int* data;
    public:
        //MyCircularQueue(k) Initializes the object with the size of the queue to be k.
        MyCircularQueue(int k) {
            front = 0, rear = 0;
            capacity = k;
            data = new int[k];
        }

        //boolean enQueue(int value) Inserts an element into the circular queue.Return true if the operation is successful.
        bool enQueue(int value) {
            if (isFull())
                return false;
            else {
                if ((rear + 1) % capacity == front)
                    reset = true;
                data[rear] = value;
                rear = (rear + 1) % capacity;
                return true;
            }
        }

        //boolean deQueue() Deletes an element from the circular queue.Return true if the operation is successful.
        bool deQueue() {
            if (isEmpty())
                return false;
            front = (front + 1) % capacity;
            if (reset)
                reset = false;
            return true;
        }

        //int Front() Gets the front item from the queue.If the queue is empty, return -1.
        int Front() {
            int res ;
            res = isEmpty() ? -1 : data[front];
            return res;
        }

        //int Rear() Gets the last item from the queue.If the queue is empty, return -1.
        int Rear() {
            int res;
            if (isEmpty())
                res = -1;
            else 
                res = rear == 0 ? data[capacity - 1] : data[rear - 1];
            return res;
        }

        //boolean isEmpty() Checks whether the circular queue is empty or not.
        bool isEmpty() {
            if (!reset && rear == front)
                return true;
            return false;
        }

        //boolean isFull() Checks whether the circular queue is full or not.
        bool isFull() {
            return reset;
        }
    };
