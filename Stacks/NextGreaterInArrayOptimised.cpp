#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(int Arr[], int size){
    vector<int> v;
    stack<int> s;
    s.push(Arr[size - 1]);
    v.push_back(INT_MIN);
    
    for(int i = size - 2; i >= 0; i--){
        while(s.empty() == false && s.top() <= Arr[i]){
            s.pop();
        }
        int res = s.empty() ? INT_MIN : s.top();
        v.push_back(res);
        s.push(Arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}

int main()
{
    int arr[] = {23,52,72,31,63,85,14,74,24,57,91};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int x : nextGreater(arr, n)){
        if(x == INT_MIN){
            cout << "- ";
        }else
            cout << x << " ";
    }

    return 0;
}
