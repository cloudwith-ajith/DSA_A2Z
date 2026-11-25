// Includes all standard C++ libraries (vector, iostream, etc.)
#include <bits/stdc++.h>
using namespace std;

/**
 * Recursive function to COUNT how many subsequences sum up to 'k'.
 * 
 * @param index : Current index being evaluated in 'arr'
 * @param k     : Target sum
 * @param sum   : Running sum of the elements picked so far along this path
 * @param arr   : Input array (passed by const reference for efficiency)
 * @return      : Total count of valid subsequences found from this state onward
 */
int recu(int index, int k, int sum, const vector<int>& arr) {
    
    // BASE CASE: Reached the end of the array
    if (index == arr.size()) {
        // If our accumulated sum matches 'k', this path forms 1 valid subsequence
        if (sum == k) {
            return 1;
        }
        // Otherwise, this path does not form a valid subsequence
        return 0;
    }

    // ---------------------------------------------------------
    // CHOICE 1: PICK (Include) the current element arr[index]
    // ---------------------------------------------------------
    // Notice we don't need a 'temp' vector or backtracking anymore because we are only
    // counting, and 'sum' is passed by value (so each call gets its own copy).
    // 'l' stores the count of valid subsequences from the LEFT (pick) subtree.
    int l = recu(index + 1, k, sum + arr[index], arr);

    // ---------------------------------------------------------
    // CHOICE 2: NOT PICK (Exclude) the current element arr[index]
    // ---------------------------------------------------------
    // 'r' stores the count of valid subsequences from the RIGHT (not-pick) subtree.
    int r = recu(index + 1, k, sum, arr);

    // Combine and return the total valid subsequences found in both branches
    return l + r;
}

/**
 * Wrapper function to start the recursive count from index 0 with sum 0.
 */
int subsumk(const vector<int>& arr, int k) {
    // Start recursion at index 0 with an initial running sum of 0
    return recu(0, k, 0, arr);
}

int main() {
    // Input array and target sum
    vector<int> arr = {1, 2, 1};
    int k = 2;

    // Calculate and print the total number of valid subsequences
    // Valid subsequences for {1, 2, 1} with k = 2 are [1, 1] and, so output is 2
    int x = subsumk(arr, k);
    cout << x << "\n";

    return 0; // End of program
}
