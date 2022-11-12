#include <bits/stdc++.h>
using namespace std;

void prevGreater(int Arr[], int size){
    stack<int> s;
    s.push(Arr[0]);
    cout << "- ";
    
    for(int i = 1; i < size; i++){
        while(s.empty() == false && Arr[i] >= s.top()){
            s.pop();
        }
        if(s.empty()){
            cout << "- ";
        }else{
            cout << s.top() << " ";
        }
        s.push(Arr[i]);
    }
}

int main()
{
    int arr[] = {32,64,24,94,17,51,81,35,42,82,52,76};
    int n;
    n = sizeof(arr)/sizeof(arr[0]);
    prevGreater(arr,n);

    return 0;
}