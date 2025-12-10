#include <iostream>
#include <string>
using namespace std;

struct Item {
    int id;
    string name;
    int quantity;
    double weight;
};

class WarehouseStack {
private:
    static const int MAX=6;
    Item stackArr[MAX];
    int top;

public:
    WarehouseStack() {
        top = -1; 
    }

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int id, string name, int qty, double w) {
        if (isFull()) {
            cout << "Warehouse is full! Cannot add item '" << name << "'." << endl;
            return;
        }
        
        top++;
        stackArr[top].id = id;
        stackArr[top].name = name;
        stackArr[top].quantity = qty;
        stackArr[top].weight = w;
        
        cout << "Success: Item '" << name << "' added to stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Error: Warehouse is empty! Nothing to remove." << endl;
            return;
        }
        
        Item removed = stackArr[top];
        top--;
        cout << "Success: Item '" << removed.name << "' removed from stack." << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Warehouse is empty." << endl;
            return;
        }
        
        cout << "\n--- Top Item Details ---" << endl;
        cout << "ID: " << stackArr[top].id << endl;
        cout << "Name: " << stackArr[top].name << endl;
        cout << "Quantity: " << stackArr[top].quantity << endl;
        cout << "Weight: " << stackArr[top].weight << "kg" << endl;
        cout << "------------------------\n" << endl;
    }

    void display() {
        cout << "\n=== Current Warehouse Inventory (Top to Bottom) ===" << endl;
        for (int i = top; i >= 0; i--) {
            cout << "Item [" << i << "]: " 
                 << stackArr[i].name 
                 << " (ID: " << stackArr[i].id << ")" << endl;
        }
        cout << "===================================================\n" << endl;
    }
};

int main() {
    WarehouseStack warehouse;
    int choice;
    
    int id, qty;
    string name;
    double weight;

    do {
        cout << "1. Push Item" << endl;
        cout << "2. Pop Item" << endl;
        cout << "3. Peek (View Top Item)" << endl;
        cout << "4. Display All Items" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (warehouse.isFull()) {
                cout << "Warehouse is full. Cannot input details." << endl;
            } else {
                cout << "Enter ID: "; cin >> id;
                cout << "Enter Name: "; cin >> name;
                cout << "Enter Quantity: "; cin >> qty;
                cout << "Enter Weight: "; cin >> weight;
                warehouse.push(id, name, qty, weight);
            }
            break;
        case 2:
            warehouse.pop();
            break;
        case 3:
            warehouse.peek();
            break;
        case 4:
            warehouse.display();
            break;
        case 0:
            cout << "Exiting system..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
        cout << endl;

    } while (choice != 0);

    return 0;
}