// Includes all standard C++ libraries (vector, iostream, etc.)
#include <bits/stdc++.h>
using namespace std;

/**
 * Helper recursive function to find all subsequences whose elements sum up to 'k'.
 * 
 * @param index : Current position we are checking in the input array 'arr'
 * @param k     : The target sum we want to reach
 * @param ans   : 2D vector storing all valid subsequences found so far (passed by reference)
 * @param temp  : Current subsequence being built along this recursive path (passed by reference)
 * @param sum   : Running sum of the elements currently inside 'temp'
 * @param arr   : The original input array (passed by const reference to avoid copying)
 */
void recu(int index, int k, vector<vector<int>>& ans, vector<int>& temp, int sum, const vector<int>& arr) {
    
    // BASE CASE: We have made a decision (pick or not-pick) for every element in the array
    if (index == arr.size()) {
        // Check if the current subsequence's sum equals the target sum 'k'
        if (sum == k) {
            // Save a copy of the valid subsequence into our final answer list
            ans.push_back(temp);
        }
        // Stop going deeper along this path and return to the previous function call
        return;
    }

    // ---------------------------------------------------------
    // CHOICE 1: PICK (Include) the current element arr[index]
    // ---------------------------------------------------------
    temp.push_back(arr[index]); // Add current element to our temporary subsequence
    
    // Move to the next index (index + 1) and add arr[index] to the running sum
    recu(index + 1, k, ans, temp, sum + arr[index], arr);

    // ---------------------------------------------------------
    // BACKTRACK: Undo the previous choice
    // ---------------------------------------------------------
    // Remove the element we just added so 'temp' goes back to its previous state
    // before we explore the "NOT PICK" choice below
    temp.pop_back();

    // ---------------------------------------------------------
    // CHOICE 2: NOT PICK (Exclude) the current element arr[index]
    // ---------------------------------------------------------
    // Move to the next index (index + 1) while keeping 'temp' and 'sum' unchanged
    recu(index + 1, k, ans, temp, sum, arr);
}

/**
 * Wrapper function that initializes helper variables and starts the recursion.
 */
vector<vector<int>> subsumk(vector<int>& arr, int k) {
    vector<vector<int>> ans; // Stores all matching subsequences
    vector<int> temp;        // Starts empty; holds elements during recursion
    
    // Start recursion from index 0 with an initial sum of 0
    recu(0, k, ans, temp, 0, arr);
    
    return ans;
}

int main() {
    // Input array and target sum
    vector<int> arr = {1, 2, 1};
    int k = 2;

    // Get all subsequences that sum to 'k'
    // Note: For {1, 2, 1} and k = 2, valid subsequences are [1, 1] and [2]
    vector<vector<int>> x = subsumk(arr, k);

    // Loop through each valid subsequence in 'x' and print it
    for (const auto& i : x) {
        cout << "[ ";
        for (int j : i) {
            cout << j << " ";
        }
        cout << "]\n";
    }

    return 0; // End of program
}


///// Includes all standard C++ libraries (vector, iostream, etc.)
#include <bits/stdc++.h>
using namespace std;

/**
 * Recursive function to find ONLY THE FIRST subsequence that sums to 'k'.
 * 
 * @return true  : A valid subsequence was found (signals all parent calls to stop early)
 * @return false : No valid subsequence was found along this path
 */
bool recu(int index, int k, vector<vector<int>>& ans, vector<int>& temp, int sum, const vector<int>& arr) {
    
    // BASE CASE: Reached the end of the array
    if (index == arr.size()) {
        // Check if our current subsequence equals the target sum 'k'
        if (sum == k) {
            ans.push_back(temp); // Save the first valid subsequence found
            return true;         // Signal "SUCCESS" up the call stack to stop further searching
        }
        return false;            // Signal "NOT FOUND" on this path
    }

    // ---------------------------------------------------------
    // CHOICE 1: PICK (Include) the current element arr[index]
    // ---------------------------------------------------------
    temp.push_back(arr[index]); // Add current element to the temporary subsequence
    
    // Explore deeper with the picked element.
    // If this branch returns 'true', immediately return 'true' without checking other branches.
    if (recu(index + 1, k, ans, temp, sum + arr[index], arr) == true) {
        return true;   
    }

    // ---------------------------------------------------------
    // BACKTRACK: Undo the previous choice
    // ---------------------------------------------------------
    // Execution only reaches here if Choice 1 returned 'false'.
    // Remove arr[index] from 'temp' before trying the "not-pick" choice.
    temp.pop_back();

    // ---------------------------------------------------------
    // CHOICE 2: NOT PICK (Exclude) the current element arr[index]
    // ---------------------------------------------------------
    // Explore deeper without the current element.
    // If this branch finds a valid subsequence, immediately propagate 'true' upward.
    if (recu(index + 1, k, ans, temp, sum, arr) == true) {
        return true;
    }

    // Neither picking nor not-picking led to a valid sum 'k' from this state
    return false;
}

/**
 * Wrapper function to set up variables and trigger the search.
 */
vector<vector<int>> subsumk(vector<int>& arr, int k) {
    vector<vector<int>> ans; // Will hold at most 1 subsequence because we stop early
    vector<int> temp;        // Tracks the current subsequence during recursion
    
    // Start recursion at index 0 with initial sum 0
    recu(0, k, ans, temp, 0, arr);
    
    return ans;
}

int main() {
    // Input array and target sum
    vector<int> arr = {1, 2, 1};
    int k = 2;

    // Find the first subsequence summing to 'k'
    vector<vector<int>> x = subsumk(arr, k);

    // Print the result (will only print [ 1 1 ], stopping before it ever checks [ 2 ])
    for (const auto& i : x) {
        cout << "[ ";
        for (int j : i) {
            cout << j << " ";
        }
        cout << "]\n";
    }

    return 0; // End of program
}
