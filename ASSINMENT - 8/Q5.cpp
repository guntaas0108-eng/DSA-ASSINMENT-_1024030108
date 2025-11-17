#include <iostream>
#include <utility> 
#include <cstring> 
using namespace std;

void printArray(int arr[], int size) {
    cout << "  ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;  
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void heapSort_Increasing(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;    
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}


void heapSort_Decreasing(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

int main() {
    int original_arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(original_arr) / sizeof(original_arr[0]);
    int* arr = new int[n];

    memcpy(arr, original_arr, n * sizeof(int));
    cout << "--- Heapsort (Increasing Order) ---" << endl;
    cout << "Original array:" << endl;
    printArray(arr, n);
    
    heapSort_Increasing(arr, n);
    
    cout << "Sorted array (increasing):" << endl;
    printArray(arr, n);

    cout << "\n-------------------------------------\n" << endl;

    memcpy(arr, original_arr, n * sizeof(int));
    cout << "--- Heapsort (Decreasing Order) ---" << endl;
    cout << "Original array:" << endl;
    printArray(arr, n);
    
    heapSort_Decreasing(arr, n);
    
    cout << "Sorted array (decreasing):" << endl;
    printArray(arr, n);
    
    delete[] arr;
    return 0;
}