//------------------------brute force method for the problem  --------

#include<bits/stdc++.h>
using namespace std;

int LastOccur(vector <int> &arr,int target){
    int  n = arr.size();
    int answer = -1;

    for(int i = 0; i < n; i++){
        if(arr[i] == target){
            answer = i;
        }
    }
    return answer;
}


int main(){
    vector <int> arr = {1, 3, 5, 7, 9};
    int target = 46;
    int result = LastOccur(arr,target);
    cout<<result;
    return 0;
}

// the time complexity of the code is O(n)
// the space complexity of the code is O(1)

//-----------------------optimal way for the problem---------


#include<bits/stdc++.h>
using namespace std;

int LastOccurrence(vector <int> &arr, int target){
    int n = arr.size();
    // the low point to the first index of the array 
    int low = 0;
    // the high point to the last index of the array 
    int high = n - 1;
    // the answer variable used to return the answer
    int answer = -1;
    // the while loop for the binary search 
    while(low <= high){
        // find the mid element 
        int mid = (high + low) / 2;
        // if the element is equal to the target, mark the answer to the mid index
        if(arr[mid] == target){
            answer = mid;
            // used to move the index always to the right 
            // becasue always at the right of the array 
            low = mid + 1;
        }
        // the right side of the array 
        else if(arr[mid] < target){
            low = mid + 1;
        }
        // the left side of the array 
        else{
            high = mid - 1;
        }
    }
    // the answer used to return 
    return answer;
}


int main(){
    vector <int> arr = {1,2,4,4,4,6,8};
    int target = 4;
    int result = LastOccurrence(arr, target);
    cout<<result;
    return 0;
}

// the time complexity of the code is O(log n)
// the space complexity of the code is O(1)


