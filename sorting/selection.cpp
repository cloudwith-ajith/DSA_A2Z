#include<bits/stdc++.h>
using namespace std;
// selection sort
int main(){
    
    int arr[8] = {1,46,24,52,20,9,2,13};
    int small = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n ; i++){
        for(int j = i ; j < n; j++){
            if(arr[j] < arr[small]){
                small = j;
            }
        }
        swap(arr[i],arr[small]);
        small = small + 1;
    }
    
    for(int x : arr){
        cout<<x<<" ";
    }
    
    return 0;
}
