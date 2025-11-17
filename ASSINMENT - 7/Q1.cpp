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

void resetArray(int original[], int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = original[i];
    }
}


// --- 1. Selection Sort ---

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        if (min_idx != i) {
            swap(arr[min_idx], arr[i]);
        }
    }
}


// --- 2. Insertion Sort ---

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; 
        int j = i - 1;    
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; 
    }
}


// --- 3. Bubble Sort ---

void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
  
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }
}


// --- 4. Merge Sort ---

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; 
    int n2 = right - mid;   

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0; 
    int j = 0; 
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return; 
    }
    
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


// --- 5. Quick Sort ---

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
      
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int original_arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(original_arr) / sizeof(original_arr[0]);
    
    int* arr_copy = new int[n];
    
    // --- 1. Selection Sort ---
    resetArray(original_arr, arr_copy, n);
    cout << "a. Selection Sort" << endl;
    cout << "Original:" << endl;
    printArray(arr_copy, n);
    selectionSort(arr_copy, n);
    cout << "Sorted:" << endl;
    printArray(arr_copy, n);
    cout << "--------------------------------" << endl;

    // --- 2. Insertion Sort ---
    resetArray(original_arr, arr_copy, n);
    cout << "b. Insertion Sort" << endl;
    cout << "Original:" << endl;
    printArray(arr_copy, n);
    insertionSort(arr_copy, n);
    cout << "Sorted:" << endl;
    printArray(arr_copy, n);
    cout << "--------------------------------" << endl;

    // --- 3. Bubble Sort ---
    resetArray(original_arr, arr_copy, n);
    cout << "c. Bubble Sort" << endl;
    cout << "Original:" << endl;
    printArray(arr_copy, n);
    bubbleSort(arr_copy, n);
    cout << "Sorted:" << endl;
    printArray(arr_copy, n);
    cout << "--------------------------------" << endl;

    // --- 4. Merge Sort ---
    resetArray(original_arr, arr_copy, n);
    cout << "d. Merge Sort" << endl;
    cout << "Original:" << endl;
    printArray(arr_copy, n);
    mergeSort(arr_copy, 0, n - 1); // Note: 0 and n-1
    cout << "Sorted:" << endl;
    printArray(arr_copy, n);
    cout << "--------------------------------" << endl;

    // --- 5. Quick Sort ---
    resetArray(original_arr, arr_copy, n);
    cout << "e. Quick Sort" << endl;
    cout << "Original:" << endl;
    printArray(arr_copy, n);
    quickSort(arr_copy, 0, n - 1); // Note: 0 and n-1
    cout << "Sorted:" << endl;
    printArray(arr_copy, n);
    cout << "--------------------------------" << endl;

    delete[] arr_copy;
    return 0;
}