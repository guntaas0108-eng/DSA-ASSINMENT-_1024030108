#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1;
    getline(cin, str1);
    string str2;
    getline(cin, str2);
    string res;
    res = str1 + str2;
    cout << "Concatenated string is " << res;
}