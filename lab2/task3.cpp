#include <iostream>
using namespace std;
class Students
{
private:
    string name;
    int roll_no;
    float marks = 0.0f;

public:
    Students(string name, int roll_no, float marks)//constructor to insitialize and declare data
    {
        this->name = name;
        this->roll_no = roll_no;
        this->marks = marks;
    }
    void display()
    {
        cout << "Name: " << name << "\t | Roll_no " << roll_no << "\t | Marks " << marks << " | \n";
    }
};
int main()
{
    
    Students students[6] =      //bulk object creating
        {
            Students{"Ahmed", 9, 3.8},
            Students{"Maisum", 23, 3.9},
            Students{"Umair", 14, 3.8},
            Students{"Aon", 5, 3.8},
            Students{"Hassan", 23, 3.8},
            Students{"Ali", 10, 3.8},
        };
    for (int i = 0; i < 6; i++) //displaying objects info to user
    {
        students[i].display();
    }
    return 0;
}
