#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool areparenthsesBalanced(const string& expr){
    stack<char> s;

for (char ch: expr){
    if(ch == '(' || ch == '[' || ch == '{'){
        s.push(ch);
    }else if( ch == ')' || ch == ']' || ch == '}'){
        if(s.empty()){
            return false;
        }
        char top = s.top();
        s.pop();

        if ((ch == ')' && top!= '(') ||
            (ch == ']' && top!= '[') ||
            (ch == '}' && top!= '{')){
                return false;
            }
    }
}    
return 0;
}
int main(){
    string expr1 = "{[()]}";
     string expr2 = "{[(])}";
      string expr3 = "((()))";
       string expr4 = "())";
        
 cout<< expr1 << " is balanced :"<< (areparenthsesBalanced(expr1)? "yes" : "no")<< endl;
  cout<< expr2 << " is balanced :"<< (areparenthsesBalanced(expr2)? "yes" : "no")<< endl;
   cout<< expr3 << " is balanced :"<< (areparenthsesBalanced(expr3)? "yes" : "no")<< endl;
    cout<< expr4 << " is balanced :"<< (areparenthsesBalanced(expr4)? "yes" : "no")<< endl;

    return 0;
}