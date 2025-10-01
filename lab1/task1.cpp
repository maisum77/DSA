#include <iostream>
using namespace std;

struct student
{
  string name;
  int rollno;
  float marks;

  void display()
  {
    cout << "Name = " << name << endl;
    cout << "Roll No = " << rollno << endl;
    cout << "Marks = " << marks << endl;
  }
};
int main()
{
  student s1 = {"ali", 12, 30.2};
  s1.display();
  return 0;
}
