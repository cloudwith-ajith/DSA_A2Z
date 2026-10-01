// brute force method for the problem 

#include<bits/stdc++.h>
using namespace std;

int Kth_Missing(vector <int> &arr, int k){
    int n = arr.size();
    
    // Traverse the sorted array sequentially
    for(int i = 0; i < n; i++){
        // If the current element is less than or equal to our target 'k',
        // it means an available number is occupied by the array.
        // We must shift our target to the right to find the next missing integer.
        if(arr[i] <= k){
            k++;
        } else {
            // Once arr[i] > k, no future elements can affect or shift our target.
            // We can break early because the array is sorted.
            break;
        }
    }
    
    // The shifted 'k' value is now exactly the k-th missing number
    return k;
}

int main(){
    vector <int> arr = {1, 4, 6, 8, 9};
    int k = 3;
    
    // Output the result
    cout << "The " << k << "th missing number is: " << Kth_Missing(arr, k);
    return 0;
}

// the time complexity of the code is O(n)
// the space complexity of the code is O(1)
