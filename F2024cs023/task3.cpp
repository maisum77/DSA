#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;

    Node(string val) : data(val), next(nullptr) {}
};

void append(Node*& head, string val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;

    if (position == 1) {
        head = temp->next;
        delete temp;
        return;
    }

    for (int i = 1; temp != nullptr && i < position - 1; ++i) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position " << position << " is out of bounds." << endl;
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " → ";
        }
        temp = temp->next;
    }
    cout << endl;
}

void traverseAndPrint(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main() {
    Node* head = nullptr;

    append(head, "Event1");
    append(head, "Event2");
    append(head, "Event3");
    append(head, "Event4");

    cout << "After Insertions:" << endl;
    displayList(head);
    cout << "---" << endl;

    deleteAtPosition(head, 2);
    
    cout << "After Deletions:" << endl;
    displayList(head);
    cout << "---" << endl;

    cout << "Traversing Linked List:" << endl;
    traverseAndPrint(head);
    cout << "---" << endl;

    

    return 0;
}