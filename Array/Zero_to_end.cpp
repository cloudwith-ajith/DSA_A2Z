//-----------------moving the zero to the end 
//-----------------brute force method 
#include<bits/stdc++.h>
using namespace std;

void bz(int arr[], int n){
    vector <int> temp(n,0);
    
    int index = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            temp[index] = arr[i];
            index++;
        }
    }
    //copy back to the original array 
    for(int i = 0; i < n; i++){
        arr[i] =temp[i];
    }
}


int main(){
    int arr[] = {0,0,1,2,0,1,0,4,0};
    int n = sizeof(arr)/ sizeof(arr[0]);
    bz(arr,n);
    for(int a : arr){
        cout<<a<<" ";
    }
    return 0;
}
