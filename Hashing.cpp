// Number Hashing 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,2,2,1,10,4,5,5,5};
    int hash[11]={0};
    //prestoring
    for(int i =0;i <sizeof(arr)/sizeof(arr[0]);i++){
        hash[arr[i]] = hash[arr[i]] + 1;
    }
    
    int  fetch =5;
    cout<<hash[fetch]<<" "<< "is the count";
    return 0;
}
