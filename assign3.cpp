#include <iostream>
#include <string>

using namespace std;

// Node structure representing each song in the playlist
struct SongNode {
    string title;
    string artist;
    float duration; // in minutes
    SongNode* next; // Pointer to the next song in the playlist
};

// Playlist class to manage the songs using a singly linked list
class Playlist {
private:
    SongNode* head; // Head pointer for the linked list

public:
    Playlist() {
        head = nullptr; // Initialize the head as null (empty playlist)
    }

    // Function to add a song to the playlist
    void addSong(const string& title, const string& artist, float duration) {
        SongNode* newSong = new SongNode();
        newSong->title = title;
        newSong->artist = artist;
        newSong->duration = duration;
        newSong->next = nullptr;

        if (head == nullptr) {
            head = newSong; // If the playlist is empty, new song becomes the first song
        } else {
            SongNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next; // Traverse to the end of the list
            }
            temp->next = newSong; // Add the new song at the end of the list
        }
        cout << "Song \"" << title << "\" added to the playlist.\n";
    }

    // Function to remove a song from the playlist by its title
    void removeSong(const string& title) {
        if (head == nullptr) {
            cout << "The playlist is empty, no song to remove.\n";
            return;
        }

        SongNode* temp = head;
        SongNode* prev = nullptr;

        // If the song to be deleted is the head
        if (temp != nullptr && temp->title == title) {
            head = temp->next; // Change head
            delete temp; // Free memory
            cout << "Song \"" << title << "\" removed from the playlist.\n";
            return;
        }

        // Search for the song to be deleted, keep track of the previous node
        while (temp != nullptr && temp->title != title) {
            prev = temp;
            temp = temp->next;
        }

        // If song was not found in the list
        if (temp == nullptr) {
            cout << "Song \"" << title << "\" not found in the playlist.\n";
            return;
        }

        // Unlink the node and free memory
        prev->next = temp->next;
        delete temp;
        cout << "Song \"" << title << "\" removed from the playlist.\n";
    }

    // Function to display the entire playlist
    void displayPlaylist() {
        if (head == nullptr) {
            cout << "The playlist is empty.\n";
            return;
        }

        SongNode* temp = head;
        cout << "\nPlaylist:\n";
        while (temp != nullptr) {
            cout << "Title: " << temp->title << ", Artist: " << temp->artist << ", Duration: " << temp->duration << " mins\n";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to play a specific song by its title
    void playSong(const string& title) {
        if (head == nullptr) {
            cout << "The playlist is empty, no song to play.\n";
            return;
        }

        SongNode* temp = head;
        while (temp != nullptr) {
            if (temp->title == title) {
                cout << "Now playing: \"" << temp->title << "\" by " << temp->artist << " (" << temp->duration << " mins)\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Song \"" << title << "\" not found in the playlist.\n";
    }

    // Destructor to clean up the memory allocated for the linked list
    ~Playlist() {
        SongNode* temp = head;
        while (temp != nullptr) {
            SongNode* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

// Main function to demonstrate the playlist functionality
int main() {
    Playlist myPlaylist;
    int choice;
    string title, artist;
    float duration;

    do {
        cout << "\n----- Playlist Menu -----\n";
        cout << "1. Add Song\n";
        cout << "2. Remove Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Play Specific Song\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To consume the newline after entering choice

        switch (choice) {
        case 1:
            cout << "Enter song title: ";
            getline(cin, title);
            cout << "Enter artist name: ";
            getline(cin, artist);
            cout << "Enter song duration (in minutes): ";
            cin >> duration;
            myPlaylist.addSong(title, artist, duration);
            break;

        case 2:
            cout << "Enter the title of the song to remove: ";
            getline(cin, title);
            myPlaylist.removeSong(title);
            break;

        case 3:
            myPlaylist.displayPlaylist();
            break;

        case 4:
            cout << "Enter the title of the song to play: ";
            getline(cin, title);
            myPlaylist.playSong(title);
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
