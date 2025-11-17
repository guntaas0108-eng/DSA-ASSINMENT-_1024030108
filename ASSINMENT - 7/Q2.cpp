#include <iostream>
#include <utility> 
using namespace std;

void printArray(int arr[], int size) {
    cout << "  ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void improvedSelectionSort(int arr[], int n) {

    for (int i = 0; i < n / 2; i++) {
        
        int left = i;          
        int right = n - 1 - i; 
        
        int min_idx = left;
        int max_idx = left;

 
        for (int j = left; j <= right; j++) {
            
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
          
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }

        // --- Perform Swaps ---

        swap(arr[left], arr[min_idx]);

        if (max_idx == left) {
            max_idx = min_idx;
        }
        swap(arr[right], arr[max_idx]);
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "--- Improved Selection Sort (Min-Max Sort) ---" << endl;
    cout << "Original array:" << endl;
    printArray(arr, n);

    improvedSelectionSort(arr, n);

    cout << "\nSorted array:" << endl;
    printArray(arr, n);

    cout << "\n------------------------------------------------\n" << endl;

    int arr2[] = {9, 2, 7, 1, 5, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Original array 2:" << endl;
    printArray(arr2, n2);

    improvedSelectionSort(arr2, n2);

    cout << "\nSorted array 2:" << endl;
    printArray(arr2, n2);

    return 0;
}