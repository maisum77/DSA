#include <iostream>
#include <string>

using namespace std;

class StudentNode
{
public:
    int rollNumber;
    string name;
    int mathMarks;
    int scienceMarks;
    int englishMarks;
    StudentNode *next;

    // Constructor
    StudentNode(int roll, string n, int math, int sci, int eng)
    {
        rollNumber = roll;
        name = n;
        mathMarks = math;
        scienceMarks = sci;
        englishMarks = eng;
        next = nullptr;
    }

    int getTotalMarks()
    {
        return mathMarks + scienceMarks + englishMarks;
    }

    float getAverage()
    {

        return getTotalMarks() / 3;
    }


    void display()
    {
        cout << "  Roll No: " << rollNumber << endl;
        cout << "  Name:    " << name << endl;
        cout << "  Marks (M, S, E): " << mathMarks << ", " << scienceMarks << ", " << englishMarks << endl;
        cout << "  Total:   " << getTotalMarks() << endl;
        cout << "  Average: " << getAverage() << "%" << endl;
    }
};

class StudentList
{
private:
    StudentNode *head;
    StudentNode *tail;

public:
    StudentList()
    {
        head = NULL;
        tail = NULL;
    }

    void addStudent(int roll, string name, int math, int sci, int eng)
    {

        StudentNode *temp = head;
        while (temp != NULL)
        {
            if (temp->rollNumber == roll)
            {
                cout << "Error: Student with Roll No " << roll << " already exists." << endl;
                return;
            }
            temp = temp->next;
        }

        StudentNode *newNode = new StudentNode(roll, name, math, sci, eng);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Added student " << endl;
    }

    void displayAll()
    {
        cout << "\n--- Displaying All Student Records ---" << endl;
        if (head == NULL)
        {
            cout << "The student list is empty." << endl;
            return;
        }

        StudentNode *temp = head;
        while (temp != NULL)
        {
            temp->display();
            cout << "-----------------------------------" << endl;
            temp = temp->next;
        }
    }

    void searchByRoll(int roll)
    {
        cout << "\n--- Searching for Roll No: " << roll << " ---" << endl;
        StudentNode *temp = head;
        while (temp != NULL)
        {
            if (temp->rollNumber == roll)
            {
                cout << "Student found:" << endl;
                temp->display();
                return;
            }
            temp = temp->next;
        }

        cout << "Student with Roll No " << roll << " was not found." << endl;
    }

    void calculateAverages()
    {
        cout << "\n--- Student Averages ---" << endl;
        if (head == NULL)
        {
            cout << "The student list is empty." << endl;
            return;
        }

        StudentNode *temp = head;
        while (temp != NULL)
        {
            cout << "  - " << temp->name << " (Roll: " << temp->rollNumber << "): ";
            cout << temp->getAverage() << "%" << endl;
            temp = temp->next;
        }
    }


    void displayHighestScorer()
    {
        cout << "\n--- Highest Scoring Student ---" << endl;
        if (head == nullptr)
        {
            cout << "The student list is empty." << endl;
            return;
        }

        StudentNode *highestScorer = head;
        int maxTotal = head->getTotalMarks();

        StudentNode *temp = head->next;
        while (temp != NULL)
        {
            int currentTotal = temp->getTotalMarks();
            if (currentTotal > maxTotal)
            {
                maxTotal = currentTotal;
                highestScorer = temp;
            }
            temp = temp->next;
        }
        cout << "The student with the highest total marks is:" << endl;
        highestScorer->display();
    }
};

void showMenu()
{
    cout << "\n===== Student Record Management =====" << endl;
    cout << "1. Add a new student" << endl;
    cout << "2. Display all student records" << endl;
    cout << "3. Search for a student by roll number" << endl;
    cout << "4. Display average of all students" << endl;
    cout << "5. Display student with highest marks" << endl;
    cout << "0. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice: ";
}

int main()
{

    StudentList studentDB;
    int choice;
    cout << "--- Loading initial student data... ---" << endl;
    studentDB.addStudent(101, "Maisum Abbas", 88, 92, 85);
    studentDB.addStudent(102, "Umair Nadeem", 75, 80, 78);
    studentDB.addStudent(103, "AON", 95, 98, 99);
    cout << "---------------------------------------" << endl;

    do
    {
        showMenu();
        cin >> choice;
        int roll, math, sci, eng;
        string name;

        switch (choice)
        {
        case 1:

            cout << "\n--- Add New Student ---" << endl;
            cout << "Enter Roll Number: ";
            cin >> roll;

            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Math Marks: ";
            cin >> math;

            cout << "Enter Science Marks: ";
            cin >> sci;

            cout << "Enter English Marks: ";
            cin >> eng;

            studentDB.addStudent(roll, name, math, sci, eng);
            break;

        case 2:
            studentDB.displayAll();
            break;

        case 3:
            cout << "Enter Roll Number to search: ";
            cin >> roll;
            studentDB.searchByRoll(roll);
            break;

        case 4:
            studentDB.calculateAverages();
            break;

        case 5:
            studentDB.displayHighestScorer();
            break;

        case 0:
            cout << "\nExiting program" << endl;
            break;

        default:
            cout << "\nInvalid choice. Please try again." << endl;
        }
        if (choice != 0)
        {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 0);

    return 0;
}