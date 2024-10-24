//PRN : 123B1B253
//Name : Sadhyoj.S.Hanwate 
//Assignment number : 2 a
/*Assignment Title : Consider Employee database of PCCOE (at least 20 records).Database contains different 
                     fields of every employee like EMP-ID, EMP-Name and EMP-Salary*/
                //a. Arrange list of employees according to EMP-ID in ascending order using Quick Sort 

#include <iostream>
#include <string>

using namespace std;

// Employee class to store EMP-ID, EMP-Name, and EMP-Salary
class Employee {
    public :
    int empID;
    string empName;
    float empSalary;
};

// Function to print the employee database
void printEmployees(Employee employees[], int n) {
    cout << "EMP-ID\tEMP-Name\tEMP-Salary\n";
    for (int i = 0; i < n; i++) {
        cout << employees[i].empID << "\t" << employees[i].empName << "\t\t" << employees[i].empSalary << endl;
    }
    cout << endl;
}

// Quick Sort function: partitioning the array based on EMP-ID
int partition(Employee employees[], int low, int high) {
    int pivot = employees[high].empID;  // Pivot is the EMP-ID of the last element
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (employees[j].empID < pivot) {
            i++;
            swap(employees[i], employees[j]);
        }
    }
    swap(employees[i + 1], employees[high]);
    return i + 1;
}

// Quick Sort function to sort employees by EMP-ID
void quickSortByID(Employee employees[], int low, int high) {
    if (low < high) {
        int pi = partition(employees, low, high);
        quickSortByID(employees, low, pi - 1);
        quickSortByID(employees, pi + 1, high);
    }
}


int main() {
    // Employee database (20 records)
    Employee employees[20] = {
        {105, "Ajay", 55000}, {103, "Bijay", 60000}, {102, "Charlie", 50000}, {108, "David", 45000},
        {101, "Eshan", 70000}, {110, "Farhan", 48000}, {115, "Ganraj", 55000}, {109, "Harsh", 52000},
        {107, "Isha", 47000}, {104, "Conrad", 59000}, {106, "Karl", 56000}, {120, "Saurabh", 54000},
        {114, "Mike", 51000}, {111, "Sachet", 53000}, {113, "Pratham", 62000}, {118, "Pranil", 47000},
        {116, "Vivek", 66000}, {119, "Rajesh", 57000}, {117, "Yash", 53000}, {112, "Tanmay", 68000}
    };

    int n = 20;

    cout << "Original List of Employees:\n";
    printEmployees(employees, n);

    // a. Sort employees by EMP-ID using Quick Sort
    quickSortByID(employees, 0, n - 1);
    cout << "Employees Sorted by EMP-ID (Ascending Order):\n";
    printEmployees(employees, n);

    return 0;
}
