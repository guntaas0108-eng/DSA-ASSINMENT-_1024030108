#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << endl;
    int sumr = 0;
    for (int i = 0; i < n; i++)
    {
        sumr = 0;
        for (int j = 0; j < m; j++)
        {
            sumr += arr[i][j];
        }
        cout << "Sum for row " << i << " is " << sumr;
        cout << endl;
    }
    cout << endl;
    int sumc = 0;
    for (int j = 0; j < m; j++)
    {
        sumc = 0;
        for (int i = 0; i < n; i++)
        {
            sumc += arr[i][j];
        }

        cout << "Sum for column " << j << " is " << sumc;
        cout << endl;
    }
}