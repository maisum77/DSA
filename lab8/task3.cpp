#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    int opID;
    string opName;
    Node* next;

    Node(int id, string name) {
        opID = id;
        opName = name;
        next = nullptr;
    }
};

class EditHistoryStack {
private:
    Node* top;

public:
    EditHistoryStack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int id, string name) {
        Node* newNode = new Node(id, name);
        newNode->next = top;
        top = newNode;

        cout << "Recorded: Operation '" << name << "' (ID: " << id << ")" << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Undo failed: No operations to undo!" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        
        cout << "Undo: Reverted operation '" << temp->opName << "'" << endl;
        delete temp;
    }

    void peek() {
        if (isEmpty()) {
            cout << "History is empty." << endl;
            return;
        }
        cout << "\n--- Last Operation (Top) ---" << endl;
        cout << "ID: " << top->opID << " | Name: " << top->opName << endl;
        cout << "----------------------------\n" << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "History is empty." << endl;
            return;
        }

        cout << "\n=== Edit History (Most Recent First) ===" << endl;
        Node* current = top;
        while (current != nullptr) {
            cout << " [ ID: " << current->opID << " | " << current->opName << " ]" << endl;
            cout << "    |" << endl;
            cout << "    v" << endl;
            current = current->next;
        }
        cout << "  NULL" << endl;
        cout << "========================================\n" << endl;
    }
};

int main() {
    EditHistoryStack history;

    history.push(101, "Draw Rectangle");
    history.push(102, "Fill Color: Red");
    history.push(103, "Resize Object");

    history.display();

    history.peek();

    cout << "User pressed Undo..." << endl;
    history.pop();

    history.peek();

    history.push(104, "Add Text: 'Hello'");
    
    history.display();

    return 0;
}