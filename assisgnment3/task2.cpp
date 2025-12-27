#include<iostream>
#include<queue>
using namespace std;
struct Node {
    int data;
    int priority;
    Node* next;
};

class PriorityQueue {
    Node* front;
public:
    PriorityQueue() { front = NULL; }

    void enqueue(int val, int p) {
        Node* temp = new Node{val, p, NULL};
        if (!front || p < front->priority) {
            temp->next = front;
            front = temp;
        } else {
            Node* start = front;
            while (start->next && start->next->priority <= p)
                start = start->next;
            temp->next = start->next;
            start->next = temp;
        }
    }

    void dequeue() {
        if (!front) return;
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    
    int peek() { return front->data; }
    void display() {
        if (!front) return;
        Node* temp = front;
        while (temp!=NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }  
        
    }
};
class CircularQueue {
    Node* front;
    Node* rear;
public:
    CircularQueue() { front = rear = NULL; }

    void enqueue(char val) {
        Node* temp = new Node{val,0, NULL};
        if (!front) front = temp;
        else rear->next = temp;
        rear = temp;
        rear->next = front; 
    }

    void dequeue() {
        if (!front) return;
        if (front == rear) {
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

    void display() {
        if (!front) return;
        Node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};
int main()
{
    PriorityQueue pq;
    pq.enqueue(100, 3); // Low priority
    pq.enqueue(500, 1); // High priority
    pq.enqueue(200, 2); // Medium priority
    
    pq.display();
    pq.dequeue();
    pq.display();
    cout << endl;

    // 2. Testing Circular Queue
    
    cout << "Circular Queue " << endl;
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    
    cq.display();
    cq.dequeue();
    cq.display();

    return 0;
}