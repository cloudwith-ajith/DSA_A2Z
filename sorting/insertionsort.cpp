#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[5] ={5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i <= n-1; i++){
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
    
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}
