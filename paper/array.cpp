#include <iostream>
using namespace std;
class student
{
public:
    int rollno;
    string name;
    int math;
    int science;
    int english;
};

class management
{
private:
    int count = 0;

public:
    static const int max_student = 100;
    student s[max_student];
    void add(int rollno, string name, int math, int science, int english)
    {
        s[count].rollno = rollno;
        s[count].name = name;
        s[count].math = math;
        s[count].science = science;
        s[count].english = english;
        count++;
    }
    void display()
    {
        for (int i = 0; i < count; i++)
        {
            cout << s[i].rollno<<endl;
            cout << s[i].name<<endl;
            cout << s[i].math<<endl;
            cout << s[i].science<<endl;
            cout << s[i].english<<endl;
        }
    }
    void find(int roll)
    {
        for (int i = 0; i < count; i++)
        {
            if(s[i].rollno==roll)
            {
                cout << s[i].rollno<<endl;
                cout << s[i].name<<endl;
                cout << s[i].math<<endl;
                cout << s[i].science<<endl;
                cout << s[i].english<<endl;
            }
        }
    }
    void average()
    {
        for (int i = 0; i < count; i++)
        {
            cout << s[i].rollno<<endl;
            cout << s[i].name<<endl;
            cout<<"Average: "<<(s[i].english+s[i].science+s[i].math)/3<<endl;
        }
    }
};
int main()
{
    management m;
    m.add(1, "Alice", 85, 90, 78);
    m.add(2, "Bob", 72, 68, 80);

    cout << "All students:\n";
    m.display();

    cout << "\nFind roll 2:\n";
    m.find(2);

    cout << "\nAverages:\n";
    m.average();

    return 0;
}
