//PRN : 123B1B253
//Name : Sadhyoj.S.Hanwate 
//Assignment number : 2 b
/*Assignment Title : Consider Employee database of PCCOE (at least 20 records).Database contains different 
                     fields of every employee like EMP-ID, EMP-Name and EMP-Salary*/
                //b. Arrange list of Employee alphabetically using Merge Sort.
#include <iostream>
#include <string>

using namespace std;

// Employee class to store EMP-ID, EMP-Name, and EMP-Salary
class Employee {
    public:
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
// Merge Sort function to merge two sorted halves by EMP-Name
void merge(Employee employees[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    Employee leftArr[n1], rightArr[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = employees[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = employees[mid + 1 + i];

    // Merge the temp arrays back into employees
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i].empName <= rightArr[j].empName) {
            employees[k] = leftArr[i];
            i++;
        } else {
            employees[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr, if any
    while (i < n1) {
        employees[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr, if any
    while (j < n2) {
        employees[k] = rightArr[j];
        j++;
        k++;
    }
}

// Merge Sort function to sort employees by EMP-Name
void mergeSortByName(Employee employees[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort the first and second halves
        mergeSortByName(employees, left, mid);
        mergeSortByName(employees, mid + 1, right);

        // Merge the sorted halves
        merge(employees, left, mid, right);
    }
}
int main() {
    int n = 20;
    
        // Employee database (20 records)
     Employee employees[20] = {
        {105, "Ajay", 55000}, {103, "Bijay", 60000}, {102, "Charlie", 50000}, {108, "David", 45000},
        {101, "Eshan", 70000}, {110, "Farhan", 48000}, {115, "Ganraj", 55000}, {109, "Harsh", 52000},
        {107, "Isha", 47000}, {104, "Conrad", 59000}, {106, "Karl", 56000}, {120, "Saurabh", 54000},
        {114, "Mike", 51000}, {111, "Sachet", 53000}, {113, "Pratham", 62000}, {118, "Pranil", 47000},
        {116, "Vivek", 66000}, {119, "Rajesh", 57000}, {117, "Yash", 53000}, {112, "Tanmay", 68000}
    };
// b. Sort employees by EMP-Name alphabetically using Merge Sort
    mergeSortByName(employees, 0, n - 1);
    cout<<"Assignment 2b"<<endl;
    cout << "Employees Sorted by EMP-Name (Alphabetically):\n";
    printEmployees(employees, n);
     return 0;
}
