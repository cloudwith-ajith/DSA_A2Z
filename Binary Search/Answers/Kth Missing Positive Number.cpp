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


// the optimal way for the problem 


#include<bits/stdc++.h>
using namespace std;

// Function to find the kth missing positive integer using Binary Search
int Kth_Missing(vector <int> &arr, int k){
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    
    // Perform standard binary search to find the transition point
    while(low <= high){
        // Calculate the middle index using proper operator precedence
        int mid = (low + high) / 2;
        
        // Calculate total missing numbers up to the current 'mid' index
        // Formula: Actual value - Expected value if nothing was missing
        int missing = arr[mid] - (mid + 1);
        
        // If the missing count is less than k, the kth missing number lies to the right
        if(missing < k){
            low = mid + 1;
        }
        // If the missing count is greater than or equal to k, it lies to the left
        else{
            high = mid - 1;
        }
    }
    
    // After the loop terminates, 'low' points to the position where 
    // the kth missing number can be derived mathematically using 'low + k'
    return low + k;
}

int main(){
    // Sample strictly increasing array
    vector <int> arr = {1, 4, 6, 8, 9};
    int k = 3;
    
    // Output the result of the function
    cout << "The " << k << "th missing number is: " << Kth_Missing(arr, k);
    return 0;
}

// important formula ---> high + 1 + k // low + k
// the time complexity of code is O(log n)
// the space complexity of the code is O(1)
