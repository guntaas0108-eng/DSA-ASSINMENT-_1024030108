#include <iostream>
using namespace std;

int main()
{
    int arr[5], front = -1, rear = -1;
    int choice = 0, val;

    while (choice != 5)
    {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (rear == 4)
            {
                cout << "Queue is Full" << endl;
            }
            else
            {
                cout << "Enter value to enqueue: ";
                cin >> val;
                if (front == -1)
                    front = 0;
                arr[++rear] = val;
                cout << val << " enqueued." << endl;
            }
            break;

        case 2: // Dequeue
            if (front == -1)
            {
                cout << "Queue is Empty" << endl;
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
                    front++;
                }
            }
            break;

        case 3: // Display
            if (front == -1)
            {
                cout << "Queue is Empty" << endl;
            }
            else
            {
                cout << "Queue: ";
                for (int i = front; i <= rear; i++)
                    cout << arr[i] << " ";
                cout << endl;
            }
            break;

        case 4: // Peek
            if (front == -1)
            {
                cout << "Queue is Empty" << endl;
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