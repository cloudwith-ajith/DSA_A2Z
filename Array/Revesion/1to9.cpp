// //-------------------brute force

#include<bits/stdc++.h>
using namespace std;

int largest(int arr[],int n){
    
    sort(arr,arr+n);
    return arr[n-1];
}

int main(){
    int arr[] = {2,5,1,3,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<largest(arr,n);
    return 0;
}

//tc is O(n log n) because its using the sorting 
// sc is O(1)
