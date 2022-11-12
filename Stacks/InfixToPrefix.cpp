// Using strings
#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

string infixToPostfix(string infix)
{
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> char_stack;
    string output;

    for (int i = 0; i < l; i++) {


        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];

        else if (infix[i] == '(')
            char_stack.push('(');


        else if (infix[i] == ')') {
            while (char_stack.top() != '(') {
                output += char_stack.top();
                char_stack.pop();
            }

            char_stack.pop();
        }

        else
        {
            if (isOperator(char_stack.top()))
            {
                if (infix[i] == '^')
                {
                    while (precedence(infix[i]) <= precedence(char_stack.top()))
                    {
                        output += char_stack.top();
                        char_stack.pop();
                    }

                }
                else
                {
                    while (precedence(infix[i]) <= precedence(char_stack.top()))
                    {
                        output += char_stack.top();
                        char_stack.pop();
                    }

                }

                char_stack.push(infix[i]);
            }
        }
    }
    return output;
}

string infixToPrefix(string expression)
{

    int l = expression.size();

    // Reverse expression
    reverse(expression.begin(), expression.end());

    // Replace ( with ) and vice versa
    for (int i = 0; i < l; i++) {

        if (expression[i] == '(') {
            expression[i] = ')';
            i++;
        }
        else if (expression[i] == ')') {
            expression[i] = '(';
            i++;
        }
    }

    string result = infixToPostfix(expression);

    // Reverse postfix
    reverse(result.begin(), result.end());

    return result;
}

// Driver code
int main()
{
    string s = ("a+b*(c^d-e)^(f+g*h)-i");
    cout << infixToPrefix(s) << std::endl;
    return 0;
}