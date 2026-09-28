// optimal solution for the problem


#include<bits/stdc++.h>
using namespace std;

// Helper function to calculate (num raised to the power of N)
int root_func(int num, int N){
    int ans = 1;
    for(int i = 1; i <= N; i++){
        ans = ans * num;
    }
    return ans;
}

// Function to find the Nth root of M using Binary Search
int Nthroot(int N, int M){
    // Define the search space boundaries
    int low = 1;
    int high = M;
    
    // Initialize answer to -1 (default if no perfect integer root exists)
    int answer = -1;

    while(low <= high){
        // Calculate the middle element of the current search space
        int mid = (low + high) / 2;
        
        // Calculate mid^N using our helper function
        int x = root_func(mid, N);
        
        // Case 1: Found the exact integer Nth root
        if(x == M){
            answer = mid; // Update the answer variable
            break;        // Exit the search space immediately
        }
        // Case 2: mid^N is too large, search the lower half
        else if(x > M){
            high = mid - 1;
        }
        // Case 3: mid^N is too small, search the upper half
        else{
            low = mid + 1;
        }
    }

    // Returns the exact root if found; otherwise returns -1
    return answer;
}

int main(){
    int N = 4;
    int M = 81;
    
    int result = Nthroot(N, M);
    cout << result; // Outputs 3 because 3^4 = 81
    
    return 0;
}


// The time complexity of the code is O(log n)
// The space complexity of the code isO(1)
