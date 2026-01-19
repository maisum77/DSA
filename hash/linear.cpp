#include <iostream>
#include <vector>

using namespace std;

class HashLinearProbing {
    int size;
    vector<int> table;

public:
    // Constructor: Initialize table with -1 (meaning empty)
    HashLinearProbing(int s) {
        size = s;
        table.assign(size, -1);
    }

    // 1. Hash Function
    int hashFunction(int key) {
        return key % size;
    }

    // 2. Insert Item
    void insertItem(int key) {
        int index = hashFunction(key);

        // Linear Probing: Find next empty spot
        // We loop until we find -1 or we circle back to start
        int originalIndex = index;
        while (table[index] != -1) {
            index = (index + 1) % size; // Move to next, wrap around if needed
            
            // If we circled back to the start, table is full
            if (index == originalIndex) {
                cout << "Table is full! Cannot insert " << key << endl;
                return;
            }
        }

        table[index] = key; // Found a spot, insert the key
    }

    // 3. Display
    void displayHash() {
        for (int i = 0; i < size; i++) {
            if (table[i] != -1)
                cout << "Index " << i << ": " << table[i] << endl;
            else
                cout << "Index " << i << ": Empty" << endl;
        }
    }
};

int main() {
    HashLinearProbing h(7);

    h.insertItem(50); // Index 1
    h.insertItem(700); // Index 0
    h.insertItem(76); // Index 6
    h.insertItem(85); // Index 1 (Collision! Moves to Index 2)
    h.insertItem(92); // Index 1 (Collision! Moves to 2, then 3)

    h.displayHash();

    return 0;
}