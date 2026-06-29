//counting the number in brute force method
#include<bits/stdc++.h>
using namespace std;
// normal method 
int main(){
    int arr[] = {1,2,3,4,1,1,1,1,3};
    int count = 0;
    int target = 1;
    for(int i =0;i < sizeof(arr)/sizeof(arr[0]);i++){
        if(arr[i] == target){
            count++;
        }
    }
    cout<<target<<"---->"<<count;
    return 0;
}
// Time complexity of the problem is O(n)

// using hash array 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,1,1,1,1,1,3};
    int hash[5] = {0};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i =0;i < n;i++){
        hash[arr[i]] = hash[arr[i]] + 1;
    }
    int target = 1;
    cout<<hash[target];
    return 0;
}

// TC os this is O(1) + O(n) as per the rule avoid the constant value --> O(n)
