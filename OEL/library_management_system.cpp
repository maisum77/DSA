#include <iostream> // For input/output operations
#include <string>   // For string handling
#include <cstdlib>  // For general utilities
using namespace std;

struct Book
{
    int bookID;    // Book identification number
    string title;  // Book title
    string author; // Book author name
};

struct Member
{
    int memberID; // Member identification number
    string name;  // Member name
    Member *next; // Pointer to next member node
};

class Library
{
private:
    // --- DYNAMIC ARRAY FOR BOOKS ---
    Book *books;      // Pointer to dynamic array of books
    int bookCount;    // Current number of books stored
    int bookCapacity; // Maximum capacity of the array

    // --- LINKED LIST FOR MEMBERS ---
    Member *memberHead; // Head pointer of member linked list

    // --- QUEUE FOR RESERVATIONS ---
    // Simple array-based queue implementation
    int *reservationQueue; // Array to store reserved book IDs
    int queueFront;        // Front of the queue
    int queueRear;         // Rear of the queue
    int queueSize;         // Current queue size
    int queueCapacity;     // Maximum queue capacity

    // --- STACK FOR RETURNED BOOKS ---
    int *returnStack;  // Array to store returned book IDs
    int stackTop;      // Top of the stack
    int stackCapacity; // Maximum stack capacity

    // --- HASH TABLE FOR BOOK SEARCH ---
    Book **hashTable; // Array of pointers to books
    int hashSize;     // Size of the hash table

public:
    Library()
    {
        // Initialize book array
        bookCapacity = 10;              // Start with capacity of 10
        bookCount = 0;                  // No books yet
        books = new Book[bookCapacity]; // Allocate memory for books

        // Initialize member linked list
        memberHead = nullptr; // Empty list initially

        // Initialize reservation queue
        queueCapacity = 20; // Queue can hold 20 reservations
        queueSize = 0;
        queueFront = 0;
        queueRear = -1;
        reservationQueue = new int[queueCapacity];

        // Initialize return stack
        stackCapacity = 20; // Stack can hold 20 books
        stackTop = -1;      // Empty stack
        returnStack = new int[stackCapacity];

        // Initialize hash table
        hashSize = 30; // Hash table size
        hashTable = new Book *[hashSize];
        for (int i = 0; i < hashSize; i++)
        {
            hashTable[i] = nullptr; // All slots empty initially
        }
    }

    ~Library()
    {
        delete[] books;            // Free book array memory
        delete[] reservationQueue; // Free queue memory
        delete[] returnStack;      // Free stack memory

        // Free linked list memory
        Member *current = memberHead;
        while (current != nullptr)
        {
            Member *temp = current;
            current = current->next;
            delete temp;
        }

        // Free hash table memory
        delete[] hashTable;
    }

    void addBook(int id, string bookTitle, string bookAuthor)
    {
        // Check if array needs to be resized
        if (bookCount >= bookCapacity)
        {
            resizeBookArray(); // Make more space
        }

        // Add book to the array
        books[bookCount].bookID = id;
        books[bookCount].title = bookTitle;
        books[bookCount].author = bookAuthor;
        bookCount++; // Increase book count

        // Add book to hash table for fast search
        addToHashTable(id, bookTitle, bookAuthor);

        cout << "Book added successfully!\n";
    }

    void resizeBookArray()
    {
        // Double the capacity
        bookCapacity = bookCapacity * 2;

        // Create new larger array
        Book *newBooks = new Book[bookCapacity];

        // Copy all books to new array
        for (int i = 0; i < bookCount; i++)
        {
            newBooks[i] = books[i];
        }

        // Delete old array and point to new one
        delete[] books;
        books = newBooks;

        cout << "Book array resized to capacity: " << bookCapacity << "\n";
    }

    void addMember(int id, string memberName)
    {
        // Create new member node
        Member *newMember = new Member;
        newMember->memberID = id;
        newMember->name = memberName;
        newMember->next = nullptr;

        // If list is empty, make this the head
        if (memberHead == nullptr)
        {
            memberHead = newMember;
        }
        else
        {
            // Traverse to the end of the list
            Member *current = memberHead;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            // Add new member at the end
            current->next = newMember;
        }

        cout << "Member added successfully!\n";
    }

