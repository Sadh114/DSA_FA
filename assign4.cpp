/*
NAME-Sadhyoj.S.Hanwate
PRN-123B1B253
Assignment No - 4 : Implement a simple text editor application using a doubly linked list to manage the text buffer. 
Text editor should support the following functionalities: a. Insert text b. Delete text c. Display text d. Search text e. Print text in reverse.

*/
#include <iostream>
#include <string>

using namespace std;

// Node class for the doubly linked list
class Node {
private:
    string content; // Text content

public:
    Node* prev; // Pointer to the previous node
    Node* next; // Pointer to the next node

    // Constructor to initialize the node
    Node() {  prev=nullptr;next=nullptr;}

    // Method to get the content data from user input
    void getData() {
        cout << "Enter text: ";
        getline(cin, content); // Get a single word of content
    }

    // Method to display the content
    void display()  {
        cout << content; // Display the content
    }

    // Method to get the content
    string getContent()  {
        return content; // Return the content
    }
};

// TextEditor class to manage the text buffer
class TextEditor {
private:
    Node* head; // Pointer to the head of the linked list
    Node* tail; // Pointer to the tail of the linked list

    // Function to display the complete text from the linked list with numbering
    void displayText()  {
        Node* current = head;
        int index = 1; // Initialize index for numbering
        while (current != nullptr) {
            cout << "Text " << index << ": "; // Display the text number
            current->display(); // Use the display method of the Node class
            cout << endl; // New line after each text
            current = current->next;
            index++; // Increment index
        }
    }

public:
    // Constructor
    TextEditor() : head(nullptr), tail(nullptr) {}

    // Destructor to free memory
    ~TextEditor() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Function to insert text
    void insertText() {
        Node* newNode = new Node(); // Create a new node
        newNode->getData();         // Get text input from user
        if (head == nullptr) {      // If the list is empty
            head = newNode;
            tail = newNode;         // Both head and tail point to the new node
        } else {
            tail->next = newNode;   // Append to the end of the list
            newNode->prev = tail;   // Link the new node's previous pointer
            tail = newNode;         // Move the tail to the new node
        }
        cout << "Inserted: " << newNode->getContent() << endl; 
    }

    // Function to delete text
    void deleteText(string& content) {
        Node* current = head;
        while (current != nullptr) {
            if (current->getContent() == content) { // If content matches
                if (current->prev) {
                    current->prev->next = current->next; // Bypass current node
                } else {
                    head = current->next; // Move head if deleting the first node
                }
                if (current->next) {
                    current->next->prev = current->prev; // Bypass current node
                } else {
                    tail = current->prev; // Move tail if deleting the last node
                }
                delete current; // Free memory
                cout << "Deleted: " << content << endl; // Confirmation message
                return;
            }
            current = current->next; // Move to the next node
        }
        cout << "Text not found: " << content << endl; // Not found message
    }

    // Function to display all text
    void displayAllText() {
        cout << "Current Text:" << endl;
        displayText(); // Call the helper function
    }

    // Function to search for text
    void searchText(string& content)  {
        Node* current = head;
        while (current != nullptr) {
            if (current->getContent() == content) {
                cout << "Found: " << content << endl; // If found, print found message
                return;
            }
            current = current->next; // Move to the next node
        }
        cout << "Text not found: " << content << endl; // Not found message
    }

    // Function to print text in reverse
    void printReverse()  {
        cout << "Text in Reverse:" << endl;
        Node* current = tail; // Start from the tail
        if (current == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        while (current != nullptr) {
            current->display(); // Print the text
            current = current->prev; // Move to the previous node
            if (current != nullptr) {
                cout << " "; // Space between texts
            }
        }
        cout << endl;
    }
};

int main() {
    TextEditor editor;
    int choice;
    string content;

    do {
        cout << "\nSimple Text Editor" << endl;
        cout << "1. Insert Text" << endl;
        cout << "2. Delete Text" << endl;
        cout << "3. Display All Text" << endl;
        cout << "4. Search Text" << endl;
        cout << "5. Print Text in Reverse" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline character

        switch (choice) {
            case 1:
                editor.insertText(); // Call the insert function
                break;
            case 2:
                cout << "Enter text to delete (single word): ";
                cin >> content; // Get a single word of content to delete
                editor.deleteText(content); // Call the delete function
                break;
            case 3:
                editor.displayAllText(); // Display all text
                break;
            case 4:
                cout << "Enter text to search (single word): ";
                cin >> content; // Get a single word of content to search
                editor.searchText(content); // Call the search function
                break;
            case 5:
                editor.printReverse(); // Print text in reverse
                break;
            case 6:
                cout << "Exiting the program." << endl; // Exit message
                break;
            default:
                cout << "Invalid choice. Please try again." << endl; // Invalid input message
        }
    } while (choice != 6);

    return 0;
}
