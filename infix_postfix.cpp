#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char c) {
    if (c == '*' || c == '/')
        return 3;
    else if (c == '+' || c == '-')
        return 2;
    else if (c == '^')
        return 4;
    else if (c == '.')
        return 1;
    else
        return 0;
}


string infixToPostfix(const string& regex) {
    string postfix;
    stack<char> operators;

    for (char c : regex) {
        if (isalnum(c)) { // Operand
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Remove the '('
        } else { // Operator
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    string regex;
    cout << "Enter the regular expression: ";
    cin >> regex;

    string postfix = infixToPostfix(regex);
    cout << "Postfix notation: " << postfix << endl;

    return 0;
}