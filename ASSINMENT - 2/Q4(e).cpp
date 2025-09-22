#include <iostream>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    int n = str.length();
    for (int i = 0; i < n; i++)
    {

        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }
    cout << str;
}