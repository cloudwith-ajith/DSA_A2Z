//normal bubble sort
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[6]={13,46,24,52,20,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j <= i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    
    for(int i  : arr){
        cout<<i<<" ";
    }
    return 0;
}

------------------------------------------
    
//recurssion--bubble_sort

#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[],int n ){
    if(n==0) {return;}
    
    for(int i = 0 ; i <= n-1; i++){
        if (arr[i] > arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    
    bubble_sort(arr, n-1);
}


int main(){
    
    int arr [6] ={13,46,24,52,20,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,n-1);
    
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}
