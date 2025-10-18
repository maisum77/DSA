#include <iostream>
#include <fstream>  
#include <string>
using namespace std;


const int NUM_STUDENTS = 25;


class Student {
public:
    int roll_no;
    string name;
    float marks;
};


void bubbleSort(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].roll_no > arr[j+1].roll_no) {
                Student temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    
    ifstream inputFile("student_information.txt");
    Student students[NUM_STUDENTS];

    for (int i = 0; i < NUM_STUDENTS; i++) {
        inputFile >> students[i].roll_no >> students[i].name >> students[i].marks;
    }

    inputFile.close();
    bubbleSort(students, NUM_STUDENTS);

    ofstream outputFile("sorted_information.txt");

    for (int i = 0; i < NUM_STUDENTS; i++) {
        outputFile << students[i].roll_no << " " << students[i].name << " " << students[i].marks << endl;
    }
    outputFile.close();

    cout << "Sorted student records have been saved to sorted_information.txt" <<endl;

    return 0; 
}