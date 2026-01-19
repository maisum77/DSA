#include<iostream>
using namespace std;

void heapyfiy(int arr[],int index, int n)
{
    int largest=index;
    int left=2*index+1;
    int right=2*index+2;

    if(left<n && arr[left]>arr[largest]) // it is a max heap if want to make min heap change the sighn to less then to 
    {
        largest=left;
    }
    if(right<n && arr[right]>arr[largest])
    {
        largest=right;
    }
    
    if (largest!=index)
    {
        swap(arr[largest],arr[index]);
        heapyfiy(arr,largest,n);
    }
    
    
}

void BuildHeap(int arr[],int n)
{
    for (int i = n/2-1; i >= 0; i--)
    {
        heapyfiy(arr,i,n);
    }
    
}

void printheap(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}


int main()
{
    int arr[]={10,3,8,9,5,13,18,14,11,70};
    BuildHeap(arr,10);
    printheap(arr,10);
}