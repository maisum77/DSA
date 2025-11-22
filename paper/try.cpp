#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class List
{
public:
    Node *head, *tail;
    int count = 0;
    List()
    {
        head = tail = NULL;
    }
    void create(int v)
    {
        Node *newnode = new Node;
        newnode->data = v;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        count++;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL";
    }
    void deletenode(int pos)
    {
        int t = 0;
        Node *temp = head;
        Node *prev;
        if (pos == 1)
        {
            head = temp->next;
            delete temp;
        }
        else if (pos == count)
        {
            delete tail;
        }
        else
        {
            while (t != pos)
            {
                prev = temp;
                temp = temp->next;
                t++;
            }
            prev->next = temp->next;
            temp->next = NULL;
            delete temp;
        }
    }
};
int main()
{
    List l;
    l.create(2);
    l.create(4);
    l.create(6);
    l.create(8);
    l.create(10);
    l.display();
    cout << endl;
    l.deletenode(4);
    l.display();
}