#include <iostream>
#include <algorithm> // For swap
using namespace std;

// This directive brings all names from the std namespace 
// into the current scope.

// Utility function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// --- Bubble Sort Function ---
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // No std:: needed for swap
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// --- Insertion Sort Function ---
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// --- Selection Sort Function ---
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            // No std:: needed for swap
            swap(arr[min_idx], arr[i]);
        }
    }
}

// --- Main function to test the sorts ---
int main() {
    // --- Test Bubble Sort ---
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    // No std:: needed for cout or endl
    cout << "--- Bubble Sort ---" << endl;
    cout << "Original array: ";
    printArray(arr1, n1);
    
    bubbleSort(arr1, n1);
    
    cout << "Sorted array:   ";
    printArray(arr1, n1);
    cout << endl;

    // --- Test Insertion Sort ---
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    cout << "--- Insertion Sort ---" << endl;
    cout << "Original array: ";
    printArray(arr2, n2);
    
    insertionSort(arr2, n2);
    
    cout << "Sorted array:   ";
    printArray(arr2, n2);
    cout << endl;

    // --- Test Selection Sort ---
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    
    cout << "--- Selection Sort ---" << endl;
    cout << "Original array: ";
    printArray(arr3, n3);
    
    selectionSort(arr3, n3);
    
    cout << "Sorted array:   ";
    printArray(arr3, n3);

    return 0;
}