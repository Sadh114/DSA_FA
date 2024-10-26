#include <iostream>
#include <string>
#define SIZE 10
using namespace std;

class Employee {
    int EID;
    string name;
    string salary;

public:
    void read() {
        cout << "Enter Employee ID: ";
        cin >> EID;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    int getID() const {
        return EID;
    }

    string getName() const {
        return name;
    }

    string getSalary() const {
        return salary;
    }
};

class Hashtable {
    Employee HT[SIZE];
    int flag[SIZE]; // 0: empty, 1: occupied

public:
    Hashtable() {
        for (int i = 0; i < SIZE; i++) {
            flag[i] = 0;  // Initialize flags to indicate empty slots
        }
    }

    void insert() {
        Employee newR;
        newR.read();
        int empID = newR.getID();
        int pos = empID % SIZE;

        // Insert employee with linear probing for collision resolution
        while (flag[pos] == 1) {
            pos = (pos + 1) % SIZE; // Linear probing
        }

        HT[pos] = newR;
        flag[pos] = 1;  // Mark this slot as occupied
    }

    void display() {
        cout << "\nEmployee Records:\n";
        cout << "| Index | sr.no |  ID  |   Name   |  Salary  | Flag |\n";
        cout << "|-------|-------|------|----------|----------|------|\n";
        for (int i = 0; i < SIZE; i++) {
            cout << "|   " << i << "   |   " << (i + 1) << "   |";
            if (flag[i] == 1) {
                cout << "  " << HT[i].getID() << "  | "
                     << " " << HT[i].getName() << "  | "
                     << "  " << HT[i].getSalary() << "  |  1  |\n";
            } else {
                cout << " Empty |   0   |  0  |  0  |  0  |\n"; // Empty flag
            }
            cout << "|-------|-------|------|----------|----------|------|\n";
        }
    }

    Employee* search(int empID) {
        int pos = empID % SIZE;

        while (flag[pos] != 0) {
            if (flag[pos] == 1 && HT[pos].getID() == empID) {
                return &HT[pos]; // Return pointer to found Employee
            }
            pos = (pos + 1) % SIZE; // Linear probing
        }

        return nullptr; // Not found
    }
};

int main() {
    Hashtable table;
    int choice;

    do {
        cout << "1. Insert Employee\n2. Display Employees\n3. Search Employee by ID\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                table.insert();
                break;
            case 2:
                table.display();
                break;
            case 3: {
                int empID;
                cout << "Enter Employee ID to search: ";
                cin >> empID;
                Employee* emp = table.search(empID);
                if (emp) {
                    cout << "Employee ID: " << emp->getID() << ", Name: " << emp->getName() << ", Salary: " << emp->getSalary() << endl; // Display found employee
                } else {
                    cout << "Employee not found.\n";
                }
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}


