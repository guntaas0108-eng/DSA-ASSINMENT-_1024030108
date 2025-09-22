#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements (even): ";
    cin >> n;

    if (n % 2 != 0)
    {
        cout << "Queue size must be even!" << endl;
        return 0;
    }

    int arr[100];
    int firstHalf[50];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int half = n / 2;
    for (int i = 0; i < half; i++)
    {
        firstHalf[i] = arr[i];
    }

    int index = 0, fh_index = 0, second_index = half;
    while (fh_index < half)
    {
        arr[index] = firstHalf[fh_index];
        index++;
        fh_index++;

        arr[index] = arr[second_index];
        index++;
        second_index++;
    }
    cout << "Output: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}