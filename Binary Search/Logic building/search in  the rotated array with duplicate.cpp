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

///---------------------------- The edge case of the problem-------

//The logic matches the optimized Binary Search approach for this problem (specifically,
//LeetCode 81: Search in Rotated Sorted Array II).The key part that makes it correct for duplicates is this condition:

// thid id the edge case for the problem, when the array contain the duplicate in the starting and the ending index of the array 
// eg {3,1,2,3,3,3,3}
//if(arr[low] == arr[mid] && arr[mid] == arr[high]){
    high--;
    low++;
}
// we can trim the array into the next index because the mid is not true then the low and the high also not true


#include<bits/stdc++.h>
using namespace std;

bool searcharr(vector <int> &arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] == target){
            return true;
        }
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            high--;
            low++;
        }else if (arr[low] <= arr[mid]){
            if(arr[low] <= target && arr[mid] >= target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }            
        }else{
            if(arr[mid] <= target && arr[high] >= target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }

    return false;
}

int main(){
    vector <int> arr =  {3,1,2,3,3,3,3};
    int target = 2;
    if(searcharr(arr,target)){
        cout<<"present in the array";
    }else{
        cout<<"not present in the array";
    }
    return 0;
}
// the time complexity of the code is O(log n)
// the space complexity of the code is O(1)
