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

/// The Time complexity of the code is O(n.2n)
// The space complexity of the code is O(n)


//---------------------------------------------rescursion 

#include <bits/stdc++.h>
using namespace std;

// Recursive helper function to generate all subsets (Power Set)
// Note: 'ans' and 'temp' are passed by reference (&) so all recursive calls modify the same vectors
void solve(int index, vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp) {
    
    // BASE CASE: 
    // If we have considered all elements in the array, store the current subset and return
    if (index == arr.size()) {
        ans.push_back(temp);
        return;
    }

    // CHOICE 1: INCLUDE the current element (arr[index])
    temp.push_back(arr[index]);          // Add element to the current subset
    solve(index + 1, arr, ans, temp);    // Move to the next index

    // BACKTRACK: 
    // Remove the element we just added so we can explore the path without it
    temp.pop_back();

    // CHOICE 2: EXCLUDE the current element (arr[index])
    solve(index + 1, arr, ans, temp);    // Move to the next index without adding arr[index]
}

// Main function to initialize variables and trigger the recursion
vector<vector<int>> powerset(vector<int> &arr) {
    vector<vector<int>> ans;  // Stores all 2^n subsets
    vector<int> temp;         // Temporarily holds one subset at a time during recursion

    // Start recursion from index 0
    solve(0, arr, ans, temp);

    return ans;
}

int main() {
    // Input array
    vector<int> arr = {1, 2, 3};
    
    // Generate the power set
    vector<vector<int>> x = powerset(arr);

    // Print each subset in the format [123]
    for (auto subset : x) {
        cout << "[";
        for (auto element : subset) {
            cout << element;
        }
        cout << "]" << endl;
    }

    return 0;
}


// The time complexity of the code is O(n. 2 ^ n)
// the space complexity of the code is O(n)
