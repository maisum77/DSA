#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
    }
};
class linklist
{
    private:
    node* head=NULL;
    node* tail=NULL;
    int count=0;
    public:
    void add(int val)
    {
        node* temp = new node(val);
        if (head==NULL)
        {
            head=tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
        count++;
    }
    void print()
    {
        node* temp=head;
        while (temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<endl;
        
    }
    void insert(int pos, int data)
    {
        node* temp=new node(data);
        node* curr=head;
        if(pos==1)
        {
            temp->next=head;
            head=temp;
        }
        else
        {
            for (int i = 1; i < pos; i++)
            {
                curr=curr->next;
            }

            temp->next=curr->next;
            curr->next=temp;
        }

    }
    void del(int pos)
    {
        node* curr=NULL;
        node* prev=head;
        for (int i = 1; i < pos; i++)
            {
                prev=prev->next;
            }
            curr=prev->next;
            prev->next=curr->next;
            delete curr;
            
    }
};
int main()
{
    linklist ll;
    ll.add(12);
    ll.add(35);
    ll.add(56);
    ll.add(26);
    ll.add(45);

    ll.print();

    ll.insert(3,11);
    ll.print();

    ll.del(2);
    ll.print();
}