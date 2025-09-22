#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    char ch;
    cin >> ch;
    while (ch != 'E')
    {
        switch (ch)
        {
        case 'C':
        { // C means create an array
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            break;
        }
        case 'D':
        { // D means display an array
            for (int i = 0; i < n; i++)
            {
                cout << arr[i];
            }
            break;
        }
        case 'I':
        { // I means insert an element in an array
            int element, k;
            cin >> element >> k;
            for (int i = n - 1; i >= k; i--)
            {
                arr[i + 1] = arr[i];
            }
            arr[k] = element;
            n++;
        }
        break;
        case 'R':
        { // R means remover an element from an array
            int z;
            cin >> z;
            for (int i = z; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            n--;
        }
        break;
        case 'L':
        { // L means linear search
            int s;
            cin >> s;
            bool flag = false;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == s)
                {
                    flag = true;
                    cout << "Element found";
                }
            }
            if (flag == false)
            {
                cout << "Element not found";
            }
            break;
        }
        case 'E':
        { // E means exiting
            break;
        }
        default:
        {
            cout << "This code is invalid";
        }
        }
        cin >> ch;
    }
}