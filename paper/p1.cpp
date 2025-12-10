#include <iostream>
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
class list
{
private:
    node *head;
    node *tail;

public:
    list()
    {
        head = tail = NULL;
    }
    void add(int val)
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
    void print()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }
    void circular()
    {
        tail->next = head;
    }
    void run_circular()
    {
        node *temp = head;
        do
        {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    void join(list l1)
    {
        tail->next = l1.head;
    }
    void add_at_position(int val, int pos) 
    {
        node *temp = new node(val);
        node *curr = NULL;
        node *prev = head;
        for (int i = 0; i < pos - 1; i++)
        {
            prev = prev->next;
        }
        curr=prev->next;
        temp->next = curr;
        prev->next = temp;
    }
    void del(int pos)
    {
        node *temp = NULL;
        node *curr = NULL;
        node *prev = head;
        for (int i = 0; i < pos - 1; i++)
        {
            prev = prev->next;
        }
        curr=prev->next;
        temp = curr->next;
        prev->next = temp;
        curr = NULL;
        delete curr;
    }
    void reverse()
    {
        node* curr=head;
        node* prev=NULL;
        node* r_next=NULL;
        while (curr!=NULL)
        {
            r_next=curr->next;
            curr->next=prev;

            prev=curr;
            curr=r_next;
        }
        head=prev;
        
    }
};

int main()
{
    list ll, l2;
    ll.add(1);
    ll.add(2);
    ll.add(3);
    ll.add(4);
    ll.add(5);
    l2.add(6);
    l2.add(7);
    l2.add(8);
    l2.add(9);
    l2.add(10);
    ll.print();
    ll.circular();
    ll.run_circular();
    ll.join(l2);
    ll.print();
    ll.reverse();
    ll.print();
    ll.add_at_position(45, 7);
    ll.print();
    ll.del(7);
    ll.print();
}