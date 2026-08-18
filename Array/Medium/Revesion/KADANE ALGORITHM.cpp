//----------------------------------------------------------KADANE ALGORITHM
// MAXI SUBARRAY SUM
//------BETTER SOLUTION
//----the time complexity of the problem is O(n2)
// the space complxity of the code is O(1)
#include<bits/stdc++.h>
using namespace std;

int max_subarray_sum(vector<int> &arr){
    int n = arr.size();
    int max_sum = INT_MIN;
    for(int i = 0; i < n; i++){
        int sums = 0;
        for(int j = i; j < n;j++){
            sums = sums + arr[j]; 
            max_sum = max(max_sum,sums);
        }
    }

    return max_sum;
}

int main(){
    vector <int> arr = {2, 3, 5, -2, 7, -4};
    int result = max_subarray_sum(arr);
    cout<<result;
    return 0;
}


//----------------------optimal code 


#include<bits/stdc++.h>
using namespace std;

int max_subarray_sum(vector<int> &arr){
    int n = arr.size();
    int max_sum = INT_MIN;
    int sums = 0;
    for(int i = 0; i < n; i++){
        sums = sums + arr[i];

        max_sum = max(max_sum,sums);

        if(sums < 0){
            sums = 0;
        }
    }
    return max_sum;
}

int main(){
    vector <int> arr = {2, 3, 5, -2, 7, -4};
    int result = max_subarray_sum(arr);
    cout<<result;
    return 0;
}

// the time complexity of the code is  O(n)
// the space complxity of the code is O(1)

// follow up 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find maximum sum of subarrays and print the subarray having maximum sum
    int maxSubArray(vector<int>& nums) {
        
        // maximum sum
        long long maxi = LLONG_MIN; 
        
        // current sum of subarray
        long long sum = 0;
        
        // starting index of current subarray
        int start = 0; 
        
        // indices of the maximum sum subarray
        int ansStart = -1, ansEnd = -1; 
        
        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            
            // update starting index if sum is reset
            if (sum == 0) {
                start = i;
            }
            
            // add current element to the sum
            sum += nums[i]; 
            
            /* Update maxi and subarray indice
            s if current sum is greater*/
            if (sum > maxi) {
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }
            
            // Reset sum to 0 if it becomes negative
            if (sum < 0) {
                sum = 0;
            }
        }
        
        // Printing the subarray
        cout << "The subarray is: [";
        for (int i = ansStart; i <= ansEnd; i++) {
            cout << nums[i] << " ";
        }
        cout << "]" << endl;
        
        // Return the maximum subarray sum found
        return maxi;
    }
};

int main() {
    vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

    // Create an instance of Solution class
    Solution sol;

    int maxSum = sol.maxSubArray(arr);

    // Print the max subarray sum
    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}
