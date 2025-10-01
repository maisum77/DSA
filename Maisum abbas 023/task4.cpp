#include<iostream>
using namespace std;
class Rectangle
{
    private:
    int l,w;
    public:
    Rectangle(int l,int w)
    {
        this->l=l;
        this->w=w;
    }
    int area()
    {
        return l*w;
    }
    int peremeter()
    {
        return l+w;
    }
};

int main()
{
    for(int i=0;i<=5;i++)
    {
        if(i==0 || i==5)
        {
            cout<<"*******"<<endl;
        }
        else{
            cout<<"*";
            for(int j=0;j<=4;j++)
            {
                cout<<" ";
            }
            cout<<"*"<<endl;
        }
    }

    Rectangle r1(12,30);
    cout<<"Area= "<<r1.area()<<" Peremeter= "<<r1.peremeter()<<endl;
    return 0;
}