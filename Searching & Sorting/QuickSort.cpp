#include <bits/stdc++.h>
using namespace std;

void display(int Arr[],int size){
    for(int i = 0; i < size; i++){
        cout << Arr[i] << " ";
    }
    cout << endl;
}

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int Arr[],int low,int high){
    int pivot = Arr[high];
    int swapIndex = (low - 1);
    for(int j = low; j <= high - 1; j++){
        if(Arr[j] < pivot){
            swapIndex++;
            swap(&Arr[swapIndex],&Arr[j]);
        }
    }
    swap(&Arr[swapIndex+1],&Arr[high]);
    return (swapIndex+1);
}

void quickSort(int Arr[], int low, int high){
    if(low < high){
        int indexPI = partition(Arr,low,high);
        
        quickSort(Arr, low, indexPI - 1);
        quickSort(Arr, indexPI + 1, high);
    }
}

int main()
{
    int arr[] = {1,2,4,5,6,90,14,16,25,34,65,19,29,72};
    int n;
    n = sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    quickSort(arr,0,n-1);
    display(arr,n);
    return 0;
}

