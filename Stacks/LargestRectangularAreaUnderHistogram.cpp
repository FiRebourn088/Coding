#include <iostream>
using namespace std;

int maxArea(int Arr[], int size){
    int res = 0;
    for(int i = 0; i < size; i++){
        int count = 1;
        for(int j = i + 1; j < size; j++){
            if(Arr[i] <= Arr[j]){
                count++;
            }else
                break;
        }
        
        for(int j = i - 1; j >= 0; j--){
            if(Arr[i] <= Arr[j]){
                count++;
            }else
                break;
        }
        int temp = count * Arr[i];
        res = max(res, temp);
    }
    return res;
}

int main()
{
    int arr[] = {1,6,7,3,5,8,6,4,6,3,7,6,3,5,7,5,3,6,9,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Max Area: " << maxArea(arr,n);

    return 0;
}