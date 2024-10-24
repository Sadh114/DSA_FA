/*
Name-Sadhyoj.S.Hanwate
PRN-123B1B253
Assignment No - 5 : Implement a navigation system for a delivery service using a circular linked list to represent routes. 
The navigation system should support the following functionalities: a. Add route b. Remove route c. Display route.

*/
#include <iostream>
#include <string>

using namespace std;

// Node structure representing each location in the route
class RouteNode {
    public :
    string location;
    RouteNode* next; // Pointer to the next location
};

// NavigationSystem class to manage the routes using a circular linked list
class NavigationSystem {
public:
    RouteNode* head; // Pointer to the start of the circular linked list


    // Constructor to initialize an empty route list
    NavigationSystem() {
        head = nullptr;
    }

    // Function to add a route (location) to the circular linked list
    void addRoute(const string& location) {
        RouteNode* newNode = new RouteNode();
        newNode->location = location;

        if (head == nullptr) {
            // If the route list is empty, the new location is the first one
            head = newNode;
            newNode->next = head; // Circular link
        } else {
            RouteNode* temp = head;
            while (temp->next != head) {
                temp = temp->next; // Traverse to the last node
            }
            temp->next = newNode;
            newNode->next = head; // Connect the new node to the head
        }
        cout << "Route \"" << location << "\" added successfully.\n";
    }

    // Function to remove a route (location) from the circular linked list
    void removeRoute(const string& location) {
        if (head == nullptr) {
            cout << "No routes to remove. The route list is empty.\n";
            return;
        }

        RouteNode* temp = head;
        RouteNode* prev = nullptr;

        // If the head node itself holds the location to be deleted
        if (head->location == location) {
            // If there's only one node in the circular list
            if (head->next == head) {
                delete head;
                head = nullptr;
            } else {
                // Find the last node to update its next pointer
                while (temp->next != head) {
                    temp = temp->next;
                }
                RouteNode* toDelete = head;
                head = head->next;
                temp->next = head; // Update the last node to point to the new head
                delete toDelete;
            }
            cout << "Route \"" << location << "\" removed successfully.\n";
            return;
        }

        // Traverse the list to find the location
        temp = head;
        do {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->location != location);

        // If the location was found
        if (temp->location == location) {
            prev->next = temp->next; // Unlink the node
            delete temp;
            cout << "Route \"" << location << "\" removed successfully.\n";
        } else {
            cout << "Route \"" << location << "\" not found.\n";
        }
    }

    // Function to display all the routes (locations)
    void displayRoutes() {
        if (head == nullptr) {
            cout << "No routes to display. The route list is empty.\n";
            return;
        }

        RouteNode* temp = head;
        cout << "Current delivery route: ";
        do {
            cout << temp->location << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << " (back to start: " << head->location << ")\n";
    }

    // Destructor to free memory
    ~NavigationSystem() {
        if (head == nullptr) {
            return;
        }

        RouteNode* temp = head;
        RouteNode* nextNode;

        do {
            nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != head);

        head = nullptr;
    }
};

// Main function to demonstrate the navigation system functionality
int main() {
    NavigationSystem navSystem;
    int choice;
    string location;

    do {
        cout << "\n----- Navigation System Menu -----\n";
        cout << "1. Add Route\n";
        cout << "2. Remove Route\n";
        cout << "3. Display Routes\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To consume the newline character after entering choice

        switch (choice) {
        case 1:
            cout << "Enter location to add: ";
            getline(cin, location);
            navSystem.addRoute(location);
            break;

        case 2:
            cout << "Enter location to remove: ";
            getline(cin, location);
            navSystem.removeRoute(location);
            break;

        case 3:
            navSystem.displayRoutes();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