    void addToHashTable(int id, string title, string author)
    {
        // Calculate hash index using modulo operation
        int index = id % hashSize;

        // Handle collision using linear probing
        int originalIndex = index;
        int attempts = 0;

        while (hashTable[index] != nullptr && attempts < hashSize)
        {
            index = (index + 1) % hashSize; // Move to next slot
            attempts++;
        }

        // If we found an empty slot
        if (attempts < hashSize)
        {
            // Create a new book in the hash table
            hashTable[index] = new Book;
            hashTable[index]->bookID = id;
            hashTable[index]->title = title;
            hashTable[index]->author = author;
        }
    }

    void searchBook(int id)
    {
        // Calculate hash index
        int index = id % hashSize;

        // Search in hash table with linear probing
        int originalIndex = index;
        int attempts = 0;
        bool found = false;

        while (hashTable[index] != nullptr && attempts < hashSize)
        {
            if (hashTable[index]->bookID == id)
            {
                // Book found!
                cout << "\n--- BOOK FOUND ---\n";
                cout << "Book ID  : " << hashTable[index]->bookID << "\n";
                cout << "Title    : " << hashTable[index]->title << "\n";
                cout << "Author   : " << hashTable[index]->author << "\n";
                found = true;
                break;
            }
            index = (index + 1) % hashSize;
            attempts++;
        }

        if (!found)
        {
            cout << "Book with ID " << id << " not found in library.\n";
        }
    }

