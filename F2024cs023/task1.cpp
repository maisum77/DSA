#include <iostream>

struct Node {
    int data;       
    Node* next;     
    Node(int val) : data(val), next(nullptr) {}
};


int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}


void push(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}


void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data;
        if (temp->next != nullptr) {
            std::cout << " → ";
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}


void displayFactorials(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << factorial(temp->data);
        if (temp->next != nullptr) {
            std::cout << " → ";
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}


int main() {
    Node* head = nullptr; 
    
    push(head, 1);
    push(head, 4);
    push(head, 2);
    push(head, 3);
    push(head, 5);

    
    std::cout << "Original Linked List:" << std::endl;
    displayList(head);

    std::cout << std::endl; 

    
    std::cout << "Factorials of Each Node:" << std::endl;
    displayFactorials(head);

   

    return 0;
}