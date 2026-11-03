#include<bits/stdc++.h>
using namespace std;

// Function to convert a string representation of a number into a 32-bit signed integer
int String_Integer(string s){
    int n = s.length();
    int index = 0;
    
    // Step 1: Discard any leading whitespaces
    while(index < n && s[index] == ' '){
        index++;
    }

    // Step 2: Determine the sign of the number (+ or -)
    int sign = 1;
    if(index < n && (s[index] == '+' || s[index] == '-')){
        sign = (s[index] == '-') ? -1 : 1;
        index++; // Move to the next character after reading the sign
    }
    
    int result = 0;
    // Step 3: Traverse the string as long as the characters are valid numeric digits
    while(index < n && isdigit(s[index])){
        // Convert character digit (e.g., '5') to integer value (5) by subtracting '0'
        int digit = s[index] - '0';

        // Step 4: Check for 32-bit signed integer overflow/underflow before updating the result
        // INT_MAX / 10 is 214748364, and INT_MAX % 10 is 7
        if(result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)){
            // Return underflow limit (INT_MIN) or overflow limit (INT_MAX) based on the sign
            return (sign == -1) ? INT_MIN : INT_MAX;
        }

        // Step 5: Append the current digit to the running total
        result = result * 10 + digit;
        index++; // Advance to the next character
    }
    
    // Step 6: Apply the sign to the final calculated value and return it
    return sign * result;
}

int main(){
    // Test case with a leading whitespace and a negative number
    string s = " -12345";
    cout << String_Integer(s); // Expected output: -12345
    return 0;
}
