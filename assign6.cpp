/*
Name - Sadhyoj.S.Hanwate
PRN - 123B1B253
Assignment No - 6 : Consider two polynomial expressions of any degree. 
Design solution to perform addition of these two polynomials with suitable data structure and display results.

*/

#include <iostream>
using namespace std;

class Polynomial;

class Node {
    int coefficient; // Coefficient of the polynomial term
    int exponent;    // Exponent of the polynomial term
  
public:
    // Constructor to initialize the node and set next to NULL
    Node* next;
    Node() {
        next = NULL;
    }

    // Method to read the coefficient and exponent from the user
    void read(int termNumber) { // Added termNumber parameter
        cout << "TERM " << termNumber << " - Enter coefficient: ";
        cin >> coefficient;
        cout << "Enter exponent: ";
        cin >> exponent;
    }

    // Method to display the term in the form "coefficient x^exponent"
    void display() {
        cout << coefficient << "x^" << exponent;
    }

    // Friend function declaration to add two polynomials
    friend class Polynomial;
    friend void addPolynomial(Polynomial polynomial1, Polynomial polynomial2);
};

// Polynomial class to represent a polynomial using a linked list of Nodes
class Polynomial {
    Node* head;

public:
    // Constructor to initialize an empty polynomial
    Polynomial() {
        head = NULL;
    }

    // Method to add a node to the polynomial, combining like terms
    void addNode(Node* newNode) {
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            Node* prev = NULL;

            // Traverse to find the right place or a term with the same exponent
            while (temp != NULL && temp->exponent > newNode->exponent) {
                prev = temp;
                temp = temp->next;
            }

            // If a term with the same exponent exists, combine the coefficients
            if (temp != NULL && temp->exponent == newNode->exponent) {
                temp->coefficient += newNode->coefficient;
                delete newNode; // Delete the new node since we merged it
            } else {
                // Insert the new node in the correct position
                newNode->next = temp;
                if (prev == NULL) {
                    head = newNode; // Insert at head if prev is NULL
                } else {
                    prev->next = newNode;
                }
            }
        }
    }

    // Method to read a polynomial
    void readPolynomial(int numTerms) {
        for (int i = 1; i <= numTerms; ++i) { // Start from 1 for term numbering
            Node* newNode = new Node();
            newNode->read(i); // Pass the term number to read
            addNode(newNode);
        }
    }

    // Method to display the polynomial
    void displayPolynomial() {
        Node* temp = head;
        bool isFirst = true;
        while (temp != NULL) {
            if (!isFirst && temp->coefficient > 0) {
                cout << " + ";
            }
            temp->display();
            temp = temp->next;
            isFirst = false;
        }
        cout << endl;
    }

    // Friend function to add two polynomials
    friend void addPolynomial(Polynomial polynomial1, Polynomial polynomial2);
};

// Function to add two polynomials
void addPolynomial(Polynomial polynomial1, Polynomial polynomial2) {
    Polynomial result;
    Node* polynomial1Head = polynomial1.head;
    Node* polynomial2Head = polynomial2.head;

    // Traverse both lists and add terms to the result
    while (polynomial1Head != NULL && polynomial2Head != NULL) {
        if (polynomial1Head->exponent == polynomial2Head->exponent) {
            Node* newNode = new Node();
            newNode->coefficient = polynomial1Head->coefficient + polynomial2Head->coefficient;
            newNode->exponent = polynomial1Head->exponent;
            result.addNode(newNode);
            polynomial1Head = polynomial1Head->next;
            polynomial2Head = polynomial2Head->next;
        } else if (polynomial1Head->exponent > polynomial2Head->exponent) {
            Node* newNode = new Node();
            newNode->coefficient = polynomial1Head->coefficient;
            newNode->exponent = polynomial1Head->exponent;
            result.addNode(newNode);
            polynomial1Head = polynomial1Head->next;
        } else {
            Node* newNode = new Node();
            newNode->coefficient = polynomial2Head->coefficient;
            newNode->exponent = polynomial2Head->exponent;
            result.addNode(newNode);
            polynomial2Head = polynomial2Head->next;
        }
    }

    // Add any remaining terms from polynomial1
    while (polynomial1Head != NULL) {
        Node* newNode = new Node();
        newNode->coefficient = polynomial1Head->coefficient;
        newNode->exponent = polynomial1Head->exponent;
        result.addNode(newNode);
        polynomial1Head = polynomial1Head->next;
    }

    // Add any remaining terms from polynomial2
    while (polynomial2Head != NULL) {
        Node* newNode = new Node();
        newNode->coefficient = polynomial2Head->coefficient;
        newNode->exponent = polynomial2Head->exponent;
        result.addNode(newNode);
        polynomial2Head = polynomial2Head->next;
    }

    // Display the result polynomial
    cout << "\nResult of addition: ";
    result.displayPolynomial();
}

int main() {
    Polynomial polynomial1, polynomial2;
    int numTerms;

    // Input for the first polynomial
    cout << "Enter the number of terms for the first polynomial: ";
    cin >> numTerms;
    polynomial1.readPolynomial(numTerms);

    // Input for the second polynomial
    cout << "Enter the number of terms for the second polynomial: ";
    cin >> numTerms;
    polynomial2.readPolynomial(numTerms);

    // Displaying the polynomials
    cout << "\nPolynomial 1: ";
    polynomial1.displayPolynomial();
    cout << "Polynomial 2: ";
    polynomial2.displayPolynomial();

    // Adding the polynomials
    addPolynomial(polynomial1, polynomial2);

    return 0;
}
