#include <iostream>
#include <string>
using namespace std;
class node
{
public:
    int id;
    bool gpu;
    double price;
    int ram;
    node *next;
    node(int id, bool gpu, double price, int ram)
    {
        this->id = id;
        this->gpu = gpu;
        this->price = price;
        this->ram = ram;
    }
};
class list
{
private:
    node *head = NULL;
    node *tail = NULL;

public:
    void add(int id, bool gpu, double price, int ram)
    {
        node *temp = new node(id, gpu, price, ram);
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void displaySpecific(node *temp)
    {
        cout << "ID: " << temp->id << endl
             << "Gpu: " << temp->gpu << endl
             << "Price: " << temp->price << endl
             << "RAM: " << temp->ram << endl;
    }
    void WithGpu()
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->gpu == true)
            {
                displaySpecific(temp);
            }
            temp = temp->next;
        }
    }
    void Average()
    {
        node *temp = head;
        double average;
        int count = 0;
        while (temp != NULL)
        {
            average = temp->price + average;
            temp = temp->next;
        }
        cout << "Average price: " << average / count << endl;
    }
    void LeastRam()
    {
        node *temp = head;
        node *temp1 = temp;
        while (temp != NULL)
        {
            if (temp->ram > temp1->ram)
            {
                temp1 = temp;
            }

            temp = temp->next;
        }
        displaySpecific(temp1);
    }
    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {

            cout << "ID: " << temp->id << endl
                 << "Gpu: " << temp->gpu << endl
                 << "Price: " << temp->price << endl
                 << "RAM: " << temp->ram << endl;
            temp=temp->next;
        }

    }
    void addAtPosition(int pos,int id, bool gpu, double price, int ram)
    {
        node* adding=new node(id,gpu,price,ram);
        node* temp=head;
        for (int i = 0; i < pos-1 ; i++)
        {
            temp=temp->next;
        }
        temp->next=adding->next;
        temp->next=adding;        
    }
    void deleting(int id)
    {
        // node* prev=head;
        // for (int i = 0; i < pos-1; i++)
        // {
        //     prev=prev->next;
        // }
        // node* curr=prev->next;

        // prev->next=curr->next;
        // delete curr;
        node* curr=head;
        // for (int i = 0; i <= pos; i++)
        // {
        //     curr=curr->next;
        // }
        while (curr!=NULL)
        {
            if(curr->id==id)
            {
                break ;
            }
            curr=curr->next;
        }
        
        node* prev=head;
        while (prev!=NULL)
        {
            if(prev->next==curr)
            {
                return ;
            }
            prev=prev->next;
        }
        prev->next=curr->next;
        delete curr;
    }


};
int main() {
    list ll;
    ll.add(1,true,123,245);
    ll.add(2,false,12,25);
    ll.add(3,true,13,24);
    ll.add(4,false,23,45);
    int choice;

    do {
        cout << "\n===== LAB COMPUTER MANAGEMENT SYSTEM =====";
        cout << "\n1. Insert New Computer at Specific Position";
        cout << "\n2. Delete Computer by System ID";
        cout << "\n3. Display Systems with GPU";
        cout << "\n4. Display Average Price of All Systems";
        cout << "\n5. Display System with Least RAM";
        cout << "\n6. Display All Systems";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int pos, id, ram;
                bool gpu;
                double price;
                cout << "Enter position to insert: ";
                cin >> pos;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter GPU (0 or 1): ";
                cin >> gpu;
                cout << "Enter price: ";
                cin >> price;
                cout << "Enter RAM: ";
                cin >> ram;
                ll.addAtPosition(pos, id, gpu, price, ram);
                break;
            }
            case 2: {
                int id;
                cout << "Enter System ID to delete: ";
                cin >> id;
                ll.deleting(id);
                break;
            }
            case 3:
                ll.WithGpu();
                break;
            case 4:
                ll.Average();
                break;
            case 5:
                ll.LeastRam();
                break;
            case 6:
                ll.display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}

