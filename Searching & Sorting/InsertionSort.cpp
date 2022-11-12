#include <iostream>
using namespace std;

void display(int Arr[], int size){
    int i;
    for(int i = 0; i < size; i++){
        cout << Arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {23,64,23,75,24,76,87,22,54,76,43,76,97,21,64,27};
    int n;
    n = sizeof(arr)/sizeof(arr[0]);
    int i,j,target;
    
    display(arr,n);
    
    for(i = 1; i < n; i++){
        target = arr[i];
        j = i - 1;
        while(target <= arr[j] && j >= 0){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = target;
    }
    
    display(arr,n);

    return 0;
}