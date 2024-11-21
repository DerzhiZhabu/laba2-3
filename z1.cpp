#include "steck.h"

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Функция для определения приоритета оператора
int getPriority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}


bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string infixToPostfix(const string& infix) {
    Stack<char> st;
    string postfix;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        }
        
        else if (c == '(') {
            st.push(c);
        }
        
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); 
        }
        
        else if (isOperator(c)) {
            while (!st.empty() && getPriority(st.top()) >= getPriority(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Введите инфиксное выражение: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Постфиксная запись: " << postfix << endl;

    return 0;
}
