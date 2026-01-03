#include <iostream>
using namespace std;

void fix(int a[], int n, int i) {
    int mx = i, l = 2*i+1, r = 2*i+2;
    if (l < n && a[l] > a[mx]) mx = l;
    if (r < n && a[r] > a[mx]) mx = r;
    if (mx != i) { swap(a[i], a[mx]); fix(a, n, mx); }
}

void heapSort(int a[], int n) {
    for (int i = n/2-1; i >= 0; i--) fix(a, n, i); // Build Heap
    for (int i = n-1; i > 0; i--) {
        swap(a[0], a[i]); // Put largest at end
        fix(a, i, 0);     // Fix remaining
    }
}
int main()
{
    int data[] = {45, 10, 75, 20, 50};
    int n = sizeof(data)/sizeof(data[0]);
    heapSort(data, n);
    cout << "Sorted Data: ";
    for(int i=0; i<n; i++) 
    cout << data[i] << " "<< "\n";
}