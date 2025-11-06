#include <iostream>
#include <string>
using namespace std;
class node
{
public:
    int rollno;
    string name;
    node *next;
    node(string name, int rollno)
    {
        this->name = name;
        this->rollno = rollno;
    }
    node()
    {
        name = "";
        rollno = 0;
    }
};
class list
{
private:
    node *head = NULL;
    node *tail = NULL;

public:
    list()
    {
        head = tail = NULL;
    }
    void add(string name, int rollno)
    {
        node *temp = new node(name, rollno);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void display()
    {
        node *temp = new node;
        temp = head;
        cout << "name\t| Rollno" << endl;
        while (temp != NULL)
        {
            cout << temp->name << "\t| " << temp->rollno << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    list ll;
    ll.add("maisum", 123);
    ll.add("Aon", 342);
    ll.add("Umair", 145);

    ll.display();
    return 0;
}