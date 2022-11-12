#include <bits/stdc++.h>
using namespace std;

int maxArea(int Arr[], int size){
    int res = 0;
    int prevSmaller[size], nextSmaller[size];
    stack<int> s;
    s.push(0);
    //1,6,3,9,4,7,3,6,6,2,9,3,6,4,6,8,3,5,4,8,6,3
    for(int i = 0; i < size; i++){
        while(s.empty() == false && Arr[i] <= Arr[s.top()]){    
            s.pop();
        }
        int prevSmallerCurr = s.empty() ? -1 : s.top();
        prevSmaller[i] = prevSmallerCurr;
        s.push(i);
    }
    
    while(s.empty() == false){
        s.pop();
    }
    
    s.push(size-1);
    for(int i = size - 1; i >= 0; i--){
        while(s.empty() == false && Arr[i] <= Arr[s.top()]){
            s.pop();
        }
        int nextSmallerCurr = s.empty() ? size : s.top();
        nextSmaller[i] = nextSmallerCurr;
        s.push(i);
    }
    
    for(int i = 0; i < size; i++){
        int temp = Arr[i];
        temp += (i - prevSmaller[i] - 1) * Arr[i];
        temp += (nextSmaller[i] - i - 1) * Arr[i];
        res = max(res, temp);
    }
    return res;
}

int main()
{
    int arr[] = {1,6,3,9,4,7,3,6,6,2,9,3,6,4,6,8,3,5,4,8,6,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Max Area is: " << maxArea(arr,n);

    return 0;
}
