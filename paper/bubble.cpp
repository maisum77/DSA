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
int main()
{
    int num[]= {12,9,37,86,2,17,5};
    int size=sizeof(num)/sizeof(num[0]);
    cout<<"before sorting:"<<endl;
    print(num,size);
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(num[i]>num[j])
            {
                swap(num[i],num[j]);
            }
        }
        
    }
    print(num,size);
}