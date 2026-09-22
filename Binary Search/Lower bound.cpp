// --------------------------------------------------LOWER BOUND---------------------------------
// -- Conditions 
// Return the equal to or the first greater element of the target 


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


// optimal solution for the lower bound

#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector <int> &arr, int target){
    int n = arr.size();
    int answer = n; // FIX: Initialize to n, in case target is greater than all elements
    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target){
            answer = mid;   // mid could be the answer, but look for a smaller index on the left
            high = mid - 1;
        } else {
            low = mid + 1;  // arr[mid] < target, look on the right side
        }
    }

    return answer;
}

int main(){
    vector <int> arr = {1, 3, 5, 7, 9, 11};
    int target = 6;
    int result = lowerbound(arr, target);
    cout << "Lower bound index: " << result; // Outputs 3 (index of element 7)
    return 0;
}

// the time complexity of the code is O(log n)
// the space complexity of the code is O(1)

