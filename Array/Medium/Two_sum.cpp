//Two_sum---->google
//-----------------------brute force
#include<bits/stdc++.h>
using namespace std;

bool two_sum(int arr[],int n,int target){
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] + arr[j] == target){
                return true;
            }
        }
    }
    
    return false;
    
}

int main(){
    int arr[] = {2,6,5,8,11};
    int n  = sizeof(arr)/sizeof(arr[0]);
    int target = 14;
    bool result = two_sum(arr,n,target);
    if(result == true){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
    return 0;
}
///-------------Time complexity O(2*n)
