#include <iostream>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    string diagnosis;
    Patient* prev;
    Patient* next;

    Patient(int pid, string pname, int page, string pdiag) {
        id = pid;
        name = pname;
        age = page;
        diagnosis = pdiag;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Patient* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    // Add patient at beginning
    void addAtBeginning(int id, string name, int age, string diag) {
        Patient* newNode = new Patient(id, name, age, diag);

        if (head == NULL) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Add patient at end
    void addAtEnd(int id, string name, int age, string diag) {
        Patient* newNode = new Patient(id, name, age, diag);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Patient* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Add patient at a specific position (middle)
    void addAtPosition(int id, string name, int age, string diag, int pos) {
        if (pos == 1) {
            addAtBeginning(id, name, age, diag);
            return;
        }

        Patient* newNode = new Patient(id, name, age, diag);
        Patient* temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Position out of range! Adding at end." << endl;
            addAtEnd(id, name, age, diag);
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;
    }

    // Search for a patient by ID
    Patient* searchPatient(int id) {
        Patient* temp = head;
        while (temp != NULL) {
            if (temp->id == id)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

    // Update patient details
    void updatePatient(int id) {
        Patient* p = searchPatient(id);
        if (p == NULL) {
            cout << "Patient not found!" << endl;
            return;
        }

        cout << "Enter new name: ";
        cin >> p->name;
        cout << "Enter new age: ";
        cin >> p->age;
        cout << "Enter new diagnosis: ";
        cin >> p->diagnosis;

        cout << "Patient details updated successfully!" << endl;
    }

    // Display all patients
    void display() {
        Patient* temp = head;
        if (temp == NULL) {
            cout << "No patient records available." << endl;
            return;
        }

        cout << "\n--- Patient Records ---\n";
        while (temp != NULL) {
            cout << "ID: " << temp->id 
                 << ", Name: " << temp->name
                 << ", Age: " << temp->age
                 << ", Diagnosis: " << temp->diagnosis << endl;
            temp = temp->next;
        }
    }
};

int main() {
    DoublyLinkedList hospital;
    int choice;

    while (true) {
        cout << "\n--- Hospital Patient Management ---\n";
        cout << "1. Add Patient at Beginning\n";
        cout << "2. Add Patient at End\n";
        cout << "3. Add Patient at Specific Position\n";
        cout << "4. Search Patient\n";
        cout << "5. Update Patient\n";
        cout << "6. Display All Patients\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 7) break;

        int id, age, pos;
        string name, diag;

        switch (choice) {
        case 1:
            cout << "Enter ID, Name, Age, Diagnosis: ";
            cin >> id >> name >> age >> diag;
            hospital.addAtBeginning(id, name, age, diag);
            break;

        case 2:
            cout << "Enter ID, Name, Age, Diagnosis: ";
            cin >> id >> name >> age >> diag;
            hospital.addAtEnd(id, name, age, diag);
            break;

        case 3:
            cout << "Enter ID, Name, Age, Diagnosis: ";
            cin >> id >> name >> age >> diag;
            cout << "Enter Position: ";
            cin >> pos;
            hospital.addAtPosition(id, name, age, diag, pos);
            break;

        case 4:
            cout << "Enter Patient ID: ";
            cin >> id;
            {
                Patient* p = hospital.searchPatient(id);
                if (p)
                    cout << "Found! Name: " << p->name << ", Age: " << p->age 
                         << ", Diagnosis: " << p->diagnosis << endl;
                else
                    cout << "Patient not found!" << endl;
            }
            break;

        case 5:
            cout << "Enter Patient ID to update: ";
            cin >> id;
            hospital.updatePatient(id);
            break;

        case 6:
            hospital.display();
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
