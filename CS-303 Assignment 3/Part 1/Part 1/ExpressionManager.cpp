#include "ExpressionManager.h"
#include <stack>
#include <iostream>
using namespace std;

/*
  Takes a string expression and checks if the parentheses
  in the expression are balanced, i.e., each opening parenthesis has a
  corresponding closing parenthesis. It does this by using a stack to
  keep track of the opening parentheses encountered and checking if each
  closing parenthesis matches the last opening parenthesis encountered.
*/
bool ExpressionManager::isBalanced(const string& expression) {
    stack<char> s;
    for (char c : expression) {
        if (isOpeningParenthesis(c)) {
            s.push(c);
        }
        else if (isClosingParenthesis(c)) {
            if (s.empty()) {
                return false;
            }
            char top = s.top();
            s.pop();
            if ((c == '}' && top != '{') ||
                (c == ')' && top != '(') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();
}

/*
  Takes an infix expression as a string and converts it to
  postfix notation. It does this by using a stack to keep track of
  operators encountered and their precedence, and adding them to the
  postfix expression in the correct order.
*/
string ExpressionManager::infixToPostfix(const string& infixExpression) {
    stack<char> s;
    string postfixExpression = "";
    for (char c : infixExpression) {
        if (c >= '0' && c <= '9') {
            postfixExpression += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfixExpression += s.top();
                s.pop();
            }
            s.pop();
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {
            while (!s.empty() && getPrecedence(c) <= getPrecedence(s.top())) {
                postfixExpression += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfixExpression += s.top();
        s.pop();
    }
    return postfixExpression;
}

// Takes a character c and returns true if it is an opening parenthesis.
bool ExpressionManager::isOpeningParenthesis(char c) {
    return c == '{' || c == '(' || c == '[';
}

// Takes a character c and returns true if it is a closing parenthesis.
bool ExpressionManager::isClosingParenthesis(char c) {
    return c == '}' || c == ')' || c == ']';
}

/*
  Takes a character c representing an operator and returns its precedence
  level. Operators with higher precedence should be evaluated before
  operators with lower precedence.
*/
int ExpressionManager::getPrecedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }

    if (c == '*' || c == '/' || c == '%') {
        return 2;
    }
    return 0;
}