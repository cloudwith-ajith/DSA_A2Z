//-------brute force methoed----
#include<bits/stdc++.h>
using namespace std;

void rotate(int arr[],int k,int n ){
    int temp_arr[k];
    for(int i =0;i < k;i++){
        temp_arr[i] = arr[i];
    }
    
    for(int j = k; j < n;j++){
        arr[j - k] =arr[j];
    }
    int p = 0;
    for(int m = n-k; m < n; m++){
        arr[m] = temp_arr[p];
        p++;
    }
}


int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int k = 2;
    int n = size(arr);
    rotate(arr,k,n);
    
    for(int a : arr){
        cout<<a<<" ";
    }
    return 0;
}
