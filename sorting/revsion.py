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

-------------------------------------------------------
#insertion sort
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[5] = {7,12,9,11,3};
    int n  = sizeof(arr)/sizeof(arr[0]);
    
    for(int i = 0; i <= n-1; i++){
        int j = i;
        while(j > 0 && arr[j-1] > arr[j] ){
            swap(arr[j-1],arr[j]);
            j--;
        }
    
    }
    
    for(int i : arr) cout<<i<<" ";
    return 0;
}
