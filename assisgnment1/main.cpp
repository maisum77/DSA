#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    int ID;
    string name;
    double grade;

public:
    // Default constructor
    Student()
    {
        ID = 0;
        name = "";
        grade = 0.0;
    }

    // Parameterized constructor
    Student(int id, string studentName, double studentGrade)
    {
        ID = id;
        name = studentName;
        grade = studentGrade;
    }

    // getters to get the data
    int getID()
    {
        return ID;
    }

    string getName()
    {
        return name;
    }
    double getGrade()
    {
        return grade;
    }

    // setters to set the data
    void setName(string newName)
    {
        name = newName;
    }

    void setGrade(double newGrade)
    {
        grade = newGrade;
    }

    // display student details.
    void display()
    {
        cout << "ID: " << ID << ", Name: " << name << ", Grade: " << grade << endl;
    }
};

class StudentManager
{
    private:
    Student student[100]; //100 students are the limit that it can manage
    int count;
    public:
    StudentManager()
    {
        count=0;
    }

    int findStudent(int id) {
        for (int i = 0; i < count; i++) //run loop through all the available stundents
        {
            if (student[i].getID() == id) //check if the required id is found then return it 
            {
                return i; 
            }
        }
        //else it will give -1 
        return -1; 
    }

    void addStudent(int id,string name, double grade) {
        if (count >= 100)//check if the students count is less then 100
         {
             cout << "Cannot add more students. Limit reached " << endl;
            return;
        }
        if (findStudent(id) != -1) // tell if the student with same id exist already 
        {
             cout << "Student with ID " << id << " already exists." << endl;
            
        }
        //else the student will be added to the studnts array
        student[count] = Student(id, name, grade);
        count++;
        cout << "Student added successfully!" << endl;
    }
    void displayStudent(int id) {
        int index = findStudent(id); // take the index of the stundet id provided as the parameters of the function
        if (index != -1) //check if the index is. not -1 which mean stund doesnt exist . if exist then display its information
        {
            student[index].display();
        } 
        else  //else if it gives -1 then shows error message
        {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }

    void displayAllStudents() {
        if (count == 0) //first check if the student are there or not
        {
            cout << "No student records to display." << endl;
            
        }
        //for loop the display all the available students to the user
        cout << "\n--- All Student Records ---" << endl;
        for (int i = 0; i < count; ++i) {
            student[i].display();
        }
        cout << "-------------------------" << endl;
    }

    void updateStudent(int id, string newName, double newGrade) {
        int index = findStudent(id);
        if (index != -1) //find student id and give its index then set new grade and name to it using the setter function of student class 
        {
            student[index].setName(newName);
            student[index].setGrade(newGrade);
            cout << "Student record updated successfully!" << endl;
        } 
        else 
        {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }

    void deleteStudent(int id) {
        int index = findStudent(id);
        if (index != -1) 
        {
            //for loop it start with the object that is going to delete and then move each step one by one to previous point to fill the gap
            for (int i = index; i < count - 1; i++) {
                student[i] = student[i + 1];
            }
            count--; // Decrease the count of students.
            cout << "Student deleted successfully!" << endl;
        } 
        else 
        {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }
};

void showMenu() {
    cout << "\n===== Student Management System =====\n";
    cout << "1. Add Student\n";
    cout << "2. Update Student\n";
    cout << "3. Delete Student\n";
    cout << "4. Display Specific Student\n";
    cout << "5. Display All Students\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}
int main()
{
    StudentManager manager;
    int choice, id;
    string name;
    double grade;
    manager.addStudent(101, "ALI", 88.5);
    manager.addStudent(102, "Ahmed", 92.0);

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: // Add
                cout << "Enter Student ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin>>name;
                cout << "Enter Grade: ";
                cin >> grade;
                manager.addStudent(id, name, grade);
                break;
            case 2: // Update
                cout << "Enter Student ID to update: ";
                cin >> id;
                cout << "Enter New Name: ";
                cin>>name;
                cout << "Enter New Grade: ";
                cin >> grade;
                manager.updateStudent(id, name, grade);
                break;
            case 3: // Delete
                cout << "Enter Student ID to delete: ";
                cin >> id;
                manager.deleteStudent(id);
                break;
            case 4: // Display Specific
                cout << "Enter Student ID to display: ";
                cin >> id;
                manager.displayStudent(id);
                break;
            case 5: // Display All
                manager.displayAllStudents();
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}