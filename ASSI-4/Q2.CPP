#include <iostream>

using namespace std;
#define MAX_SIZE 5
int circularQueue[MAX_SIZE];
int front = -1;
int rear = -1;  
bool isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1));
}

// Function to check if the circular queue is empty
bool isEmpty() {
    return front == -1;
}

// Function to add an element to the circular queue
void enqueue() {
    if (isFull()) {
        cout << "Circular Queue is full. Cannot enqueue." << endl;
    } else {
        int value;
        cout << "Enter the value to enqueue: ";
        cin >> value;
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        circularQueue[rear] = value;
        cout << value << " enqueued successfully." << endl;
    }
}

// Function to remove an element from the circular queue
void dequeue() {
    if (isEmpty()) {
        cout << "Circular Queue is empty. Cannot dequeue." << endl;
    } else {
        cout << "Dequeued element: " << circularQueue[front] << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
}

// Function to display the elements of the circular queue
void display() {
    if (isEmpty()) {
        cout << "Circular Queue is empty." << endl;
    } else {
        cout << "Elements in the circular queue are: ";
        int i = front;
        while (i != rear) {
            cout << circularQueue[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << circularQueue[i] << endl;
    }
}

// Function to get the front element without removing it
void peek() {
    if (isEmpty()) {
        cout << "Circular Queue is empty. No element to peek." << endl;
    } else {
        cout << "Front element is: " << circularQueue[front] << endl;
    }
}

// Main function to run the menu-driven program
int main() {
    int choice;
    do {
        cout << "\n--- Circular Queue Operations Menu ---" << endl;
        cout << "1. Enqueue (Add element)" << endl;
        cout << "2. Dequeue (Remove element)" << endl;
        cout << "3. Peek (Get front element)" << endl;
        cout << "4. Display (Show all elements)" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                if (isEmpty()) {
                    cout << "Circular Queue is empty." << endl;
                } else {
                    cout << "Circular Queue is not empty." << endl;
                }
                break;
            case 6:
                if (isFull()) {
                    cout << "Circular Queue is full." << endl;
                } else {
                    cout << "Circular Queue is not full." << endl;
                }
                break;
            case 7:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}