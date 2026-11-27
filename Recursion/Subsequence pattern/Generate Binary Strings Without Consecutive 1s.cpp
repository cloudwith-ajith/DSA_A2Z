#include <bits/stdc++.h>
using namespace std;

// Helper function to generate valid binary strings using backtracking
void back_track(int n, string &str, vector<string> &ans) {
    // Base Case: If the current string reaches the target length 'n',
    // store it in the result list and return to explore other branches.
    if (str.length() == n) {
        ans.push_back(str);
        return;
    }

    // Choice 1: Always add '0'.
    // Adding '0' never creates consecutive '1's, so it is always valid.
    // Exploring '0' before '1' ensures the final output is sorted.
    str.push_back('0');
    back_track(n, str, ans);
    str.pop_back(); // Backtrack: remove '0' to restore the state for the next choice.

    // Choice 2: Add '1' only if safe.
    // We can only append '1' if the string is empty or the last character is '0'.
    if (str.empty() || str.back() == '0') {
        str.push_back('1');
        back_track(n, str, ans);
        str.pop_back(); // Backtrack: remove '1' after exploring this branch.
    }
}

// Main solver function to initialize variables and start backtracking
vector<string> one_zero(int n) {
    vector<string> ans;
    string str = "";
    back_track(n, str, ans);
    return ans;
}

int main() {
    int n = 2;
    vector<string> x = one_zero(n);
    
    // Print all generated binary strings
    for (auto i : x) {
        cout << i << " ";
    }
    return 0;
}


// The time complexity of the code is O(n.2^n)
// The space complexity of the code is O(n)
