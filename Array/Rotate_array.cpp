//--------------------------------------right rotate
#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[],int start, int end){
    while(start < end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

void k_rotate(int arr[],int k,int n){
    //normalize k = k % n. egde case
    k = k % n;
    
    //reverse the entire array
    reverse(arr,0,n-1);
    
    //reverse the first part
    reverse(arr,0, k-1);
    
    //reverse the last part
    reverse(arr,k,n-1);
    
    
}


int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    k_rotate(arr,k,n);
    
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}

//-----------------left rotate

#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[],int start, int end){
    while(start < end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

void k_rotate(int arr[],int k,int n){
    //normalize k = k % n. egde case
    k = k % n;
    // rotate the first k element
    reverse(arr, 0 , k-1);
    // rotate the balance element
    reverse(arr,k,n-1);
    //reverse the whole array
    reverse (arr,0,n-1);
}


int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    k_rotate(arr,k,n);
    
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}
