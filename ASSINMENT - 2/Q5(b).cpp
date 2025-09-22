#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;

    int mainDiag[n];
    int upperDiag[n-1];
    int lowerDiag[n-1];

    for (int i = 0; i < n; i++)
    {
        cin >> mainDiag[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> upperDiag[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> lowerDiag[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << mainDiag[i] << " ";
            else if (i == j - 1)
                cout << upperDiag[i] << " ";
            else if (i == j + 1)
                cout << lowerDiag[j] << " ";
            else
                cout <<0<<" ";
        }
        cout << endl;
    }
}