// optimnal  method for the problem 
#include<bits/stdc++.h>
using namespace std;

double Median_arrays(vector <int> &arr1, vector <int> &arr2){
    // STEP 1: Ensure arr1 is always the smaller array.
    // This minimizes the binary search range and guarantees O(log(min(n, m))) time complexity.
    if(arr1.size() > arr2.size()){
        return Median_arrays(arr2, arr1);
    }

    int n = arr1.size();
    int m = arr2.size();
    
    // Define the binary search range on the smaller array (arr1)
    int low = 0;
    int high = n;
    
    // Total elements that should be on the left half of the combined partition
    int leftside = (n + m + 1) / 2;

    // STEP 2: Perform binary search to find the correct partition point
    while(low <= high){
        // Pick a cut point in arr1
        int cut_1 = (low + high) / 2;
        // Calculate the corresponding cut point in arr2
        int cut_2 = leftside - cut_1;

        // STEP 3: Identify the 4 boundary elements around the cuts.
        // If a cut is at the absolute boundary (0 or end), use INT_MIN/INT_MAX as virtual padding.
        int left1 = (cut_1 == 0) ? INT_MIN : arr1[cut_1 - 1];  // Max element on left of arr1
        int right1 = (cut_1 == n) ? INT_MAX : arr1[cut_1];     // Min element on right of arr1
        
        int left2 = (cut_2 == 0) ? INT_MIN : arr2[cut_2 - 1];  // Max element on left of arr2
        int right2 = (cut_2 == m) ? INT_MAX : arr2[cut_2];     // Min element on right of arr2

        // STEP 4: Check if we found the valid partition.
        // Every element on the left side must be <= every element on the right side.
        if(left1 <= right2 && left2 <= right1){
            
            // If total number of elements is ODD, median is the maximum of the left elements
            if((n + m) % 2 == 1){
                return (double)max(left1, left2);
            }
            // If total number of elements is EVEN, median is the average of the two middle elements
            else{
                return (((double)max(left1, left2) + min(right1, right2)) / 2.00);
            }
        }
        // STEP 5: Adjust the binary search range if the partition is invalid
        else if(left1 > right2){
            // Too many elements from arr1 are on the left side; shift left
            high = cut_1 - 1;
        }else{
            // Too few elements from arr1 are on the left side; shift right
            low = cut_1 + 1;
        }
    }

    return 0.00;
}

int main(){
    // Test Case
    vector <int> arr1 = {1, 2, 3};
    vector <int> arr2 = {4, 5};
    
    cout << "The median is: " << Median_arrays(arr1, arr2) << endl;
    return 0;
}

// The time complexity of the code is O(log (min(arr1, arr2));
// the space complexity of the code is O(1)
