#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node*prev;
    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};

class double_list{
    private:
    node* head;
    node* tail;
    public:
    double_list(){
        head=tail=NULL;
    }
    void add(int val)
    {
        node* temp=new node(val);
        if(head==NULL)
        {
            head=tail=temp;
            head->prev=NULL;
        }
        else{
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
    }
    void print()
    {
        node* temp= head;
        while (temp!=NULL)
        {
            cout<<temp->data<<"<->";
            temp=temp->next;
        }
    }
};

int main()
{
    double_list ll;
    ll.add(1);
    ll.add(2);
    ll.add(3);
    ll.add(4);
    ll.add(5);
    ll.print();

}