//------------------------linear search
#include<bits/stdc++.h>
using namespace std;

int  linear_search(int arr[],int num,int n){
    for(int i =0;i < n; i++){
        if(arr[i] == num){
            return  i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int num = 6;
    cout<<linear_search(arr,num,n);
    return 0;
}
