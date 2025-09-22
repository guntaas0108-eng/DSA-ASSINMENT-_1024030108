#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int k = 0; k < (n / 2); k++)
    {
        int temp = arr[k];
        arr[k] = arr[n - k - 1];
        arr[n - k - 1] = temp;
    }
    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
}