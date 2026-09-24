// brute force method 

#include<bits/stdc++.h>
using namespace std;

bool searcharr(vector <int> &arr, int target){
    int n = arr.size();
    for(int i = 0 ; i < n; i++){
        if(arr[i] == target){
            return true;
        }
    }

    return false;
}

int main(){
    vector <int> arr =  {3,1,2,3,3,3,3};
    int target = 9;
    if(searcharr(arr,target)){
        cout<<"present in the array";
    }else{
        cout<<"not present in the array";
    }
    return 0;
}

// the time complexity of the code is O(n)
// the space complexity of the code is O(1)
