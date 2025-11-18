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
    int temp;
    print(num,size);
    for (int i = 0; i < size; i++)
    {
        temp=i;
        for (int j = i+1; j < size; j++)
        {
            if (num[j]<num[temp])
            {
                temp=j;
            }
            
        }
        
        if (num[i]>num[temp])
        {
            swap(num[i],num[temp]);
        }
        
        
    }
    print(num,size);
    

}