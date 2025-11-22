#include<iostream>
using namespace std;
void print(int arr[],int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<"->";
    }
    cout<<endl;
}
int main(){
     int num[]= {12,9,37,86,2,17,5};
    int size=sizeof(num)/sizeof(num[0]);
    int key;
    for (int i = 1; i < size; i++)
    {
        key=num[i];
        int j=i-1;
        while (num[j]>key&&j>=0)
        {
            num[j+1]=num[j];
            j--;
        }
        num[j+1]=key;
    }
    print(num,size);
}