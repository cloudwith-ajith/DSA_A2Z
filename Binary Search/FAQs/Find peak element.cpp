// brute force method for the code is 
#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
        // A single element is always a peak.
    if (nums.size() == 1) {
        return 0;
    }
 
    for (int i = 0; i < (int)nums.size(); i++) {
            // Check the first element using only the right neighbor.
        if (i == 0) {
            if (nums[i] > nums[i + 1]) {
                return i;
            }
        } else if (i == (int)nums.size() - 1) {
                // Check the last element using only the left neighbor.
            if (nums[i] > nums[i - 1]) {
                return i;
            }
        } else {
            // A middle element is a peak only if it is greater than both sides.
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                return i;
            }
        }
     }
 
    return -1;
}

 
// Driver code starts
int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};

    cout << findPeakElement(nums) << endl;
 
    return 0;
}


// the time complexity of the code is O(n)
// the space compleity of the code is O(1)


//==============================================================================================
// optimal way for the code 


#include<bits/stdc++.h>
using namespace std;

int Peak_Element(vector <int> &arr){
    int n = arr.size();
    
    // Safety check: Handle arrays with fewer than 2 elements to prevent runtime errors
    if (n == 0) return -1;
    if (n == 1) return 0; // A single element is always its own peak

    // Check if the very first element is a peak (it has no left neighbor)
    if(arr[0] > arr[1]) return 0;
    
    // Check if the very last element is a peak (it has no right neighbor)
    if(arr[n-1] > arr[n - 2]) return n - 1;
    
    // Set search boundaries. We start at 1 and end at n-2 
    // because index 0 and n-1 were already validated above.
    int low = 1;
    int high = n - 2;
    
    // Standard Binary Search loop
    while(low <= high){
        // Calculate the middle index safely to avoid potential integer overflow
        int mid = low + (high - low) / 2;

        // Condition A: If mid is greater than both its neighbors, we found a peak!
        if(arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]){
            return mid;
        }
        // Condition B: If the element to the right is greater, we are on a rising slope.
        // This guarantees that at least one peak element exists on the right side.
        else if(arr[mid] < arr[mid + 1]){
            low = mid + 1; // Move our search space to the right half
        }
        // Condition C: If we are on a falling slope, a peak must exist on the left side.
        else{
            high = mid - 1; // Move our search space to the left half
        }
    }

    // Return -1 if no peak element is found (mathematically impossible if array is valid)
    return -1;
}

int main(){
    // Test case: 3 is the peak element, located at index 2
    vector <int> arr = {1, 2, 3, 1};
    cout << "Peak Index: " << Peak_Element(arr) << endl;
    return 0;
}



// the time complexity of the code is O(log n)
// the space complexity of the code is O(1)
