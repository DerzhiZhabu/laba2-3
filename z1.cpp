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

// Функция для проверки, является ли символ оператором
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Функция для преобразования инфиксного выражения в постфиксное
string infixToPostfix(const string& infix) {
    Stack<char> st;
    string postfix;

    for (char c : infix) {
        // Если символ - операнд (буква или цифра), добавляем его к результату
        if (isalnum(c)) {
            postfix += c;
        }
        // Если символ - открывающая скобка, кладём её в стек
        else if (c == '(') {
            st.push(c);
        }
        // Если символ - закрывающая скобка, извлекаем операторы из стека до открывающей скобки
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();  // Удаляем открывающую скобку
        }
        // Если символ - оператор
        else if (isOperator(c)) {
            while (!st.empty() && getPriority(st.top()) >= getPriority(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Извлекаем все оставшиеся операторы из стека
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
