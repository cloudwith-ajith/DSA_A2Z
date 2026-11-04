#include<bits/stdc++.h> // Includes all standard library headers in one go
using namespace std;

/**
 * Helper function to expand outward from a given center point 
 * and calculate the length of the palindrome found.
 * 
 * @param s     The input string.
 * @param left  The starting left index for expansion.
 * @param right The starting right index for expansion.
 * @return      The total length of the palindrome found.
 */
int helper_function(string s, int left, int right){

    // Keep expanding outward as long as:
    // 1. 'left' pointer stays inside the string boundary (>= 0)
    // 2. 'right' pointer stays inside the string boundary (< string length)
    // 3. The characters at both pointers match (mirror images match)
    while(left >= 0 && right < s.length() && s[left] == s[right]){
        left--;  // Move the left pointer one step to the left
        right++; // Move the right pointer one step to the right
    }

    // When the loop breaks, 'left' and 'right' have gone 1 step too far.
    // The standard distance formula is: (right - left + 1)
    // Adjusting for the 2 extra steps: (right - 1) - (left + 1) + 1 = right - left - 1
    return (right - left - 1);
}

/**
 * Main function to find the longest palindromic substring.
 * 
 * @param s The input string.
 * @return  The actual longest palindromic substring found.
 */
string Longest_Palindromic(string s) {
    int n = s.length(); // Get the total length of the string
    
    // Base Case: If the string is empty, the longest palindrome is an empty string
    if (n == 0) return ""; 

    int start = 0;  // Tracks the starting index of the longest palindrome found so far
    int maxlen = 0; // Tracks the length of the longest palindrome found so far

    // Iterate through every character in the string, treating each as a potential center
    for(int i = 0 ; i < n; i++){
        
        // Case 1: Check for ODD-length palindromes (e.g., "aba", center is 'b')
        // We pass the exact same index (i, i) as the left and right center.
        int len1 = helper_function(s, i, i);
        
        // Case 2: Check for EVEN-length palindromes (e.g., "abba", center is between 'b' and 'b')
        // We pass adjacent indices (i, i + 1) as the left and right center.
        int len2 = helper_function(s, i, i + 1);
        
        // Find the maximum length obtained from the current center 'i'
        int current_max = max(len1, len2);

        // If the palindrome found at this center is longer than our previous best
        if (current_max > maxlen){
            maxlen = current_max; // Update the maximum length

            // Calculate the starting position of this new longest palindrome.
            // Works flawlessly for both odd and even lengths due to integer division.
            start = i - (current_max - 1) / 2;
        }
    }

    // Extract and return the substring starting from 'start' with length 'maxlen'
    return s.substr(start, maxlen);
}

int main(){
    string s = "a12321b"; // Sample input string
    
    // Call the function and print the resulting longest palindrome ("12321")
    cout << Longest_Palindromic(s); 
    
    return 0; // Signal successful program execution
}



// The Time complexity of the code is O(N 2)
// The Space complexiyt of the code is O(1)
