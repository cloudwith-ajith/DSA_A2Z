#include <iostream>
using namespace std;

int power_function(int num, int mul) {
    // Base case: anything to the power of 0 is 1
    if (mul == 0) {
        return 1;
    }
    
    // Recursive step: num * num^(mul - 1)
    return num * power_function(num, mul - 1);
}

int main() {
    int num = 2;
    int mul = 10;
    cout << power_function(num, mul); // Outputs: 1024
    return 0;
}

// The time complexity of the code is O(n)
// The space complexity of the code is O(1)


//-----------------------------------------------------Expo
#include <bits/stdc++.h> // Includes all standard C++ libraries (iostream, iomanip, etc.)
using namespace std;

// Function to calculate 'num' raised to the power 'p' (num^p)
// Time Complexity: O(log p) | Space Complexity: O(1)
double power_func(double num, int p) {
    double ans = 1.0;       // Stores the final result (starts at 1 because x^0 = 1)
    long long nn = p;       // Use 'long long' to prevent integer overflow if p is INT_MIN (-2147483648)

    // If the exponent is negative, convert it to positive for the loop
    if (nn < 0) {
        nn = -1 * nn;
    }

    // Loop until the remaining exponent 'nn' becomes 0
    while (nn) {
        if (nn % 2 == 0) {
            // If exponent is EVEN: square the base and cut the exponent in half
            // Example: 2^10 becomes (2^2)^5 = 4^5
            num = num * num;
            nn = nn / 2;
        } else {
            // If exponent is ODD: multiply the current base into 'ans' and reduce exponent by 1
            // Example: 4^5 becomes 4 * 4^4
            ans = num * ans;
            nn = nn - 1;
        }
    }

    // If the original exponent was negative, take the reciprocal (x^-p = 1 / x^p)
    if (p < 0) {
        return 1.0 / ans;
    }

    return ans; // Return the final computed power
}

int main() {
    double num = 2; // Base number
    int p = 20;     // Exponent (power)

    // 'fixed' prevents scientific notation (e.g., 1.04858e+06)
    // 'setprecision(0)' hides decimal places to print a clean whole number
    cout << fixed << setprecision(0) << power_func(num, p); // Outputs: 1048576

    return 0; // End of program
}
