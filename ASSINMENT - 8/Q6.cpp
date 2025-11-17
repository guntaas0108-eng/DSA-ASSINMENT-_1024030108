#include <iostream>
#include <vector>    
#include <utility>   
#include <stdexcept> 
using namespace std;

class MaxPriorityQueue {
private:

    vector<int> heap;
    int parent(int i) { 
        return (i - 1) / 2; 
    }

    int leftChild(int i) { 
        return (2 * i) + 1; 
    }

    int rightChild(int i) { 
        return (2 * i) + 2; 
    }

    void heapifyUp(int i) {
        while (i > 0 && heap[i] > heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int maxIndex = i;
        int l = leftChild(i);
        int r = rightChild(i);
        int n = heap.size();

        if (l < n && heap[l] > heap[maxIndex]) {
            maxIndex = l;
        }

        if (r < n && heap[r] > heap[maxIndex]) {
            maxIndex = r;
        }

        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

public:
  
    void insert(int priority) {
        heap.push_back(priority);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (isEmpty()) {
            throw std::runtime_error("Priority queue is empty");
        }

        int maxElement = heap[0];

        heap[0] = heap.back();
        heap.pop_back(); 

        heapifyDown(0);

        return maxElement;
    }

    int getMax() {
        if (isEmpty()) {
            throw std::runtime_error("Priority queue is empty");
        }
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }

    int getSize() {
        return heap.size();
    }
};

int main() {
    MaxPriorityQueue pq;

    cout << "--- Priority Queue (using Max Heap) ---" << endl;
    pq.insert(30);
    pq.insert(10);
    pq.insert(50); 
    pq.insert(20);
    pq.insert(40);

    cout << "Queue size: " << pq.getSize() << endl;
    cout << "Current Max element (getMax): " << pq.getMax() << endl;
    cout << "\nExtracting elements in priority order:" << endl;
    cout << "  ";
    
    while (!pq.isEmpty()) {
        cout << pq.extractMax() << " ";
    }

    cout << endl;

    cout << "\nQueue is now empty: " << boolalpha << pq.isEmpty() << endl;
    try {
        pq.getMax();
    } catch (const std::runtime_error& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
    return 0;
}