#include<bits/stdc++.h>
using namespace std;
//maximum subarray code
int max_subarray(int arr[],int n, int k){
    int sums = 0;
    // to calculate the k elements
    for(int i = 0 ;i < k; i++){
        sums += arr[i];
    }
    // assign the sum to the max_sub
    int max_sub = sums;
    //sliding the window
    for(int i = k; i < n; i++){
        sums = sums + arr[i]; //add the right one 
        sums = sums - arr[i - k]; // remove the left element
        max_sub = max(max_sub,sums);
    }
    return max_sub;
}

int main(){
    int arr[] = {9, -3, 3, -1, 6, -5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 6;
    int result = max_subarray(arr,n,k);
    cout<< result;
    return 0;
}
