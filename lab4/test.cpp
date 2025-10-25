#include<iostream>
using namespace std;

void merge(int arr[],int st,int mid,int end)
{
   int size= end-st+1;
   int temp[size];//create an array to temperatory store the sorted array value
   int i=st;
   int j=mid+1;
   int count=0;
   while(i<=mid && j<=end)
   {
      if(arr[i]<=arr[j])
      {
         temp[count]=arr[i];
         i++;
      }
      else{
         temp[count]=arr[j];
         j++;
      }
      count++;
   }
   //for remaining left side of elements
   while(i<=mid)
   {
      temp[count]=arr[i];
      i++;
      count++;
   }
   //for remaining left side of elements
   while(j<=end)
   {
      temp[count]=arr[j];
      j++;
      count++;
   }

   //storing the elements to the orignal array
   for (int idx = 0; idx < size; idx++)
   {
      arr[idx+st]=temp[idx];

   }
   

}

void mergeSort(int arr[],int st,int end)
{
   if(st<end)
   {
      int mid=st+(end-st)/2;
      //mergesort forthe left half
      mergeSort(arr,st,mid);
      //mergesort for the right half of the array
      mergeSort(arr,mid+1,end);

      merge(arr,st,mid,end);
   }
}

int main()
{
 int arr[6]={23,45,2,67,34,89};
 int n = 6;
    
    cout << "Original array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    mergeSort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
 return 0;
}