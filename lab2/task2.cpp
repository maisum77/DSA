#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "size of dynamic arr : ";
    cin >> size;
    int *dray = new int[size]; // declaring dynamic array
    for (int i = 0; i < size; i++)
    {
        dray[i] = i * 2; //storing multiple of 2 in array
    }
    for (int j = 0; j < size; j++)
    {
        cout << dray[j] << " ";
    }
    delete [] dray;//delete the data from it
    return 0;
}