#include<iostream>
using namespace std;
int main()
{
    int arr[7]={2,5,9,12,17,37,86};
    int size=sizeof(arr)/sizeof(arr[0]);
    int s,l,m,n;
    cout<<"Enter your number to find : ";
    cin>>n;
    s=0;
    l=size-1;
    while (s<=l)
    {
        
        m=(s+l)/2;
        if(arr[m]==n)
        {
            cout<<"number is at index " <<m<<endl;
            break;
        }
        if(arr[m]<n)
        {
            s=m+1;
        }
        else
        {
            l=m-1;
        }
    }
    
}