#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    string originalString = "DataStructure";
    stack<char> charstack;

    for(char c: originalString){
        charstack.push(c);
    }

    string reversedString = " ";

    while(!charstack.empty()){
        reversedString += charstack.top();
        charstack.pop();
    }
    cout << "Original string :" << originalString;
    cout << "reversed string :" << reversedString;
    
    return 0;
}