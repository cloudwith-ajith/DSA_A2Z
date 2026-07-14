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

------------------------------------------------------
    
//insertion sort with recurssion

#include<bits/stdc++.h>
using namespace std;


void insertion_sort(int arr[],int i, int n){
    if (i > n-1){
        return ;
    }else{
        int j = i;
        while (j > 0 && arr[j-1] > arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
        
        insertion_sort(arr,i+1,n);
    }
} 


int main(){
    
    int arr[6] = {13,46,24,52,20,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,0,n);
    
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}
