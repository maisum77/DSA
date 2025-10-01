#include<iostream>
using namespace std;
class Student
{
    public:
    string name;
    int marks;
    Student(string name,int marks) //constructor
    {
        this->name=name;
        this->marks=marks;
    }
    void display() //display name and marks
    {
        cout<<"Name= "<<name<<" Marks= "<<marks<<endl;
    }
};

void Calculation(Student students[], int number) //calculation function to cal culate average,max,min
{
    int total = 0;
    int min=students[0].marks;
    int max=students[0].marks;
    //find total
    for(int i = 0; i < number; i++)
    {
        total += students[i].marks;
    }
    //find min value
    for(int j = 0; j < number; j++)
    {
        if(min>students[j].marks)
        {
            min=students[j].marks;
        }
    } 
    //find max value  
    for(int k = 0; k < number; k++)
    {
        if(max<students[k].marks)
        {
            max=students[k].marks;
        }
    }   
    cout << "Average marks= " << total/number << endl;
    cout<<"minimum marks= "<<min<<endl;
    cout<<"maximum marks= "<<max<<endl;
    
}

int main()
{
    //bulk object creation
    Student student[8]={
        Student{"ali",24},
        Student{"ahmed",34},
        Student{"aon",45},
        Student{"anas",70},
        Student{"aliyan",24},
        Student{"aazan",87},
        Student{"asfhaq",99},
        Student{"ameer",24}
    };
    //dispaly values
    for(int i=0;i<8;i++)
    {
        student[i].display();
    }
    //calculte value according to the conditions
    Calculation(student, 8);

}
