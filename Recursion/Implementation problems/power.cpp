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

// The time complexity of the code is O(log n)
// The space complexity of the code is O(1)
