#include<bits/stdc++.h>
using namespace std;

int lonlen(vector<int> &arr, int target){
    int n = arr.size();
    unordered_map <int,int> mpp;
    // max lent 
    int maxlen = 0;
    int sum = 0 ;
    for(int i = 0 ; i < n; i++){
        // add the sum
        sum += arr[i];
        // the sum equal to the target 
        // then the len from the zero to is a subarray
        if(sum == target){
            maxlen = i + 1;
        }else if(mpp.find(sum) != mpp.end()){                
             maxlen = max(maxlen, i - mpp[sum]);
        }else{
                // the condition is the prefix is not in the array then add
                mpp[sum] = i;     
            }  
        }
    //return the maxlen
    return maxlen;
}  


int main(){
    vector<int> arr = {9, -3, 3, -1, 6, -5};
    int target = 0 ;
    int result = lonlen(arr,target);
    cout<<result;
    return 0;
}
