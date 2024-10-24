/*
Name - Sadhyoj.S.Hanwate
PRN.no - 123B1B253
Assignment No - 7 : Implement a browser history management system using a stack data structure to track the user's browsing history.
The system should support the following functionalities: a. Add visited page b. Navigate back c. View current page d. Check if history is empty or not
Assume no upper bound on number of pages visited.

  */
#include <iostream>
#include <string>

using namespace std;

class BrowserHistory {
private:
    string* history;        // Pointer to dynamically allocated array
    int historyCapacity;    // Current capacity of the array
    int currentPageIndex;   // Index of the current page

public:
    // Constructor to initialize the browser history
    BrowserHistory() {
        history = nullptr;           // Initialize history pointer to nullptr
        historyCapacity = 0;         // No initial capacity
        currentPageIndex = 0;        // No pages visited initially
    }

    // Destructor to free allocated memory
    ~BrowserHistory() {
        delete[] history;            // Free the dynamic array
    }

    // Function to add a visited page
    void addVisitedPage(const string& page) {
        // Increment capacity by 1
        string* expandedHistory = new string[historyCapacity + 1];  // Create a new array with increased capacity
        for (int i = 0; i < currentPageIndex; ++i) {
            expandedHistory[i] = history[i];  // Copy old history to new array
        }
        delete[] history;             // Free the old array
        history = expandedHistory;    // Point to the new array

        history[currentPageIndex++] = page;  // Add the page and increment the currentPageIndex
        historyCapacity++;           // Update the capacity
        cout << "Visited: " << page << endl;
    }

    // Function to navigate back to the previous page
    void navigateBack() {
        if (currentPageIndex > 1) {
            cout << "Navigating back from: " << history[currentPageIndex - 1] << endl;
            --currentPageIndex;  // Go back to the previous page
            cout << "Current page is now: " << history[currentPageIndex - 1] << endl;
        } else if (currentPageIndex == 1) {
            cout << "Navigating back from: " << history[currentPageIndex - 1] << endl;
            cout << "No previous page to go back to." << endl;
        } else {
            cout << "No history to go back to." << endl;
        }
    }

    // Function to view the current page
    void viewCurrentPage() {
        if (currentPageIndex > 0) {
            cout << "Current page: " << history[currentPageIndex - 1] << endl;
        } else {
            cout << "No pages visited yet." << endl;
        }
    }

    // Function to check if the history is empty
    bool isHistoryEmpty() {
        return currentPageIndex == 0;  // Returns true if no pages have been visited
    }

    // Function to display all visited pages in reverse order
    void displayAllPages() {
        if (currentPageIndex > 0) {
            cout << "Browser History (most recent first):" << endl;
            for (int i = currentPageIndex - 1; i >= 0; --i) {  // Start from the most recent page
                cout << currentPageIndex - i << ". " << history[i] << endl;  // Print page index and URL
            }
        } else {
            cout << "No pages visited yet." << endl;
        }
    }
};

int main() {
    BrowserHistory browserHistory;
    int choice;
    string page;

    do {
        cout << "\nBrowser History Management System" << endl;
        cout << "1. Add Visited Page" << endl;
        cout << "2. Navigate Back" << endl;
        cout << "3. View Current Page" << endl;
        cout << "4. Check if History is Empty" << endl;
        cout << "5. Display All Pages" << endl; // New option
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter page URL: ";
                cin >> page;
                browserHistory.addVisitedPage(page);
                break;
            case 2:
                browserHistory.navigateBack();
                break;
            case 3:
                browserHistory.viewCurrentPage();
                break;
            case 4:
                if (browserHistory.isHistoryEmpty()) {
                    cout << "History is empty." << endl;
                } else {
                    cout << "History is not empty." << endl;
                }
                break;
            case 5:
                browserHistory.displayAllPages(); // Call to display all pages
                break;
            case 6:
                cout << "Exiting the program" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

