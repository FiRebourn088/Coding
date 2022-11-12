#include <bits/stdc++.h>
using namespace std;

int maxArea(int Arr[], int size){
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
int main()
{
    int arr[] = {1,5,8,4,6,9,6,9,4,6,5,9,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Max Area is: " << maxArea(arr,n);

    return 0;
}
