/*
Name - Sadhyoj.S.Hanwate
PRN - 123B1B253
Assignment No - 9 : b] Implement a checkout system for a supermarket to efficiently manage customer queues during peak hours. 
The system should support the following operations using a circular queue data structure: a. Customer arrival b. Customer checkout c. Close Checkout Counter d. View customer.
*/

#include <iostream>
#include <string>
using namespace std;

class CircularQueue {
private:
	string* queue;
	int front, rear, capacity;

public:
	CircularQueue(int size) {
    	capacity = size;
    	queue = new string[capacity];
    	front = rear = -1;
	}

	~CircularQueue() {
    	delete[] queue;
	}

	bool isFull() {
    	return (rear + 1) % capacity == front;
	}

	bool isEmpty() {
    	return front == -1;
	}

	void enqueue(const string& customer) {
    	if (isFull()) {
        	cout << "Queue is full. Cannot add customer: " << customer << "\n";
        	return;
    	}
    	if (isEmpty()) {
        	front = 0;
    	}
    	rear = (rear + 1) % capacity;
    	queue[rear] = customer;
    	cout << "Customer " << customer << " has arrived.\n";
	}

	void dequeue() {
    	if (isEmpty()) {
        	cout << "Queue is empty. No customer to checkout.\n";
        	return;
    	}
    	cout << "Customer " << queue[front] << " has checked out.\n";
    	if (front == rear) { // Queue has only one element
        	front = rear = -1; // Reset queue
    	} else {
        	front = (front + 1) % capacity;
    	}
	}

	void closeCounter() {
    	if (isEmpty()) {
        	cout << "No customers in the queue to close the counter.\n";
        	return;
    	}
    	cout << "Closing checkout counter. Customers remaining:\n";
    	while (!isEmpty()) {
        	cout << queue[front] << " ";
        	dequeue();
    	}
    	cout << "\n";
	}

	void viewCustomer() {
    	if (isEmpty()) {
        	cout << "No customers in the queue.\n";
        	return;
    	}
    	cout << "Current customer at front: " << queue[front] << "\n";
	}
};

int main() {
	CircularQueue checkoutQueue(5); // Size of the queue can be adjusted

	int choice;
	string customerName;

	do {
    	cout << "\nSupermarket Checkout System\n";
    	cout << "1. Customer Arrival\n";
    	cout << "2. Customer Checkout\n";
    	cout << "3. Close Checkout Counter\n";
    	cout << "4. View Customer\n";
    	cout << "5. Exit\n";
    	cout << "Enter your choice: ";
    	cin >> choice;

    	switch (choice) {
        	case 1:
            	cout << "Enter customer name: ";
            	cin >> customerName;
            	checkoutQueue.enqueue(customerName);
            	break;
        	case 2:
            	checkoutQueue.dequeue();
            	break;
        	case 3:
            	checkoutQueue.closeCounter();
            	break;
        	case 4:
            	checkoutQueue.viewCustomer();
            	break;
        	case 5:
            	cout << "Exiting the system.\n";
            	break;
        	default:
            	cout << "Invalid choice. Please try again.\n";
    	}
	} while (choice != 5);

	return 0;
}
