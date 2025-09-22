#include <iostream>
using namespace std;

int main()
{
    string s;
    cout << "Enter string: ";
    cin >> s;

    char arr[100];
    int front = 0, rear = -1, size = 0;
    int freq[256] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        freq[ch]++;

        // enqueue
        if (size < 100)
        {
            rear = (rear + 1) % 100;
            arr[rear] = ch;
            size++;
        }

        while (size > 0 && freq[arr[front]] > 1)
        {
            front = (front + 1) % 100; // dequeue
            size--;
        }

        if (size == 0)
            cout << -1 << " ";
        else
            cout << arr[front] << " ";
    }

    cout << endl;
    return 0;
}