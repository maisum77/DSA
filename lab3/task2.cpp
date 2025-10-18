#include<iostream>
using namespace std;
int linear(int arr[],int num,int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==num)
        {
            return i;
        }
    }
    return -1;
}
int binary(int arr[],int num,int size)
{
    int start=arr[0];
    int end=size-1;
    int mid=0;
    
    while (start <= end)
    {
        mid=(start+end)/2;
        if(arr[mid] == num)
        {
            return mid;
        }
        else if(arr[mid] < num)
        {
            start=mid+1;
        }
        else 
        {
            end=mid-1;
        }
    }
    return -1;
    
}

int main()
{
    int size=0;
    cout<<"Enter size of the array= ";
    cin>>size;
    int *dynamicArr = new int[size];
    for (int i = 0; i < size; i++)
    {
        dynamicArr[i]=i*10;
    }
    int input=0;
    here:
    cout<<"Enter the number to search= ";
    cin>>input;
    if(input<0)
    {
        goto here;
    }
    cout<<"Linear Searching= "<<linear(dynamicArr,input,size)<<endl
        <<"Binary Searching= "<<binary(dynamicArr,input,size);
    delete[] dynamicArr;
    return 0;


}
