#include <iostream>
#include <string>
using namespace std;

// Simple BST Node structure
struct Node {
    string path;        // Full path like "students/ahmed/semester1"
    string type;        // "folder" or "file"
    Node* left;
    Node* right;
    
    Node(string p, string t) {
        path = p;
        type = t;
        left = right = nullptr;
    }
};

class StudentFileSystem {
private:
    Node* root;
    
    // Insert item into BST
    Node* insertNode(Node* node, string path, string type) {
        if (node == nullptr) {
            return new Node(path, type);
        }
        
        if (path < node->path) {
            node->left = insertNode(node->left, path, type);
        } else if (path > node->path) {
            node->right = insertNode(node->right, path, type);
        } else {
            cout << "Already exists = " << path << endl;
        }
        return node;
    }
    
    // Search for item
    Node* searchNode(Node* node, string path) {
        if (!node || node->path == path) {
        return node;
    }

    // Recursive steps
    if (path < node->path) {
        return searchNode(node->left, path);
    } else {
        return searchNode(node->right, path);
    }
    }
    
    // Delete item from BST
    Node* deleteNode(Node* node, string path) {
        if (node == nullptr) {
            cout << "✗ Not found: " << path << endl;
            return nullptr;
        }
        
        if (path < node->path) {
            node->left = deleteNode(node->left, path);
        } else if (path > node->path) {
            node->right = deleteNode(node->right, path);
        } else {
            cout << "Deleting: " << path << endl;
            
            // One or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            
            // Two children: find smallest in right subtree
            Node* temp = node->right;
            while (temp->left != nullptr) temp = temp->left;
            
            node->path = temp->path;
            node->type = temp->type;
            node->right = deleteNode(node->right, temp->path);
        }
        return node;
    }
    
    // Display all items (inorder)
    void displayAll(Node* node) {
        if (node != nullptr) {
            displayAll(node->left);
            cout << "  - " << node->path << " (" << node->type << ")" << endl;
            displayAll(node->right);
        }
    }

public:
    StudentFileSystem() 
    { 
        root = nullptr; 
    }
    
    // CREATE operations
    void createPerson(string name) {
        string path = "students/" + name;
        root = insertNode(root, path, "person_folder");
    }
    
    void createRelationship(string person, string relation) {
        string path = "students/" + person + "/" + relation;
        root = insertNode(root, path, "relationship_folder");
    }
    
    void createCourse(string person, string relation, string course) {
        string path = "students/" + person + "/" + relation + "/" + course;
        root = insertNode(root, path, "course_file");
    }
    
    // SEARCH operation
    void search(string path) {
        Node* found = searchNode(root, path);
        if (found) {
            cout << "Found: " << found->path << " (" << found->type << ")" << endl;
        } else {
            cout << "Not found: " << path << endl;
        }
    }
    
    // DELETE operation
    void deleteItem(string path) {
        root = deleteNode(root, path);
    }
    
    // DISPLAY system
    void display() {
        if (root == nullptr) {
            cout << "\n[System empty]" << endl;
            return;
        }
        cout << "\n=== FILE SYSTEM STRUCTURE ===" << endl;
        displayAll(root);
        cout << "================================" << endl;
    }
};

// Demonstration
int main() {
    StudentFileSystem fs;
    
    cout << "====== STUDENT FILE SYSTEM ======" << endl;
    
    // Create sample data
    fs.createPerson("Ahmed");
    fs.createPerson("Bilal");
    
    fs.createRelationship("Ahmed", "Semester1");
    fs.createRelationship("Ahmed", "Semester2");
    fs.createRelationship("Bilal", "Semester1");
    
    fs.createCourse("Ahmed", "Semester1", "CS101");
    fs.createCourse("Ahmed", "Semester1", "MATH101");
    fs.createCourse("Ahmed", "Semester2", "CS102");
    fs.createCourse("Bilal", "Semester1", "CS101");
    
    // Display all
    fs.display();
    
    // Search examples
    cout << "\n--- Searching ---" << endl;
    fs.search("students/Ahmed/Semester1/CS101");
    fs.search("students/Bilal/Semester2"); // This will fail
    
    // Delete examples
    cout << "\n--- Deleting ---" << endl;
    fs.deleteItem("students/Ahmed/Semester1/CS101");
    fs.display();
    
    fs.deleteItem("students/Bilal");
    fs.display();
    
    return 0;
}