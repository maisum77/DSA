#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    string isbn;
    string title;
    string author;
};

class LibraryCatalog {
private:
    vector<vector<Book>> table;
    int size;
    
    int hash(string key) {
        int sum = 0;
        for (char c : key) {
            sum += c;
        }
        return sum % size;
    }
    
public:
    LibraryCatalog(int s = 10) {
        size = s;
        table.resize(size);
    }
    
    void addBook(string isbn, string title, string author) {
        if (isbn.empty() || title.empty() || author.empty()) {
            cout << "Invalid book details." << endl;
            return;
        }
        int index = hash(isbn);
        for (Book b : table[index]) {
            if (b.isbn == isbn) {
                cout << "Book with this ISBN already exists." << endl;
                return;
            }
        }
        Book newBook = {isbn, title, author};
        table[index].push_back(newBook);
        cout << "Book added." << endl;
    }
    
    void searchBook(string isbn) {
        if (isbn.empty()) {
            cout << "Invalid ISBN." << endl;
            return;
        }
        int index = hash(isbn);
        for (Book b : table[index]) {
            if (b.isbn == isbn) {
                cout << "Found - Title: " << b.title << ", Author: " << b.author << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }
    
    void deleteBook(string isbn) {
        if (isbn.empty()) {
            cout << "Invalid ISBN." << endl;
            return;
        }
        int index = hash(isbn);
        for (int i = 0; i < table[index].size(); i++) {
            if (table[index][i].isbn == isbn) {
                table[index].erase(table[index].begin() + i);
                cout << "Book deleted." << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }
    
    void displayAll() {
        bool empty = true;
        for (int i = 0; i < size; i++) {
            if (!table[i].empty()) {
                empty = false;
                for (Book b : table[i]) {
                    cout << "ISBN: " << b.isbn << ", Title: " << b.title << ", Author: " << b.author << endl;
                }
            }
        }
        if (empty) {
            cout << "Catalog is empty." << endl;
        }
    }
};

int main() {
    LibraryCatalog catalog;
    int option;
    string isbn, title, author;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Delete Book\n";
        cout << "4. Display All Books\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> option;
        
        switch(option) {
            case 1:
                cout << "Enter ISBN: ";
                cin >> isbn;
                cout << "Enter title: ";
                cin >> title;
                cout << "Enter author: ";
                cin >> author;
                catalog.addBook(isbn, title, author);
                break;
            case 2:
                cout << "Enter ISBN: ";
                cin >> isbn;
                catalog.searchBook(isbn);
                break;
            case 3:
                cout << "Enter ISBN: ";
                cin >> isbn;
                catalog.deleteBook(isbn);
                break;
            case 4:
                catalog.displayAll();
                break;
            case 0:
                cout << "Exiting." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
        }
    } while (option != 0);
    
    return 0;
}