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
    int count = 0; 

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
        count++;
    }
    void print_ll()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void incrementEvenValues() {
        node* temp = head;
        while (temp != NULL) {
            if (temp->data % 2 == 0) {
                temp->data++; 
            }
            temp = temp->next;
        }
    }

    list alternate(list l)
    {
        list merge;
        node* temp1 = head;     
        node* temp2 = l.head;   

        while (temp1 != NULL && temp2 != NULL)
        {
            merge.push_back(temp1->data);
            merge.push_back(temp2->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while (temp1 != NULL)
        {
            merge.push_back(temp1->data);
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            merge.push_back(temp2->data);
            temp2 = temp2->next;
        }
        return merge;
    }
};


int main()
{
   
    list l1;
    l1.push_back(1);
    l1.push_back(3);
    l1.push_back(5);
    l1.push_back(7);

    list l2;
    l2.push_back(2);
    l2.push_back(4);
    l2.push_back(6);

    cout << "Original List 1:" << endl;
    l1.print_ll();
    cout << "Original List 2:" << endl;
    l2.print_ll();
    cout << "-----------------------------------" << endl;

    cout << "Incrementing even values in List 1..." << endl;
    l1.incrementEvenValues();
    cout << "List 1 after increment:" << endl;
    l1.print_ll();
    cout << "-----------------------------------" << endl;
    cout << "Incrementing even values in List 2..." << endl;
    l2.incrementEvenValues();
    cout << "List 2 after increment:" << endl;
    l2.print_ll();
    cout << "-----------------------------------" << endl;

  
    list l3 = l1.alternate(l2);
    
    cout << "Merged List" << endl;
    l3.print_ll();
    cout << "-----------------------------------" << endl;


    return 0;
}