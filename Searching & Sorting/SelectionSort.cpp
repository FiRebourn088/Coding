#include <iostream>
using namespace std;

void display(int Arr[], int size){
    int i;
    for(i = 0; i < size; i++){
        cout << Arr[i] << " ";
    }
    cout << endl;
}

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int arr[] = {32,65,23,87,34,94,16,48,26,69,42,97,73,28,94,53,85,42,75};
    int n;
    n = sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    int i,j,min,temp;
    for(i = 0; i < n - 1; i++){
        min = i;
        for(j = i + 1; j < n; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        swap(&arr[min],&arr[i]);
    }
    
    display(arr,n);

    return 0;
}