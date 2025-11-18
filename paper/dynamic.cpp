#include<iostream>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the size of the arr=";
    cin>>size;
    int* arr= new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i]=i;
        
    }
    for (int j = 0; j < size; j++)
    {
        cout<<arr[j]<<endl;
        
    }
}