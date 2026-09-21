// brute force method // linear search 

#include<bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int x){
    int n = arr.size();
    int ind = -1;
    for(int i = 0 ; i < n; i++){
        if(arr[i] == x){
            ind = i;
        }
    }
    return ind;
}


int main(){
    vector <int> arr = {1, 3, 5, 7, 9, 11};
    int target = 7;
    int result = search(arr,target);
    cout<< result;
    return 0;
}

// The Time complexity of the code is O(n)
// The Space complexity of the code is O(1)


// binary search 

#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector <int> &arr,int x){
    int n = arr.size();
    //the first index as the low 
    int low  = 0 ;
    // the last index as the high 
    int high = n - 1;
    //while loop 
    while(low <= high){
        // get the mid value
        int mid = (low + high) / 2;
        // if the mid value is the target value, then return the index
        if(arr[mid] == x){
            return mid;
        }
        // if the mid value is greater, change the high 
        if(arr[mid] > x){
            high = mid -1;
        }
        // if the mid value is lesser than, change the low value 
        else{
            low = mid + 1;
        }
    }
    // return -1 if there is no target found 
    return -1;
}


int main(){
    vector <int> arr = {1, 3, 5, 7, 9, 11};
    int x = 7;
    int result = binarysearch(arr,x);
    cout<<result;
    return 0;
}

// The Time complexity of the code is O(log n)
// The Space complexity of the code is O(1)
