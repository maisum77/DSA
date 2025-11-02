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
    int count=0;
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
        count++;
    }
    void middle()
    {
        node* temp=head;
        for (int i = 0; i < (count-1)/2; i++)
        {
            temp=temp->next;
        }
        cout<<"middle value:"
            <<temp->data<<endl;   
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
    ll.middle();
    
}