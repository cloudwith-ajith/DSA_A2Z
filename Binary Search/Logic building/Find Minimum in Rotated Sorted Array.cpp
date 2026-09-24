// brute force method 
// linear search in the array is the brute force method for the array 
// the time complexity of the code is O(n)
// the space complexity of the code is O(1)

// Optimal way for the problem 

#include<bits/stdc++.h>
using namespace std;

int min_element(vector <int> &arr){
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int minn = INT_MAX;

    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[low] <= arr[mid]){
            minn = min(arr[low],minn);
            low = mid + 1;
        }else{
            minn = min(minn,arr[mid]);
            high = mid - 1;
        }
    }

    return minn;
}



int main(){
    vector <int> arr = {11, 13, 15, 17};
    int result = min_element(arr);
    cout<<result;
    return 0;
}

// the time complexity of the code is O(log n);
// the space complexity of the code is O(1)
