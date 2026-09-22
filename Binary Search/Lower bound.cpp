// brute force method for the lower bound 


#include<bits/stdc++.h>
using namespace std;

int upper_bound(vector <int> &arr, int target){
    int n = arr.size();
    for(int i = 0 ; i < n; i ++){
        if(arr[i] == target || arr[i] > target){
            return i;
        }
    }
    return -1;
}

int main(){
    vector <int> arr = {1,3,5,7,9,11};
    int target = 6;
    int result = upper_bound(arr,target);
    cout<< result;
    return 0;
}


// the time complexity of the code is O(n)
// hte space complexity of the code is O(1)

