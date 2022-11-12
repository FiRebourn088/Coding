#include<bits/stdc++.h>
using namespace std;

void spanStock(int Arr[], int size){
    stack<int> s;
    cout << 1 << " ";
    s.push(0);
    
    for(int i = 1; i < size; i++){
        while(s.empty() == false && Arr[s.top()] <= Arr[i]){
            s.pop();
        }
        int span = s.empty() ? i + 1: i - s.top();
        cout << span << " ";
        s.push(i);
    }
}

int main()
{
    int arr[] = {23,53,12,54,87,34,76,45,23,65,87,45,23,89,8,65,90};
    int n;
    n = sizeof(arr)/sizeof(arr[0]);
    spanStock(arr,n);

    return 0;
}

