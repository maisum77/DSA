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
public:
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
    list alternate(list l)
    {
        list merge;
        node* temp1=head;
        node* temp2=l.head;
        while (temp1 != NULL && temp2 != NULL)
        {
            merge.push_back(temp1->data);
            merge.push_back(temp2->data);

            temp1=temp1->next;
            temp2=temp2->next;
            
        }
        while (temp1!=NULL)
        {
            merge.push_back(temp1->data);
            temp1=temp1->next;
        }
        while (temp2!=NULL)
        {
            merge.push_back(temp2->data);
            temp2=temp2->next;
        }
        return merge;
        
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
    list l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    cout<<"First list"<<endl;
    l1.print_ll();
    cout<<"second list"<<endl;
    list l2;
    l2.push_back(4);
    l2.push_back(5);
    l2.push_back(6);
    l2.print_ll();
    cout<<"Merged list"<<endl;
    list l3= l2.alternate(l1);
    l3.print_ll();

    
    
}