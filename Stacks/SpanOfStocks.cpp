#include<bits/stdc++.h>
using namespace std;

void spanStock(int Arr[], int size){
    for(int i = 0; i < size; i++){
        int count = 1;
        for(int j = i - 1; j >= 0 && Arr[j] <= Arr[i]; j--){
            count++;
        }
        cout << count << " ";
    }
}

int main(){
    int arr[] = {32,65,13,75,23,12,65,86,23,64,23,65,86,23};
    int n;
    n = sizeof(arr)/sizeof(arr[0]);
    spanStock(arr,n);
    return 0;
}
