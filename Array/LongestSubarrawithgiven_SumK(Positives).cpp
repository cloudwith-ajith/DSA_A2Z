#include<bits/stdc++.h>
using namespace std;

int longest_subarray(int arr[],int n,int k){
    unordered_map <int,int> prefix_mpp;
    int max_len = 0;
    int sum = 0;
    for(int i = 0;i < n; i++){
        sum = sum + arr[i];
        //find the very first len of the k
        if (sum == k ){
            max_len = i + 1;
        }
        //find the key wheather present in the prefixmapp
        if(prefix_mpp.find(sum - k) != prefix_mpp.end()){
            max_len = max(max_len, i - prefix_mpp[sum-k]);
        }
        // store the memory of the element 
        if(prefix_mpp.find(sum) == prefix_mpp.end()){
            prefix_mpp[sum] = i;
        }
    }
    
    return max_len;
} 

int main(){
    int arr[] = {10, 5, 2, 7, 1, 9};
    int k = 15;
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = longest_subarray(arr,n,k);
    cout<<result;
    return 0;
}

//-------------------------only posttive with slidind window

#include<bits/stdc++.h>
using namespace std;

int longest_subarray_window(int arr[],int n ,int k){
    int left = 0;
    int max_len = 0;
    int sum = 0;
    //right pointer
    for(int right = 0; right < n;right++){
        sum = sum + arr[right];
        //left remove when window up
        while(left <= right && sum > k){
            sum = sum - arr[left];
            left++;
        }
        //check the sum is equal to k 
        if(sum == k){
            max_len = max(max_len,right-left +1);
        }
    }
    
    return max_len;
}

int main(){
    int arr[] = {10, 5, 2, 7, 1, 9};
    int k = 15;
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = longest_subarray_window(arr,n,k);
    cout<<result;
    return 0;
}

//----- space complexity ----O(1)
