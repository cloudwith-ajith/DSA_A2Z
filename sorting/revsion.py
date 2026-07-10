#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int arr[6] = {7,12,9,11,13,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = n-1; i >= 0 ; i--){
        for(int j  = 0; j <= i-1; j++){
            if(arr[j] > arr[j +1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    
    for(int i : arr){
        cout<<i<<" ";
    }
    
    return 0;
}
