#include <iostream>
#include <string>

using namespace std;

// Class representing a folder node
class FolderNode {
public:
    string folderName;
    FolderNode* left;
    FolderNode* right;

    FolderNode(string name) {
        folderName = name;
        left = nullptr;
        right = nullptr;
    }
};

// Class to manage the File System Tree
class FileSystem {
private:
    FolderNode* root;

    // Recursive helper for Pre-order: Root -> Left -> Right
    void preOrderHelper(FolderNode* node) {
        if (node == nullptr) return;
        cout << "[" << node->folderName << "] ";
        preOrderHelper(node->left);
        preOrderHelper(node->right);
    }

    // Recursive helper for In-order: Left -> Root -> Right
    void inOrderHelper(FolderNode* node) {
        if (node == nullptr) return;
        inOrderHelper(node->left);
        cout << "[" << node->folderName << "] ";
        inOrderHelper(node->right);
    }

    // Recursive helper for Post-order: Left -> Right -> Root
    void postOrderHelper(FolderNode* node) {
        if (node == nullptr) return;
        postOrderHelper(node->left);
        postOrderHelper(node->right);
        cout << "[" << node->folderName << "] ";
    }

public:
    FileSystem(FolderNode* rootNode) {
        root = rootNode;
    }

    void showPreOrder() {
        cout << "Pre-order:  ";
        preOrderHelper(root);
        cout << endl;
    }

    void showInOrder() {
        cout << "In-order:   ";
        inOrderHelper(root);
        cout << endl;
    }

    void showPostOrder() {
        cout << "Post-order: ";
        postOrderHelper(root);
        cout << endl;
    }
};

int main() {
    
    FolderNode* root = new FolderNode("Root");
    root->left = new FolderNode("Users");
    root->right = new FolderNode("Windows");
    
    root->left->left = new FolderNode("Docs");
    root->left->right = new FolderNode("Music");
    
    root->right->right = new FolderNode("System32");

    FileSystem myFiles(root);

    cout << "--- File Manager Directory Listing ---\n\n";
    
    myFiles.showPreOrder();
    myFiles.showInOrder();
    myFiles.showPostOrder();

    return 0;
}