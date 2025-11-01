#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int a)
    {
        data = a;
        next = NULL;
    }
};
class list
{
    node *head;
    node *tail;

public:
    list()
    {
        head = tail = NULL;
    }
    void push_front(int val) // function to push the value to the front of the link list
    {
        node *newNode = new node(val); // dynamically make a new object of the node
        if (head == NULL)              // first element is created then initalized head and tail to the first element
        {
            head = tail = newNode; // make the head and tail to same node in the first making
            return;
        }
        else // else if the first node is already created and is not null than the created new node will be equal to head of the created element
        {
            newNode->next = head; // copy the first node address and store in the new one and
            head = newNode;       // move the head to the new node
        }
    }
    void pop_front()
    {
        node *temp = head;
        if (head == NULL)
        {
            cout << "no list exist";
        }
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    void push_back(int val)
    {
        node *newNode = new node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop_back()
    {
        node *temp = head;
        node *temp_tail = tail;
        if (head == NULL)
        {
            cout << "no list exist";
            return;
        }
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void insert(int val,int pos)
    {
        node* temp=head;
        for(int i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        node* newnode=new node(val);
        newnode->next=temp->next;
        temp->next=newnode;
        
    }

    void print_ll() // functionto print the link list
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    list ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.pop_front();

    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.pop_back();

    ll.insert(10,3);

    ll.print_ll();
}