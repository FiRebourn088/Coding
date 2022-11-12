#include <iostream>
using namespace std;

void nextGreater(int Arr[], int size){
    for(int i = 0; i < size; i++){
        bool flag = false;
        for(int j = i + 1; j < size; j++){
            if(Arr[i] < Arr[j]){
                cout << Arr[j] << " ";
                flag = true;
                break;
            }
        }
        if(flag == false){
            cout << "- ";
        }
    }
}

int main()
{
    int arr[] = {32,53,72,24,75,93,17,64,73,83,26,74,52,74,93};
    int n;
    n = sizeof(arr)/sizeof(arr[0]);
    nextGreater(arr,n);

    return 0;
}
