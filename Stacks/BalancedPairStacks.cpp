#include<bits/stdc++.h>
using namespace std;

bool checkPair(char x, char y){
    return((x=='(' && y==')') || (x=='[' && y==']') || (x=='{' && y=='}'));
}

bool checkBalance(string expr){
    stack<char> s;
    for(int i=0; i<expr.length(); i++){
        if(expr[i]=='(' || expr[i]=='[' || expr[i]=='{'){
            s.push(expr[i]);
        }
        else{
            if(s.empty()){
                return false;
            }
            else if(checkPair(s.top(),expr[i])){
                s.pop();
                continue;
            }else{
                return false;
            }
        }
    }
    return s.empty();
}

int main(){
    string expr="{{{}}";
    checkBalance(expr)?cout << "Balanced" : cout << "Unbalanced";
    return 0;
}