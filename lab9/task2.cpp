#include <iostream>
using namespace std;

// Class to represent each node in the tree
class StudentNode {
public:
    int rollNumber;
    StudentNode* left;
    StudentNode* right;

    StudentNode(int val) {
        rollNumber = val;
        left = nullptr;
        right = nullptr;
    }
};

// Class to manage the Binary Search Tree
class UniversityBST {
private:
    StudentNode* root;

    // Internal helper for insertion
    StudentNode* insertHelper(StudentNode* node, int val) {
        if (node == nullptr) return new StudentNode(val);

        if (val < node->rollNumber)
            node->left = insertHelper(node->left, val);
        else if (val > node->rollNumber)
            node->right = insertHelper(node->right, val);

        return node;
    }

    // Internal helper for in-order traversal
    void inorderHelper(StudentNode* node) {
        if (node == nullptr) return;
        inorderHelper(node->left);
        cout << node->rollNumber << " ";
        inorderHelper(node->right);
    }

    // Internal helper to find the minimum value (for deletion)
    StudentNode* findMin(StudentNode* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    // Internal helper for deletion
    StudentNode* deleteHelper(StudentNode* node, int key) {
        if (node == nullptr) return node;

        if (key < node->rollNumber)
            node->left = deleteHelper(node->left, key);
        else if (key > node->rollNumber)
            node->right = deleteHelper(node->right, key);
        else {
            // Case 1 & 2: One child or No child
            if (node->left == nullptr) {
                StudentNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                StudentNode* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Two children
            StudentNode* temp = findMin(node->right);
            node->rollNumber = temp->rollNumber;
            node->right = deleteHelper(node->right, temp->rollNumber);
        }
        return node;
    }

public:
    UniversityBST() { root = nullptr; }

    void insert(int val) {
        root = insertHelper(root, val);
    }

    void remove(int val) {
        root = deleteHelper(root, val);
    }

    bool search(int key) {
        StudentNode* current = root;
        while (current != nullptr) {
            if (current->rollNumber == key) return true;
            if (key < current->rollNumber) current = current->left;
            else current = current->right;
        }
        return false;
    }

    void displayInOrder() {
        inorderHelper(root);
        cout << endl;
    }
};

int main() {
    UniversityBST uni;

    // 1. Insert multiple roll numbers
    uni.insert(55);
    uni.insert(32);
    uni.insert(89);
    uni.insert(12);
    uni.insert(45);
    uni.insert(67);

    // 2. Show in-order traversal before deletion
    cout << "Students in system (Before Deletion): ";
    uni.displayInOrder();

    // 3. Search for a roll number
    int rollToFind = 45;
    if (uni.search(rollToFind))
        cout << "Search: Roll number " << rollToFind << " found.\n";
    else
        cout << "Search: Roll number " << rollToFind << " not found.\n";

    // 4. Delete a roll number
    int rollToRemove = 32;
    cout << "\nStudent " << rollToRemove << " transferred. Removing from system...\n";
    uni.remove(rollToRemove);

    // 5. Show in-order traversal after deletion
    cout << "Students in system (After Deletion): ";
    uni.displayInOrder();

    return 0;
}