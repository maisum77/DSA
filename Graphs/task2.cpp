#include <iostream>
#include <string>
#include <queue>  // For Waiting Queue
#include <stack>  // For Emergency Stack
#include <vector> // For simple dynamic array behavior

using namespace std;

// Data Structure: Patient
struct Patient {
    int id;
    string name;
    int age;
};

// Data Structure: Linked List Node for Doctors
struct DoctorNode {
    string doctorName;
    DoctorNode* next;
};

// Main System Class
class HospitalSystem {
private:
    // Task 1: Store records using arrays (Fixed size for simplicity)
    Patient allPatients[100];
    int patientCount = 0;

    // Task 3: Queue for waiting, Stack for emergency
    queue<Patient> waitingQueue;
    stack<Patient> emergencyStack;

    // Task 4: Hash Table (Simple array based on ID % 10)
    Patient* hashTable[10]; 

    // Task 4: Linked List Head for Doctors
    DoctorNode* docHead = nullptr;

public:
    HospitalSystem() {
        // Initialize Hash Table to null
        for(int i=0; i<10; i++) hashTable[i] = nullptr;
    }

    // Task 1: Dynamic Addition
    void addPatient() {
        if (patientCount >= 100) {
            cout << "Storage full!\n";
            return;
        }
        Patient p;
        cout << "Enter ID: "; cin >> p.id;
        cin.ignore(); // clear buffer
        cout << "Enter Name: "; getline(cin, p.name);
        cout << "Enter Age: "; cin >> p.age;

        // Store in Array
        allPatients[patientCount] = p;
        
        // Store in Hash Table (Simple Hash Function: ID % 10)
        int hashIndex = p.id % 10;
        hashTable[hashIndex] = &allPatients[patientCount];

        patientCount++;
        
        // Ask for Type to assign to Queue or Stack
        int type;
        cout << "Is this an Emergency? (1 for Yes, 0 for No): ";
        cin >> type;
        if (type == 1) {
            emergencyStack.push(p);
            cout << "Added to Emergency Stack.\n";
        } else {
            waitingQueue.push(p);
            cout << "Added to Waiting Queue.\n";
        }
    }

    // Task 2: Sort patients by Age (Bubble Sort)
    void sortPatientsByAge() {
        for (int i = 0; i < patientCount - 1; i++) {
            for (int j = 0; j < patientCount - i - 1; j++) {
                if (allPatients[j].age > allPatients[j + 1].age) {
                    // Swap
                    Patient temp = allPatients[j];
                    allPatients[j] = allPatients[j + 1];
                    allPatients[j + 1] = temp;
                }
            }
        }
        cout << "Patients sorted by Age:\n";
        for (int i = 0; i < patientCount; i++) {
            cout << allPatients[i].name << " (" << allPatients[i].age << ")\n";
        }
    }

    // Task 4: Search via Hash Table
    void searchPatient() {
        int id;
        cout << "Enter Patient ID to search: ";
        cin >> id;
        int hashIndex = id % 10;
        
        if (hashTable[hashIndex] != nullptr && hashTable[hashIndex]->id == id) {
            cout << "Found: " << hashTable[hashIndex]->name << ", Age: " << hashTable[hashIndex]->age << endl;
        } else {
            cout << "Patient not found.\n";
        }
    }

    // Task 4: Assign Doctor (Linked List)
    void addDoctor() {
        string name;
        cout << "Enter Doctor Name: ";
        cin.ignore();
        getline(cin, name);

        DoctorNode* newNode = new DoctorNode{name, nullptr};
        if (docHead == nullptr) {
            docHead = newNode;
        } else {
            DoctorNode* temp = docHead;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Doctor assigned.\n";
    }
    
    void showDoctors() {
        cout << "Available Doctors: ";
        DoctorNode* temp = docHead;
        while (temp != nullptr) {
            cout << temp->doctorName << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    HospitalSystem hs;
    int choice;
    
    // Menu Driven Design
    do {
        cout << "\n--- HOSPITAL SYSTEM ---\n";
        cout << "1. Add Patient (Array/Stack/Queue/Hash)\n";
        cout << "2. Sort Patients by Age (Array)\n";
        cout << "3. Search Patient by ID (Hash Table)\n";
        cout << "4. Add/Assign Doctor (Linked List)\n";
        cout << "5. Show Doctors\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {
            case 1: hs.addPatient(); break;
            case 2: hs.sortPatientsByAge(); break;
            case 3: hs.searchPatient(); break;
            case 4: hs.addDoctor(); break;
            case 5: hs.showDoctors(); break;
            case 0: cout << "Exiting..."; break;
            default: cout << "Invalid choice.";
        }
    } while (choice != 0);

    return 0;
}