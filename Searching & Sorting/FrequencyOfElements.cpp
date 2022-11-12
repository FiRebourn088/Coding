#include <iostream>
using namespace std;

void countFrequency(int Arr[], int size){
    int i,j,count;
    bool flag;
    for(i = 0; i < size; i++){
        flag = false;
        count = 0;
        for(j = i + 1; j < size; j++){
            if(Arr[i] == Arr[j]){
                flag = true;
                break;
            }
        }
        
        if(flag == true){
            continue;
        }
        
        for(j = 0; j <= i; j++){
            if(Arr[i] == Arr[j]){
                count++;
            }
        }
        
        cout << Arr[i] << ":" << count << endl;
    }
}

int main()
{
    int arr[] = {1,5,2,6,6,6,7,3,6,4,8,9,3,2};
    int n;
    n = sizeof(arr)/sizeof(arr[0]);
    countFrequency(arr,n);
    return 0;
}
