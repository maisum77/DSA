#include<iostream>
using namespace std;
int main()
{
   int arr[6] = {12, 35, 1, 10, 34, 1};
   
   int largest=0;
   int semi_largest=0;
   for(int i=0;i<=5;i++)
   {
    
    if(arr[i]>largest)
    {
        largest=arr[i];
    }
    if(arr[i]<largest && arr[i]>semi_largest)
    {
        semi_largest=arr[i];
    }
   }
   if (semi_largest==0)
   {
    return -1;
   }
   cout<<"largest value ="<<largest<<endl;
   cout<<"second largest value ="<<semi_largest;
}