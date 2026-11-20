#include<bits/stdc++.h>
using namespace std;

// Global constant for modulo to keep large numbers within 64-bit integer limits
const long long MOD = 1e9 + 7;

// Calculates (base ^ exc) % MOD in O(log(exc)) time using Binary Exponentiation
long long power(long long base, long long exc) {
    // Base case: any number raised to the power of 0 is 1
    if (exc == 0) {
        return 1;
    }

    // Recursively find (base ^ (exc / 2))
    long long half = power(base, exc / 2);
    
    // Square the half result and apply modulo
    long long result = (half * half) % MOD;

    // If the exponent is odd, multiply by 'base' one extra time to account for integer division rounding
    if (exc % 2 == 1) {
        result = (result * base) % MOD;
    }

    return result;
}

// Counts total "good" digit strings of length n
long long Good_count(long long n) {
    // Even indices (0, 2, 4...) can hold 5 even digits: {0, 2, 4, 6, 8}
    long long evencount = (n + 1) / 2;
    
    // Odd indices (1, 3, 5...) can hold 4 prime digits: {2, 3, 5, 7}
    long long oddcount = n / 2;

    // Calculate total combinations for even and odd positions
    long long eve = power(5, evencount);
    long long od = power(4, oddcount);

    // Multiply both combinations and apply MOD to prevent overflow
    long long result = (eve * od) % MOD;

    return result;
}

int main() {
    long long n = 2; // Length of the digit string
    
    // Output the total count of good numbers of length n
    cout << Good_count(n) << endl; 
    
    return 0;
}


