#include<iostream>
using namespace std;
class nodes{
    public:
    int data;
    nodes* next;
};
void printlist(nodes*n)
{
    while (n!=nullptr)
    {
        cout<<n->data<<endl;
        n=n->next;
    }
    

}
int main()
{
    nodes* head=new nodes;
    nodes* second=new nodes;
    nodes* third=new nodes;

    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=nullptr;
    printlist(head);
}