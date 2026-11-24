#include <bits/stdc++.h>
using namespace std;

// Helper function to build valid parenthesis combinations via backtracking
void backtrack(vector<string> &answer, string &current, int opencout, int closedcout, int max) {
    // Base case: if the string reaches the target length (2 * n), save it
    if (current.length() == max * 2) {
        answer.push_back(current);  
        return;
    }

    // Choice 1: Add an opening bracket '(' if we haven't used all 'n' of them
    if (opencout < max) {
        current.push_back('(');                                      // Choose
        backtrack(answer, current, opencout + 1, closedcout, max);   // Explore
        current.pop_back();                                          // Unchoose (backtrack)
    }

    // Choice 2: Add a closing bracket ')' only if it matches an unclosed '('
    if (closedcout < opencout) {     
        current.push_back(')');                                      // Choose
        backtrack(answer, current, opencout, closedcout + 1, max);   // Explore
        current.pop_back();                                          // Unchoose (backtrack)
    }
}

// Main wrapper function to initialize variables and start recursion
vector<string> Generate_Parentheses(int n) {
    vector<string> answer; // Stores all valid combinations
    string value;          // Tracks the current string being built
    backtrack(answer, value, 0, 0, n);
    return answer;
}

int main() {
    int n = 3;
    vector<string> x = Generate_Parentheses(n);
    
    // Print all generated valid combinations
    for (auto i : x) {
        cout << i << " ";
    }
    return 0;
}


// The Time complexity of the code is O(4n/root n)
// The space complexity of code is O(4n/root n)
