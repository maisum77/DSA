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
    void reverse()
    {
        node *curr = head;
        node *r_next = NULL;
        node *prev = NULL;

        while (curr != NULL)
        {
            r_next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = r_next;
        }
        head = prev;
    }
    void print_ll()
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
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.print_ll();
    ll.reverse();
    ll.print_ll();
}