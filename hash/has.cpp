#include <iostream>
#include <list>
#include <vector>

using namespace std;

class HashChaining {
    int BUCKET; // Size of the hash table
    vector<list<int>> table; // A vector where every slot holds a list

public:
    // Constructor to set size
    HashChaining(int size) {
        BUCKET = size;
        table.resize(BUCKET);
    }

    // 1. Hash Function
    int hashFunction(int key) {
        return key % BUCKET;
    }

    // 2. Insert Item
    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key); // Push into the list at that index
    }

    // 3. Display Hash Table
    void displayHash() {
        for (int i = 0; i < BUCKET; i++) {
            cout << "Index " << i << ": ";
            for (int x : table[i]) {
                cout << x << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    // Create a hash table of size 7
    HashChaining h(7);

    // Insert data (notice 15 and 8 will collide at index 1)
    h.insertItem(15); // 15 % 7 = 1
    h.insertItem(11); // 11 % 7 = 4
    h.insertItem(27); // 27 % 7 = 6
    h.insertItem(8);  // 8 % 7 = 1  <-- Collision! Adds to list at index 1

    h.displayHash();

    return 0;
}