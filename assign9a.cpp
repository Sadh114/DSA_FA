/*
Name - Sadhyoj.S.Hanwate
PRN : 123B1B253
Assignment No - 9 :  a] Implement a restaurant waitlist system using the queue data structure. 
Restaurant waitlist provide following facility: a. Add Party to Waitlist b. Seat Party c. Display Waitlist
*/

#include <iostream>
#include <string>

using namespace std;

// Node structure for the queue
class PartyNode {
	public:
	string name;      	// Name of the party
	int size;         	// Size of the party
	PartyNode* next;  	// Pointer to the next party in the queue
};

// Queue class for managing the waitlist
class WaitlistQueue {
public:
	PartyNode* front;   // Front pointer (first party in the queue)
	PartyNode* rear;	// Rear pointer (last party in the queue)


	// Constructor to initialize an empty queue
	WaitlistQueue() {
    	front = nullptr;
    	rear = nullptr;
	}

	// Function to add a party to the waitlist (enqueue)
	void addParty(const string& name, int size) {
    	PartyNode* newNode = new PartyNode();
    	newNode->name = name;
    	newNode->size = size;
    	newNode->next = nullptr;

    	if (rear == nullptr) {
        	// If the queue is empty, both front and rear point to the new node
        	front = rear = newNode;
    	} else {
        	// Insert the new node at the rear
        	rear->next = newNode;
        	rear = newNode;
    	}
    	cout << "Party " << name << " of size " << size << " added to the waitlist.\n";
	}

	// Function to seat a party (dequeue)
	void seatParty() {
    	if (front == nullptr) {
        	cout << "Waitlist is empty. No parties to seat.\n";
        	return;
    	}

    	// Remove the front party from the queue
    	PartyNode* temp = front;
    	cout << "Seating party " << front->name << " of size " << front->size << ".\n";
    	front = front->next;

    	// If the queue becomes empty, rear should also be nullptr
    	if (front == nullptr) {
        	rear = nullptr;
    	}

    	delete temp;
	}

	// Function to display the waitlist
	void displayWaitlist() const {
    	if (front == nullptr) {
        	cout << "Waitlist is empty.\n";
        	return;
    	}

    	cout << "Current Waitlist:\n";
    	PartyNode* temp = front;
    	int position = 1;
    	while (temp != nullptr) {
        	cout << position++ << ". Party " << temp->name << ", Size: " << temp->size << "\n";
        	temp = temp->next;
    	}
	}

	// Destructor to clear the queue and free memory
	~WaitlistQueue() {
    	while (front != nullptr) {
        	PartyNode* temp = front;
        	front = front->next;
        	delete temp;
    	}
	}
};

// Main function to demonstrate the restaurant waitlist system
int main() {
	WaitlistQueue waitlist;
	int choice;
	string name;
	int size;

	do {
    	cout << "\nRestaurant Waitlist System\n";
    	cout << "1. Add Party to Waitlist\n";
    	cout << "2. Seat Party\n";
    	cout << "3. Display Waitlist\n";
    	cout << "4. Exit\n";
    	cout << "Enter your choice: ";
    	cin >> choice;

    	switch (choice) {
        	case 1:
            	cout << "Enter party name: ";
            	cin >> name;
            	cout << "Enter party size: ";
            	cin >> size;
            	waitlist.addParty(name, size);
            	break;

        	case 2:
            	waitlist.seatParty();
            	break;

        	case 3:
            	waitlist.displayWaitlist();
            	break;

        	case 4:
            	cout << "Exiting...\n";
            	break;

        	default:
            	cout << "Invalid choice. Please try again.\n";
    	}
	} while (choice != 4);

	return 0;
}



