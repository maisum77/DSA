#include<iostream>
using namespace std;
class Car{
    public:
    string brand;
    string model;
    int make;
    Car(string brand,string model,int make)
    {
        this->brand=brand;
        this->model=model;
        this->make=make;
    }
    void display()
    {
        cout<<brand<<"\t"<<model<<"\t"<<make<<endl;
    }
};
int main()
{
    Car c1("toyota","corolla",2019);
    Car c2("honda","city",2006);
    Car c3("nissan","sunny",2003);

    c1.display();
    c2.display();
    c3.display();

}