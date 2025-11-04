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
private:
    node *head = NULL;
    node *tail = NULL;

public:
    void push_back(int val)
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
    void circular()
    {
        tail->next=head;
    }
    
    void print_ll()
    {
        node *temp = head;
        do
        {
            cout << temp->data << endl;
            temp = temp->next;
        } while (temp != head);
    }
};

int main()
{
    list ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.circular();
    ll.print_ll();
    
}