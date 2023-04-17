#include "Queue.h"
#include <iostream>
using namespace std;

/*
  Constructor for the Queue class. It initializes the data
  members of the Queue class. It dynamically allocates memory for
  the array that will store the elements of the queue.
*/
Queue::Queue(int size) {
    arr = new int[size]; // Allocate memory for the array that stores the queue elements.
    capacity = size;
    rear = -1;
    front = 0;
    count = 0;
}

Queue::~Queue() {
    delete[] arr; // Free the memory allocated for the array.
}

/*
  Adds an element to the back of the queue. It first checks if
  the queue is already full, and if so, prints a message to the
  console. If the queue is not full, it increments the rear
  pointer, adds the new element to the array at the rear index,
  and increments the count.
*/
void Queue::enqueue(int element) {
    if (rear == capacity - 1) {
        cout << "Queue is full\n";
    }
    else {
        rear++;
        arr[rear] = element;
        count++;
    }
}

/*
  Removes and returns the element at the front of the queue. It
  first checks if the queue is empty, and if so, prints a message
  to the console and returns -1. If the queue is not empty, it
  returns the element at the front of the array, increments the
  front pointer, and decrements the count.
*/
int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return -1;
    }
    else {
        int dequeuedElement = arr[front];
        front++;
        count--;
        return dequeuedElement;
    }
}

// Returns the element at the front of the queue without removing it.
int Queue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return -1;
    }
    else {
        return arr[front];
    }
}

// Returns a boolean value indicating whether the queue is empty or not.
bool Queue::isEmpty() {
    return (count == 0);
}

// Returns the number of elements currently in the queue.
int Queue::size() {
    return count;
}