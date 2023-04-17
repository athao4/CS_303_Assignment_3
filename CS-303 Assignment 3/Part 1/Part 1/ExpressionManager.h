#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H

#include <string>
using namespace std;

class ExpressionManager {
public:
	// Check whether the given string is a balanced expression.
	static bool isBalanced(const string& expression);
	// Convert infix to postfix expression.
	static string infixToPostfix(const string& infixExpression);

private:
	// Check whether the character has opening parenthesis, bracket, or brace.
	static bool isOpeningParenthesis(char c);
	// Check whether the character has closing parenthesis, bracket, or brace.
	static bool isClosingParenthesis(char c);
	// Return the precedence level of the operator represented by the character.
	static int getPrecedence(char c);
};

#endif 
