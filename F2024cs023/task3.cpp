#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string userName;
    int userID;
    Node* next;

    Node(string name, int id) {
        userName = name;
        userID = id;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() {
        Node* current = head;
        Node* nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        cout << "\n--- All memory freed. ---\n";
    }

    void registerUser(string name, int id) {
        Node* newNode = new Node(name, id);
        cout << "\n-> Registering " << name << " (ID: " << id << ")..." << endl;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void displayList() {
        cout << "   Current List: [ ";
        
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->userName;
            cout << " -> ";
            temp = temp->next;
        }
        
        cout << "NULL ]\n";
    }
};

int main() {
    LinkedList userList;
    string name;
    int id = 1001; 

    cout << "--- Dynamic List Growth Visualization ---\n";
    cout << "** Enter 'exit' as the name to stop. **\n\n";

    cout << "Initial State:" << endl;
    userList.displayList();
    cout << "------------------------------------------" << endl;

    while (true) {
        cout << "Enter new user name: ";
        getline(cin, name); 

        if (name == "exit") {
            break;
        }

        userList.registerUser(name, id);
        id++; 

        userList.displayList();
        cout << "------------------------------------------" << endl;
    }

    cout << "\n Registration complete. Final user list:\n";
    userList.displayList();

    return 0;
}