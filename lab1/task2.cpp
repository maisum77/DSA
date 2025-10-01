#include<iostream>
using namespace std;
class Book
{
    public:
    string title;
    string author;
    float price;

    Book(string a, string b, float c)
    {
        title=a;
        author=b;
        price=c;
    }
    void display()
    {
        cout<<"Title= "<<title<<endl;
        cout<<"Author= "<<author<<endl;
        cout<<"Price= "<<price<<endl;
    }
};
int main()
{
    Book b("Power","Robert",120.23);
    b.display();
    return 0;
}