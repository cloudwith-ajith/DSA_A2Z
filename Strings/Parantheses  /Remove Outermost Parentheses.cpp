#include<bits/stdc++.h>
using namespace std;

string Remove_Outermost_Parentheses(string s){
    int n = s.size();
    int opened = 0;    // Tracks the current nesting depth level of parentheses
    string result = ""; // Stores the final processed string
    
    // Loop through each character of the string one by one
    for(int i = 0 ; i < n; i ++){
        
        // Case 1: We encounter an opening parenthesis '('
        if(s[i] == '('){
            // If opened > 0, it means we are already inside a group.
            // This '(' is NOT an outermost one, so we include it in the result.
            if(opened > 0){
                result += s[i];
            }
            // Increment the counter because we are going one level deeper
            opened++;
            
        // Case 2: We encounter a closing parenthesis ')'
        }else{
            // Decrement the counter first because we are stepping out of one level
            opened--;

            // After stepping out, if opened > 0, it means there are still outer layers left.
            // This ')' is NOT the final outermost one closing the group, so we include it.
            if(opened > 0){
                result += s[i];
            }
            // Note: If opened becomes 0, it was the outermost ')', so we skip it.
        }
    }

    return result; // Return the cleaned string with outer layers removed
}

int main(){
    string s = "((()))";
    // Prints the output. For "((()))", the outermost pair is removed, leaving "(())"
    cout<<Remove_Outermost_Parentheses(s);
    return 0;
}


// The Time complexity of the code is O(N)
// The Space complexity of the code is O(1)
