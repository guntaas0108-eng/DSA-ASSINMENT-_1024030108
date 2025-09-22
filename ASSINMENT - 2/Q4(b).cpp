#include <iostream>
using namespace std;
int main()
{
string str;
getline(cin, str);
int n = str.length();
int r = 0;
int l = n - 1;
while (r < l)
{
    char temp = str[r];
    str[r] = str[l];
    str[l] = temp;
    r++;
    l--;
}
cout << str;
}