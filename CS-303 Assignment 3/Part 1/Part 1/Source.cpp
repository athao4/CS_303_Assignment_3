// A Chao Thao
// CS-303 Assignment 3 Part 1
// April 17, 2023

#include <iostream>
using namespace std;
#include "ExpressionManager.h"

int main() {
    string infixExpression;
    // Ask user to enter an infix expresssion.
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    // Checks whether the entered infix expression is balanced or not.
    if (!ExpressionManager::isBalanced(infixExpression)) {
        cout << "Expression is Invalid!!" << endl;
        return 1;
    }

    // Converts the infix expression to postfix.
    string postfixExpression = ExpressionManager::infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}