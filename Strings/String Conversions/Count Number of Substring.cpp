#include<bits/stdc++.h> // Includes all standard library headers (useful for competitive programming)
using namespace std;

// Function to count substrings that can form a palindrome
int count_substring(string s){
    int n = s.length(); // Get the length of the input string
    int vaild_count  = 0; // Initialize a counter for valid substrings

    // Outer loop: Defines the starting index 'i' of the substring
    for(int i = 0 ; i < n; i++){
        
        // Middle loop: Defines the ending index 'j' of the substring
        for(int j = i; j < n; j++){
            
            // Frequency array for characters 'a' through 'j' (since size is 10)
            // It resets to 0 for every new substring being checked
            int arr[10] = {0};

            // Inner loop: Iterates through characters from index 'i' to 'j'
            for(int k = i; k <= j; k++){
                // Increment the frequency of the current character.
                // Subtracting 'a' converts characters 'a'-'j' into indices 0-9.
                arr[s[k] - 'a']++;
            }

            int odd_cout = 0; // Initialize counter for characters with odd frequencies
            
            // Loop through the frequency array to count how many characters appear an odd number of times
            for( auto m : arr){
                if(m % 2 == 1){
                    odd_cout++; // Increment if the count is odd
                }
            }

            // A string can be rearranged into a palindrome if it has at most ONE character with an odd count
            if(odd_cout <= 1){
                vaild_count++; // It's a valid substring, increment the total count
            }
        }
    }

    return vaild_count; // Return the total number of valid substrings found
} 

int main(){
    string s = "aabb"; // Define a sample test string
    
    // Call the function and print the result to the console
    cout << count_substring(s); 
    
    return 0; // Signal successful program termination
}


// The Time complexity of the code is O(N3)
// The space complecity of the code is O(n)

