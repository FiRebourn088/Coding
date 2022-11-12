#include<iostream>
using namespace std;

void mergeSort(int[],int,int); 
void merge(int[],int,int,int);

void printArray(int arr[], int size){
    int i;
    for(i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() 
{
    int array[]= {8, 4, 5, 1, 3, 9, 0, 2, 7, 6};
    int i; 

    int size = sizeof(array)/sizeof(array[0]);
    printArray(array, size);

    mergeSort(array, 0, size-1); 
    printArray(array, size);
}

void mergeSort(int a[], int left, int right)
{
    int mid;
    if(left < right)
    {
        // can also use mid = left + (right - left) / 2
        // this can avoid data type overflow
        mid = (left + right)/2;
        
        // recursive calls to sort first half and second half subarrays
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

void merge(int a[], int left, int mid, int right)
{
    int i = left; // starting index of left subarray
    int j = mid + 1; // starting index of right subarray
    int index = left; // used to place items in temp[]
    int temp[10];

    while(i<=mid && j<=right)
    {
        // place the smaller item at temp[index]
        if(a[i] < a[j]) { temp[index] = a[i]; i = i+1; } else { temp[index] = a[j]; j = j+1; } index++; } // i > mid would mean all items for left 
    // subarray were successfully placed, and there 
    // must be unplaced right subarray items
    if(i>mid)
    {
        while(j<=right)
        {
            temp[index] = a[j];
            index++;
            j++;
        }
    }
    // else all items of right subarray must have 
    // been placed and there must be 
    // unplaced items in the left-subarray
    else
    {
        while(i<=mid)
        {
            temp[index] = a[i];
            index++;
            i++;
        }
    }
    int p = left; // left index of subarray
    // by now index would have reached right 
    // most index of right subarray
    
    // placing all items of temp[] into actual array a[]
    while(p < index)
    {
        a[p]=temp[p];
        p++;
    }
}