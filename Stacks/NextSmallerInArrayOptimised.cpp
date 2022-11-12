#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(int Arr[], int size){
    vector<int> v;
    stack<int> s;
    v.push_back(INT_MIN);
    s.push(Arr[size - 1]);
    
    for(int i = size - 2; i >= 0; i--){
        while(s.empty() == false && Arr[i] <= s.top()){
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
    int arr[] = {32,52,27,15,83,43,74,26,84,23,65,86,24,83,91,32,64,84,24};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int x : nextSmaller(arr,n)){
        if(x == INT_MIN){
            cout << "- ";
        }else
            cout << x << " ";
    }

    return 0;
}