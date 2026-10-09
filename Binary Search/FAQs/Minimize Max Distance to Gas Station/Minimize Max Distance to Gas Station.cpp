// optimal solution for the problem using the binary search 


##include<bits/stdc++.h>
using namespace std;

// This helper function counts how many NEW gas stations are required 
// if the maximum allowed distance between any two stations is set to 'dis'.
double helperfunction(vector<int> &arr, double dis){
    int n = arr.size();
    int ans = 0; // Stores the total number of new stations needed

    // Loop through every existing gap between adjacent initial gas stations
    for(int i = 0; i < n - 1; i++){
        double gap = arr[i + 1] - arr[i]; // Calculate the width of the current gap
        int station = gap / dis;          // Estimate how many stations fit in this gap

        // Edge case: If the gap is perfectly divisible by 'dis', 
        // the division accidentally counts the endpoint station which already exists.
        // Example: gap = 4, dis = 2 -> 4/2 = 2. But we only need 1 station at coordinate 2.
        if(station * dis == gap){
            station--; // Subtract 1 to avoid overcounting
        }

        ans += station; // Add the stations needed for this gap to our total count
    }

    return ans; // Return total stations required for this specific 'dis'
}

// Main logic implementing Binary Search on Answer
double GasStation(vector<int> &arr, int k ){
    int n = arr.size();
    double low = 0;  // The absolute minimum possible max distance (cannot be lower than 0)
    double high = 0; // The maximum possible distance initially present on the road

    // Find the largest gap among the starting gas stations to establish our upper search boundary
    for(int i = 0 ; i < n - 1; i++){
        high = max(high, (double)arr[i + 1] - arr[i]);
    }
    
    // Binary search condition for decimal points.
    // It will continue looping until the search space shrinks down to less than 1e-6 (0.000001).
    while(high - low > 1e-6){
        double mid = (low + high) / 2.00; // Calculate the middle distance to test

        // If the number of stations required for distance 'mid' is GREATER than allowed 'k',
        // it means 'mid' is too small of a distance. We must look in the upper half.
        if(helperfunction(arr, mid) > k){
            low = mid; // Shift the lower bound up
        }
        // If the stations required are less than or equal to 'k', 'mid' is a valid option.
        // We look in the lower half to see if we can find an even smaller maximum distance.
        else{
            high = mid; // Shift the upper bound down
        }
    }

    // When the loop terminates, high and low are virtually identical.
    // 'high' holds the minimized maximum distance accurate to 6 decimal places.
    return high; 
}

int main(){
    // Initial gas station coordinates on a straight highway
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    int k = 1; // Number of additional gas stations we are allowed to add
    
    // Set the output to show fixed floating points with 6 decimal places of precision
    cout << fixed << setprecision(6) << GasStation(arr, k) << endl;
    
    return 0;
}

// the time complexity of the code is O(log n(max_gap))
// the space complexity of the code is O(1)
