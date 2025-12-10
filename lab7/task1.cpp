#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to create a linked list from an array
Node* createList(int arr[], int n) {
    Node* head = new Node(arr[0]);
    Node* temp = head;

    for (int i = 1; i < n; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Function to display a linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to display sum of corresponding nodes
void displaySum(Node* head1, Node* head2) {
    cout << "Sum of corresponding nodes: ";

    Node* p = head1;
    Node* q = head2;

    while (p != NULL && q != NULL) {
        cout << p->data + q->data << " ";
        p = p->next;
        q = q->next;
    }
    cout << endl;
}

int main() {

    int arr1[5] = {1, 3, 5, 7, 9};
    int arr2[5] = {2, 4, 6, 8, 10};

    // Create two linked lists
    Node* head1 = createList(arr1, 5);
    Node* head2 = createList(arr2, 5);

    // Display lists
    cout << "List 1: ";
    display(head1);

    cout << "List 2: ";
    display(head2);

    // Display sum of corresponding nodes
    displaySum(head1, head2);

    return 0;
}
