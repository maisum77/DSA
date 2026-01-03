#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
class linklist
{
public:
    node *head;
    node *tail;

public:
    linklist()
    {
        head = tail = NULL;
    }
    void push(int val)
    {
        node *temp = new node(val);
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void pop()
    {
        if (head == NULL) 
            return;
            
        node *temp = head;
        
        if (head == tail) 
        {
            head = tail = NULL;
        }
        else 
        {
            head = head->next;
        }
        
        delete temp;
    }
    void print_head()
    {
        cout << head->data;
    }
};

class Queue
{
public:
    linklist ll;
    void push(int val)
    {
        ll.push(val);
    }
    void pop()
    {
        ll.pop();
    }
    void front()
    {
        ll.print_head();
    }
    bool empty()
    {
        return ll.head == NULL;
    }
};
int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    while (!q.empty())
    {
        q.front();
        q.pop();
    }
    return 0;
}
