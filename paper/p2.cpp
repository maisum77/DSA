#include<iostream>
using namespace std;
int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n*fact(n-1);
}
int fiba(int n)
{
    if(n<=1)
    {
        return n;
    }
    return fiba(n-1)+fiba(n-2); 
}
int main()
{
 
    cout<<fact(5)<<endl;

    
    for (int i = 0; i < 10; i++)
    {
        cout<<fiba(i)<<"->";
    }

}