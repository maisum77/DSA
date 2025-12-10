#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// Function to create a doubly linked list from an array
Node* createList(int arr[], int n) {
    Node* head = new Node(arr[0]);
    Node* temp = head;

    for (int i = 1; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
    return head;
}

// Display list forward
void display(Node* head) {
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Display square of each element
void displaySquares(Node* head) {
    Node* temp = head;
    cout << "Square of each element: ";
    while (temp != NULL) {
        cout << (temp->data * temp->data) << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    int arr[5] = {2, 4, 6, 8, 10};

    // Create doubly linked list
    Node* head = createList(arr, 5);

    // Display the list
    display(head);

    // Display squares of each element
    displaySquares(head);

    return 0;
}
