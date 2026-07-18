//find the unique elements in the sorted array 
#include<bits/stdc++.h>
using namespace std;


int unique(int arr[],int n){
    int i = 0;
    for(int j =0;j < n-1;j++){
        if(arr[j] != arr[j+1]){
            i++;
        }
    }
    return i+1;
}

int main(){
    int arr[6] ={1,1,2,3,3,4};
    // output unique-->4,and arr{1,2,3,4,1,3};
    int n =sizeof(arr)/sizeof(arr[0]);
    cout<<unique(arr,n);
    return 0;
}
