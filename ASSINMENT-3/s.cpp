#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if parentheses are balanced
bool areParenthesesBalanced(const string& expr) {
    stack<char> s; // Create a stack to store opening parentheses

    for (char ch : expr) { // Iterate through the expression
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch); // If it's an opening parenthesis, push it onto the stack
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty()) {
                return false; // If a closing parenthesis appears without a matching opening one, it's unbalanced
            }
            char top = s.top(); // Get the top element of the stack
            s.pop(); // Pop the top element

            // Check for matching pairs
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false; // If the closing parenthesis doesn't match the top of the stack, it's unbalanced
            }
        }
    }
    return s.empty(); // If the stack is empty at the end, all parentheses are balanced
}

int main() {
    string expr1 = "{[()]}";
    string expr2 = "{[(])}";
    string expr3 = "((()))";
    string expr4 = "(()";

    cout << expr1 << " is balanced: " << (areParenthesesBalanced(expr1) ? "Yes" : "No") << endl;
    cout << expr2 << " is balanced: " << (areParenthesesBalanced(expr2) ? "Yes" : "No") << endl;
    cout << expr3 << " is balanced: " << (areParenthesesBalanced(expr3) ? "Yes" : "No") << endl;
    cout << expr4 << " is balanced: " << (areParenthesesBalanced(expr4) ? "Yes" : "No") << endl;

    return 0;
}