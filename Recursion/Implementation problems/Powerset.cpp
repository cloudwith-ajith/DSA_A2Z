#include <bits/stdc++.h>
using namespace std;

// Function to generate all possible subsets (the Power Set) using bit manipulation
vector<vector<int>> subsets(vector<int> arr) {
    int n = arr.size();
    
    // Total number of subsets is 2^n. 
    // Left-shifting 1 by n (1 << n) is a fast way to compute 2^n.
    int total = 1 << n;

    // 2D vector to store all generated subsets
    vector<vector<int>> ans;

    // Loop through every number from 0 to (2^n - 1).
    // Each number 'i' acts as a binary mask representing one unique subset.
    // Example for n=3: i=5 in binary is 101 -> pick index 0 and index 2.
    for (int i = 0; i < total; i++) {
        vector<int> subset; // Stores the elements for the current subset

        // Check each bit position 'j' from 0 to n-1
        for (int j = 0; j < n; j++) {
            // (1 << j) creates a number with only the j-th bit set (e.g., 001, 010, 100).
            // Using bitwise AND (&) checks if the j-th bit of 'i' is 1.
            if ((i & (1 << j)) != 0) {
                // If the j-th bit is 1, include arr[j] in the current subset
                subset.push_back(arr[j]);
            }
        }

        // Add the completed subset to our final answer list
        ans.push_back(subset);
    }

    return ans;
}

int main() {
    // Input array of 3 elements (2^3 = 8 total subsets)
    vector<int> arr = {1, 2, 3};
    
    // Call the function to get the power set
    vector<vector<int>> ans = subsets(arr);
    
    // Print all subsets in a readable format
    cout << "Power Set:" << endl;
    for (const auto& subset : ans) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
