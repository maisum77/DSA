#include <iostream>
using namespace std;

struct Node {
    int data;       
    Node* next;     

    Node(int val) : data(val), next(nullptr) {}
};


void push(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}


void displayList(Node* head) {
    if (head == nullptr) {
        cout << "[Empty List]" << std::endl;
        return;
    }
    
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " → ";
        }
        temp = temp->next;
    }
    cout << std::endl;
}


void deleteFromBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is already empty." << std::endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}


void deleteFromEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is already empty." << std::endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* secondLast = head;
    while (secondLast->next->next != nullptr) {
        secondLast = secondLast->next;
    }

    delete secondLast->next;    
    secondLast->next = nullptr; 
}


void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty." << std::endl;
        return;
    }

    if (position == 1) {
        deleteFromBeginning(head); 
        return;
    }

    
    Node* prev = head;
    for (int count = 1; prev != nullptr && count < position - 1; ++count) {
        prev = prev->next;
    }

    
    if (prev == nullptr || prev->next == nullptr) {
        cout << "Position " << position << " is out of bounds." << std::endl;
        return;
    }

   
    Node* nodeToDelete = prev->next;
    prev->next = nodeToDelete->next; 
    delete nodeToDelete;             
}

int main() {
    Node* head = nullptr; 

   
    push(head, 50);
    push(head, 40);
    push(head, 30);
    push(head, 20);
    push(head, 10);

    cout << "Initial List:" << std::endl;
    displayList(head);
    cout << "---" << std::endl;

    cout << "After deleting from beginning:" << std::endl;
    deleteFromBeginning(head);
    displayList(head);
    cout << "---" << std::endl;

    cout << "After deleting from end:" << std::endl;
    deleteFromEnd(head);
    displayList(head);
    cout << "---" << std::endl;

    cout << "After deleting from position 2:" << std::endl;
    deleteAtPosition(head, 2); // Deletes '30'
    displayList(head);
    cout << "---" << std::endl;

    

    return 0;
}