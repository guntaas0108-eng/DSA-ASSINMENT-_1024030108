#include <iostream>
using namespace std;

int main()
{
    int arr[5];
    int front = -1, rear = -1;
    int choice = 0, val;

    while (choice != 5)
    {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Enqueue
            if ((rear + 1) % 5 == front)
            {
                cout << "Queue Full" << endl;
            }
            else
            {
                cout << "Enter value to enqueue: ";
                cin >> val;
                if (front == -1)
                    front = 0;
                rear = (rear + 1) % 5;
                arr[rear] = val;
                cout << val << " enqueued." << endl;
            }
            break;

        case 2: // Dequeue
            if (front == -1)
            {
                cout << "Queue Empty" << endl;
            }
            else
            {
                cout << "Dequeued: " << arr[front] << endl;
                if (front == rear)
                {
                    front = rear = -1;
                }
                else
                {
                    front = (front + 1) % 5;
                }
            }
            break;

        case 3: // Display
            if (front == -1)
            {
                cout << "Queue Empty" << endl;
            }
            else
            {
                cout << "Queue: ";
                int i = front;
                while (true)
                {
                    cout << arr[i] << " ";
                    if (i == rear)
                        break;
                    i = (i + 1) % 5;
                }
                cout << endl;
            }
            break;

        case 4: // Peek
            if (front == -1)
            {
                cout << "Queue Empty" << endl;
            }
            else
            {
                cout << "Front element: " << arr[front] << endl;
            }
            break;

        case 5: // Exit
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}