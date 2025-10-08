#include <iostream>
using namespace std;
void print(int arr[], int size) // print the dynamic array
{
    for (int j = 0; j < size; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
}
void reverse(int arr[], int size) //reverse array and swap it
{
    for (int i = 0; i < size; i++, size--)
    {
        swap(arr[i], arr[size - 1]);
    }
}

int main()
{
    int size;
    cout << "size of dynamic arr : ";
    cin >> size;
    int *dray = new int[size];
    for (int i = 0; i < size; i++)
    {
        dray[i] = i + 1;
    }
    print(dray, size);
    reverse(dray, size);
    print(dray, size);

    delete[] dray;
    return 0;
}
