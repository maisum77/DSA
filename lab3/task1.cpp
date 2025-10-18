#include<iostream>
using namespace std;
int main()
{
    int arr[6]={5,10,15,20,25,30};
    int sum=0;
    for (int i = 0; i < 6; i++)
    {
        sum+=arr[i];
    }
    cout<<"Sum= "<<sum<<endl
        <<"Average= "<<sum/6<<endl;
    
}