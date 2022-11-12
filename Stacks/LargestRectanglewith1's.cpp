#include <bits/stdc++.h>
using namespace std;

#define R 4
#define C 4

int largestHistRow(int Arr[], int size){
    stack<int> s;
    
    int res = 0;
    int top, curr;
    
    for(int i = 0; i < size; i++){
        while(s.empty() == false && Arr[s.top()] >= Arr[i]){
            top = s.top();
            s.pop();
            curr = Arr[top] * (s.empty() ? i : i - s.top() - 1);
            res = max(res, curr);
        }
        s.push(i);
    }
    
    while(s.empty() == false){
        top = s.top();
        s.pop();
        curr = Arr[top] * (s.empty() ? size : size - s.top() - 1);
        res = max(res, curr);
    }
    return res;
}

int maxArea(int Arr[][C]){
    int res = largestHistRow(Arr[0], C);
    
    for(int i = 1; i < R; i++){
        for(int j = 0; j < C; j++){
            if(Arr[i][j])
                Arr[i][j] += Arr[i - 1][j]; 
        }
        res = max(res, largestHistRow(Arr[i], C));
    }
    return res;
}

int main()
{
    int arr[][C] = {
        {0,1,1,0},
        {1,1,1,1},
        {1,1,1,1},
        {0,1,0,0}
    };
    
    cout << "Maximum rectangle is: " << maxArea(arr);

    return 0;
}