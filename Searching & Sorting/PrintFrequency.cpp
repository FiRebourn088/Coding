#include <iostream>
using namespace std;

void printFrequency(int Arr[], int size){
    //Arr.sort()
    int i,count;
    i = 0;
    while(i < size){
        count = 1;
        
        while(i < size - 1 && Arr[i]==Arr[i + 1]){
            i++;
            count++;
        }
        cout << Arr[i] << ":" << count << endl; 
        i++;
    }
}

int main()
{
    int arr[] = {1,1,1,3,5,7,7,8,8,8,8,9,9,9};
    int n;
    n = sizeof(arr)/sizeof(arr[0]);
    printFrequency(arr,n);
    return 0;
}
