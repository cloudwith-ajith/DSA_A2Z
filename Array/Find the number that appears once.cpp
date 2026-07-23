// code for the  Find the number that appears once, and the other numbers twice
// better method 
#include<bits/stdc++.h>
using namespace std;

int find_num(int arr[],int n){
    map <int,int> mpp;
    for(int i = 0; i < n;i++){
        mpp[arr[i]] = mpp[arr[i]] + 1;
    }
    
    for(int i = 0; i < n; i++){
        if(mpp[arr[i]] == 1){
            return arr[i];
        }
    }
    return -1;
}

int main(){
    int arr[] = {4,1,2,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = find_num(arr,n);
    cout<<result;
    return 0;
}

//tc is O(N)

//-------optimal way
#include<bits/stdc++.h>
using namespace std;

int app_num(int arr[],int n){
    
    int xor1 = 0;
    for(int i = 0; i < n; i++){
        xor1 = xor1  ^ arr[i];
    }
    
    return xor1;
}

int main(){
    int arr[] = {4,1,2,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = app_num(arr,n);
    cout<<result;
    return 0;
}
