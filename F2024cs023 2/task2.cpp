#include <iostream>
using namespace std;

class Node
{
public:
    int bookID;
    Node *next;

    Node(int id)
    {
        bookID = id;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }
    void addAtEnd(int id)
    {
        Node *newNode = new Node(id);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtPosition(int id, int position)
    {
        Node *newNode = new Node(id);

        if (position == 1)
        {
            newNode->next = head;
            head = newNode;
            cout << " -> Inserted " << id << " at position 1 (head).\n";
            return;
        }

        Node *temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << " -> Error: Position " << position << " is out of bounds.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        cout << " -> Inserted " << id << " at position " << position << ".\n";
    }

    void displayList()
    {
        cout << "List: [ ";
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->bookID << " -> ";
            temp = temp->next;
        }
        cout << "NULL ]\n";
    }
};

int main()
{
    LinkedList libraryList;

    libraryList.addAtEnd(101);
    libraryList.addAtEnd(105);
    libraryList.addAtEnd(110);
    libraryList.addAtEnd(120);

    cout << "Initial Library List:\n";
    libraryList.displayList();
    cout << "------------------------------------------\n";

    cout << "Task: Inserting Book ID 108 at position 3...\n";
    libraryList.insertAtPosition(108, 3);
    libraryList.displayList();
    cout << "------------------------------------------\n";

    cout << "Task: Inserting Book ID 99 at position 1...\n";
    libraryList.insertAtPosition(99, 1);
    libraryList.displayList();
    cout << "------------------------------------------\n";

    cout << "Task: Inserting Book ID 125 at position 7...\n";
    libraryList.insertAtPosition(125, 7);
    libraryList.displayList();
    cout << "------------------------------------------\n";

    return 0;
}