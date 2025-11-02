#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};
class DoubleList
{
private:
    node *head;
    node *tail;

public:
    DoubleList()
    {
        head = tail = NULL;
    }
    void push_front(int val)
    {
        node *temp = new node(val);
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    void push_back(int val)
    {

        node* temp=new node(val);
        if(head==NULL)
        {
            head=tail=temp;
        }
        else
        {
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
    }

    void pop_front()
    {
        node* temp=head;
        head=head->next;
        delete temp;
        
    }
    void pop_back()
    {
        node* temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete temp;
        
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "<=>";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    DoubleList dl;
    dl.push_front(1);
    dl.push_front(2);
    dl.push_front(3);
    dl.display();
    dl.push_back(4);
    dl.push_back(5);
    dl.push_back(6);
    dl.display();
    dl.pop_front();
    dl.pop_back();
    dl.display();
}