#include<bits/stdc++.h>
using namespace std;

// Function to calculate the sum of "beauty" of all substrings
// Beauty of a string = (Maximum frequency of a character) - (Minimum frequency of a character)
int Beauty_substring(string s){
    int n = s.length();
    int total_count = 0;

    // Outer loop: Defines the starting index of the substring
    for(int i = 0 ; i < n; i++){

        // Frequency array to keep track of character counts for substrings starting at index 'i'
        int freq[26] = {0};

        // Inner loop: Defines the ending index of the substring
        // By expanding 'j', we dynamically build and check every possible substring s[i...j]
        for(int j = i ;j < n; j++){
            
            // Increment the frequency of the current character
            freq[s[j] - 'a']++;

            int min_freq = INT_MAX;
            int max_freq = 0;

            // Find the maximum and minimum frequencies among characters present in the current substring
            for(int k = 0; k < 26; k++){
                if(freq[k] > 0){ // Only consider characters that have appeared at least once
                    min_freq = min(min_freq, freq[k]);
                    max_freq = max(max_freq, freq[k]);
                }
            }

            // Add the beauty of the current substring s[i...j] to the total count
            total_count += (max_freq - min_freq);
        }
    }

    return total_count;
}


int main(){
    string s = "xyx";
    
    // Output the total beauty sum for the string
    cout << "Total Beauty: " << Beauty_substring(s) << endl; 
    
    return 0;
}

// The time complexity of the code is O(N 2)
// The space complexity of the code is O(1)
