#include <iostream>
#include <string>
using namespace std;

struct Computer {
    // A single node to store "Computer" information
};

void insertAtPosition(Computer*& head, int position) {
    // create a new node
    // fill in the values for each system ID

    // check if pos is head -> set as head then break

    // traverse to given position
    // validate if position is within the range
    
    // fit the node into the position.
}

void deleteByID(Computer*& head, int id) {
    // check if list is empty
    // check if list only contains one node
    // join prev. and next nodes
    
    // delete the node by ID
}









int main() {
    Computer* head = nullptr;
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
                int pos;
                cout << "Enter position to insert: ";
                cin >> pos;
                insertAtPosition(head, pos);
                break;
            }
            case 2: {
                int id;
                cout << "Enter System ID to delete: ";
                cin >> id;
                deleteByID(head, id);
                break;
            }
            case 3:
                displayWithGPU(head);
                break;
            case 4:
                displayAveragePrice(head);
                break;
            case 5:
                displayLeastRAM(head);
                break;
            case 6:
                displayAll(head);
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