    void sortBooks()
    {
        // Bubble Sort Algorithm - Simple and easy to understand
        // Compares adjacent elements and swaps them if in wrong order

        if (bookCount <= 1)
        {
            cout << "Not enough books to sort.\n";
            return;
        }

        // Outer loop: passes through the array
        for (int i = 0; i < bookCount - 1; i++)
        {
            // Inner loop: compare adjacent elements
            for (int j = 0; j < bookCount - i - 1; j++)
            {
                // If current book ID is greater than next book ID, swap them
                if (books[j].bookID > books[j + 1].bookID)
                {
                    // Swap the books
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }

        cout << "Books sorted successfully by ID!\n";
    }

    void reserveBook(int bookID)
    {
        // Check if queue is full
        if (queueSize >= queueCapacity)
        {
            cout << "Reservation queue is full! Cannot reserve more books.\n";
            return;
        }

        // Add to queue (circular queue implementation)
        queueRear = (queueRear + 1) % queueCapacity;
        reservationQueue[queueRear] = bookID;
        queueSize++;

        cout << "Book ID " << bookID << " added to reservation queue.\n";
    }

    void processReservation()
    {
        if (queueSize <= 0)
        {
            cout << "No reservations to process.\n";
            return;
        }

        // Get the front element
        int reservedBookID = reservationQueue[queueFront];
        queueFront = (queueFront + 1) % queueCapacity;
        queueSize--;

        cout << "Processing reservation for Book ID: " << reservedBookID << "\n";
    }

    void returnBook(int bookID)
    {
        // Check if stack is full
        if (stackTop >= stackCapacity - 1)
        {
            cout << "Return stack is full! Cannot add more returns.\n";
            return;
        }

        // Push book ID onto stack
        stackTop++;
        returnStack[stackTop] = bookID;

        cout << "Book ID " << bookID << " returned and added to recent returns.\n";
    }

    void viewRecentReturns()
    {
        if (stackTop < 0)
        {
            cout << "No books have been returned yet.\n";
            return;
        }

        cout << "\n--- RECENTLY RETURNED BOOKS ---\n";
        // Display from top to bottom (LIFO order)
        for (int i = stackTop; i >= 0; i--)
        {
            cout << "Book ID: " << returnStack[i] << "\n";
        }
    }

    void displayAll()
    {
        cout << "\n========================================\n";
        cout << "         LIBRARY INFORMATION\n";
        cout << "========================================\n";

        // Display all books
        cout << "\n--- ALL BOOKS (" << bookCount << " books) ---\n";
        if (bookCount == 0)
        {
            cout << "No books in library.\n";
        }
        else
        {
            for (int i = 0; i < bookCount; i++)
            {
                cout << "ID: " << books[i].bookID
                     << " | Title: " << books[i].title
                     << " | Author: " << books[i].author << "\n";
            }
        }

        // Display all members
        cout << "\n--- ALL MEMBERS ---\n";
        if (memberHead == nullptr)
        {
            cout << "No members registered.\n";
        }
        else
        {
            Member *current = memberHead;
            int memberNum = 1;
            while (current != nullptr)
            {
                cout << "Member " << memberNum << ": ID="
                     << current->memberID << ", Name=" << current->name << "\n";
                current = current->next;
                memberNum++;
            }
        }

        // Display reservation queue
        cout << "\n--- RESERVATION QUEUE (" << queueSize << " reservations) ---\n";
        if (queueSize == 0)
        {
            cout << "No reservations in queue.\n";
        }
        else
        {
            for (int i = 0; i < queueSize; i++)
            {
                int index = (queueFront + i) % queueCapacity;
                cout << "Reservation " << (i + 1) << ": Book ID "
                     << reservationQueue[index] << "\n";
            }
        }

        // Display recent returns
        cout << "\n--- RECENT RETURNS ---\n";
        if (stackTop < 0)
        {
            cout << "No recent returns.\n";
        }
        else
        {
            cout << "Total books returned: " << (stackTop + 1) << "\n";
        }

        cout << "\n========================================\n";
    }
};

void displayMenu()
{
    cout << "\n========================================\n";
    cout << "     LIBRARY MANAGEMENT SYSTEM\n";
    cout << "========================================\n";
    cout << "1. Add New Book\n";
    cout << "2. Add New Member\n";
    cout << "3. Search Book by ID (Hash Search)\n";
    cout << "4. Sort Books by ID\n";
    cout << "5. Reserve a Book (Add to Queue)\n";
    cout << "6. Process Next Reservation\n";
    cout << "7. Return a Book (Add to Stack)\n";
    cout << "8. View Recent Returns\n";
    cout << "9. Display All Information\n";
    cout << "10. Exit\n";
    cout << "========================================\n";
    cout << "Enter your choice (1-10): ";
}

int getIntegerInput(string prompt)
{
    int value;
    cout << prompt;
    cin >> value;
    return value;
}

string getStringInput(string prompt)
{
    string value;
    cout << prompt;
    cin >> value;
    return value;
}

int main()
{
    // Create library object
    Library library;

    int choice;    // To store user's menu choice
    int id;        // To store book or member ID
    string title;  // To store book title
    string author; // To store book author
    string name;   // To store member name

    // Main program loop - keeps running until user chooses to exit
    while (true)
    {
        // Display menu and get user choice
        displayMenu();
        cin >> choice;
        cout << "\n";

        // Process user's choice using switch statement
        switch (choice)
        {
        case 1:
            // Add a new book
            cout << "--- ADD NEW BOOK ---\n";
            id = getIntegerInput("Enter Book ID: ");
            title = getStringInput("Enter Book Title: ");
            author = getStringInput("Enter Book Author: ");
            library.addBook(id, title, author);
            break;

        case 2:
            // Add a new member
            cout << "--- ADD NEW MEMBER ---\n";
            id = getIntegerInput("Enter Member ID: ");
            name = getStringInput("Enter Member Name: ");
            library.addMember(id, name);
            break;

        case 3:
            // Search for a book using hash table
            cout << "--- SEARCH BOOK ---\n";
            id = getIntegerInput("Enter Book ID to search: ");
            library.searchBook(id);
            break;

        case 4:
            // Sort books by ID
            cout << "--- SORT BOOKS ---\n";
            library.sortBooks();
            break;

        case 5:
            // Reserve a book (add to queue)
            cout << "--- RESERVE BOOK ---\n";
            id = getIntegerInput("Enter Book ID to reserve: ");
            library.reserveBook(id);
            break;

        case 6:
            // Process next reservation
            cout << "--- PROCESS RESERVATION ---\n";
            library.processReservation();
            break;

        case 7:
            // Return a book (add to stack)
            cout << "--- RETURN BOOK ---\n";
            id = getIntegerInput("Enter Book ID being returned: ");
            library.returnBook(id);
            break;

        case 8:
            // View recent returns
            cout << "--- VIEW RECENT RETURNS ---\n";
            library.viewRecentReturns();
            break;

        case 9:
            // Display all library information
            library.displayAll();
            break;

        case 10:
            // Exit the program
            cout << "Thank you for using Library Management System!\n";
            cout << "Goodbye!\n";
            return 0; // Exit main function

        default:
            // Invalid choice
            cout << "Invalid choice! Please enter a number between 1 and 10.\n";
        }

        cout << "\n"; // Add blank line for readability
    }

    return 0; // Return statement (though we never reach here due to exit)
}
