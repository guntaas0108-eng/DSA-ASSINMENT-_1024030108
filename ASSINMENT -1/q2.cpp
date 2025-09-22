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
for (int i = 0; i < n; i++)
{
    for (int j = i + 1; j < n; j++)
    {
        if (arr[j] == arr[i])
        {
            arr[j] = -99999;
        }
    }
}
for (int i = 0; i < n; i++)
{
    if (arr[i] != -99999)
    {
        cout << arr[i] << " ";
    }
}
