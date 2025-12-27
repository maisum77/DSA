#include <iostream>
#include <string>

using namespace std;

class HospitalQueue
{
private:
    static const int MAX = 5;
    string patients[MAX];
    int front, rear, count;

public:
    HospitalQueue()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

   
    void enqueue(string name)
    {
        if (count == MAX)
        {
            cout << "Queue is full! Cannot add more patients.\n";
        }
        else
        {
            rear = (rear + 1) % MAX; 
            patients[rear] = name;
            count++;
            cout << "Patient " << name << " added to the line.\n";
        }
    }

    
    void dequeue()
    {
        if (count == 0)
        {
            cout << "The queue is empty. No patients to serve.\n";
        }
        else
        {
            cout << "Doctor is serving: " << patients[front] << endl;
            front = (front + 1) % MAX;
            count--;
        }
    }

    
    void display()
    {
        if (count == 0)
        {
            cout << "No patients in the waiting room.\n";
            return;
        }
        cout << "Current Waiting Line: ";
        int tempFront = front;
        for (int i = 0; i < count; i++)
        {
            cout << patients[tempFront] << " ";
            tempFront = (tempFront + 1) % MAX;
        }
        cout << endl;
    }
};

int main()
{
    HospitalQueue q;
    int choice;
    string name;

    do
    {
        cout << "\n--- Hospital Management System ---\n";
        cout << "1. Enqueue Patient\n";
        cout << "2. Dequeue Patient (Serve)\n";
        cout << "3. Display Waiting Patients\n";
        cout << "4. Exit and Show Postfix Output\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter patient name: ";
            cin >> name;
            q.enqueue(name);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "\nExiting Program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}