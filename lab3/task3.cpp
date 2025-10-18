#include <iostream>
#include <cstdlib>
using namespace std;

void printArray(int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", "; 
        }
    }
    cout << "]" << endl;
}

void selectionSort(int arr[], int size) {
    int swapCount = 0;

    for (int i = 0; i < size - 1; i++) {
        
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; 
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            
            swapCount++;
        }
    }
    cout << "Selection Sort: " << swapCount << " swaps performed." << endl;
}

void insertionSort(int arr[], int size) {
    int swapCount = 0;

    
    for (int i = 1; i < size; i++) {
        int j = i; 
        while (j > 0 && arr[j] < arr[j - 1]) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            swapCount++;
            j--;
        }
    }
    cout << "Insertion Sort: " << swapCount << " swaps performed." << endl;
}
int main() {

    int SIZE = 10;
    int originalArray[SIZE];
    int arrForSelection[SIZE]; 
    int arrForInsertion[SIZE]; 

    
    for (int i = 0; i < SIZE; ++i) {
        originalArray[i] = rand() % 100 + 1;
    }
    for (int i = 0; i < SIZE; ++i) {
        arrForSelection[i] = originalArray[i];
        arrForInsertion[i] = originalArray[i];
    }

    // Print the starting array
    cout << "------------------------------------------" << endl;
    cout << "Original Array: ";
    printArray(originalArray, SIZE);
    cout << "------------------------------------------" << endl;

    cout << "Selection Sort:" << endl;
    selectionSort(arrForSelection, SIZE);
    cout << "Sorted Array:   ";
    printArray(arrForSelection, SIZE);
    cout << "------------------------------------------" << endl;

    
    cout << "Insertion Sort:" << endl;
    insertionSort(arrForInsertion, SIZE);
    cout << "Sorted Array:   ";
    printArray(arrForInsertion, SIZE);
    cout << "------------------------------------------" << endl;

    return 0;
}