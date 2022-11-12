#include <bits/stdc++.h>
using namespace std;

void prevSmaller(int Arr[], int size){
    stack<int> s;
    
    s.push(Arr[0]);
    cout << "- ";
    
    for(int i = 1; i < size; i++){
        while(s.empty() == false && Arr[i] <= s.top()){
            s.pop();
        }
        if(s.empty()){
            cout << "- ";
        }else
            cout << s.top() << " ";
        s.push(Arr[i]);
    }
}

int main()
{
    int arr[] = {12,66,73,26,74,24,94,26,84,53,87,54,52,83,99};
    int n = sizeof(arr)/sizeof(arr[0]);
    prevSmaller(arr,n);

    return 0;
}
