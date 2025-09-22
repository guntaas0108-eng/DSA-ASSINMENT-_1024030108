#include <iostream>
using namespace std;
int main()
{
    int n1, m1, n2, m2;
    cin >> n1 >> m1 >> n2 >> m2;
    int arr1[n1][m1];
    int arr2[n2][m2];
    int res[n1][m2];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            cin >> arr1[i][j];
        }
    }
    cout << endl;
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cin >> arr2[i][j];
        }
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < m1; k++)
            {
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    cout << endl;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}