#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int checkIfOperand(char ch){
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch){
    switch(ch){
        case '+':
        case '-':
            return 1;
        case '/':
        case '*':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

int convertInfixToPostfix(char* expression){
    int i,j;
    stack<char> s;
    
    for(i = 0, j = -1; expression[i]; ++i){
        if(checkIfOperand(expression[i])){
            expression[++j] = expression[i];
        }
        else if(expression[i] == '('){
            s.push(expression[i]);
        }
        else if(expression[i] == ')'){
            while(!s.empty() && s.top() != '('){
                expression[++j] = s.top();
                s.pop();
            }
            if(!s.empty() && s.top() != '('){
                return -1;
            }
            else
                s.pop();
        }
        else{
            while(!s.empty() && precedence(expression[i]) <= precedence(s.top())){
                expression[++j] = s.top();
                s.pop();
            }
            s.push(expression[i]);
        }
    }
    
    while(!s.empty()){
        expression[++j] = s.top();
        s.pop();
    }
    
    expression[++j] ='\0';
    cout << expression;
}

int main()
{
    char expression[] = "a+b*(c^d-e)^(f+g*h)-i";
    convertInfixToPostfix(expression);
    return 0;
}
