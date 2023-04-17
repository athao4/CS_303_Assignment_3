#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
    int* arr; // pointer to the array that stores the queue elements
    int rear; // index of the rear element of the queue
    int front; // index of the front element of the queue
    int capacity; // maximum number of elements the queue can hold
    int count; // current number of elements in the queue

public:
    Queue(int size); // constructor that initializes the queue with a specified size
    ~Queue(); // destructor that frees the memory allocated for the queue
    void enqueue(int element); // adds an element to the rear of the queue
    int dequeue(); // removes and returns the front element of the queue
    int peek(); // returns the front element of the queue without removing it
    bool isEmpty(); // checks if the queue is empty
    int size(); // returns the current number of elements in the queue
};

#endif