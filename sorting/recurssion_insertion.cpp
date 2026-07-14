#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int arr[6] = {13,46,24,52,20,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    for(int i = 0; i < n; i++){
        int j = i;
        while ( j != 0 && arr[j-1] > arr[j] ){
            swap(arr[j-1],arr[j]);
            j--;
        }
        
    }
    
    for(int i : arr){
        cout<<i<<" ";
    }

    return 0;
}
