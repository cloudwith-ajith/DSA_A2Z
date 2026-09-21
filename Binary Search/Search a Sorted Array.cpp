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
        int mid = low + (high - low) / 2;
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

// ⚠️ The Problem with (low + high) / 2In C++,
//     a standard 32-bit signed integer (int) has a maximum maximum capacity of 2,147,483,647.
//     If you are searching through a massive array (like a large database or a huge dataset in competitive programming) where both low and high are large numbers,
// adding them together can easily push the value past that maximum limit.Example of how it breaks:Assume low = 1,500,000,000Assume high = 2,000,000,000Step 1: 
// The computer tries to calculate low + high → 1,500,000,000 + 2,000,000,000 = 3,500,000,000.
//     Step 2: Because 3,500,000,000 is greater than the integer limit (2,147,483,647), the value overflows into negative numbers.
//     It wraps around and becomes roughly -794,967,296.Step 3: The computer divides that negative number by 2, resulting in a negative index (-397,483,648).
// The Crash: Trying to access arr[-397,483,648] causes your program to crash instantly with a Segmentation Fault or out-of-bounds error.
// The Solution: low + (high - low) / 2By rewriting the equation, we change the order of operations so that the computer never has to calculate 
// a number larger than high itself.Let's plug the same numbers into the safe formula:Calculate the distance (high - low):2,000,000,000 - 1,500,000,000 = 500,000,000 
//     (Perfectly safe, well below the limit).Divide the distance by 2:500,000,000 / 2 = 250,000,000.Add it back to low:1,500,000,000 + 250,000,000 = 1,750,000,000.
//     The calculation stays completely within safe boundaries at every single step, giving you the exact correct midpoint without any risk of memory corruption.

