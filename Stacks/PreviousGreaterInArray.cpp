#include <iostream>
using namespace std;

void prevGreater(int Arr[], int size){
    int i,j;
    for(i = 0; i < size; i++){
        bool flag = false;
        for(j = i - 1; j >= 0; j--){
            if(Arr[i] < Arr[j]){
                cout << Arr[j] << " ";
                flag = true;
                break;
            }
        }
        if(flag == false){
            cout << "- " ;
        }
    }
}

int main()
{
    int arr[] = {23,64,31,64,87,15,84,46,83,82,15,65,23,68,27,83,14};
    int n;
    n = sizeof(arr)/sizeof(arr[0]);
    prevGreater(arr,n);

    return 0;
}