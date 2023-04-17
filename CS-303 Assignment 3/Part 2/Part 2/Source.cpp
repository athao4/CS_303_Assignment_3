// A Chao Thao
// CS-303 Assignment 3 Part 2
// April 17, 2023

#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
	Queue myQueue(10);
	myQueue.enqueue(1);
	myQueue.enqueue(2);
	myQueue.enqueue(3);
	myQueue.enqueue(4);
	myQueue.enqueue(5);
	myQueue.enqueue(6);

	// Display front element.   
	cout << "Front element: " << myQueue.peek() << endl;
	// Remove front element.
	cout << "Dequeued element: " << myQueue.dequeue() << endl;
	// Display new front after remove
	cout << "Front element: " << myQueue.peek() << endl;
	// Check if empty (0:No , 1:Yes)
	cout << "Queue is empty: " << myQueue.isEmpty() << endl;
	// Display the size
	cout << "Queue size: " << myQueue.size() << endl;

	return 0;
}