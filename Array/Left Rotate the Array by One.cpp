//---------------------------------brute force method Tc - o(n),sp - o(n)
#include<bits/stdc++.h>
using namespace std;

void rotate(int arr[],int n ){
    vector <int> temp(n);
    
    for(int i = 1; i < n; i++){
        temp[i-1]  = arr[i];
    }
    temp[n-1] = arr[0];
    
    for(int i : temp){
        cout<<i<<" ";
    }

}

int main(){
    int arr[] ={-1, 0, 3, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    rotate(arr,n);
  
    return 0;
}
//-------------------------------------optimal approach TC is - O(n), SP O(1)---
#include<bits/stdc++.h>
using namespace std;

void rotate(int arr[],int n ){
    int first_element =arr[0];
    
    for(int i =1;i < n;i++){
        arr[i-1] =arr[i];
    }
    arr[n-1]=first_element;
} 
int main(){
    int arr[] ={-1, 0, 3, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    rotate(arr,n);
    
    for(int i : arr){
        cout<<i<<" ";
    }

    return 0;
}
