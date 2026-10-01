// brute force mothod

#include<bits/stdc++.h>
using namespace std;

// This function simulates the shipping process to find out 
// how many days are required for a given ship capacity.
int helperfunction(vector <int> &arr, int capacity){
    int n = arr.size();
    int load = 0;   // Tracks the total weight loaded onto the current day's ship
    int day = 1;    // Shipping takes at least 1 day, so we start counting at day 1

    for(int i = 0; i < n; i++){
        // Calculate what the weight would be if we added the current package
        int x = load + arr[i];

        // If adding the package exceeds the ship's maximum capacity
        if(x > capacity){
            day++;          // Send the full ship away and move to the next day
            load = arr[i];  // Start the new day's ship with the current package
        } else {
            load += arr[i]; // Otherwise, safely add the package to the current ship
        }
    }

    return day; // Return the total number of days used for this capacity
}

// This function finds the minimum ship capacity needed to deliver 
// all packages within the allowed number of days.
int Capacity_ship(vector <int> &arr, int day){
    int n = arr.size();
    
    // The ship capacity must be at least equal to the heaviest single package.
    // Otherwise, that heavy package could never be loaded.
    int start = *max_element(arr.begin(),arr.end());
    
    // The maximum possible capacity needed is the sum of all packages combined.
    // A ship with this capacity can carry everything in exactly 1 day.
    int end = accumulate(arr.begin(),arr.end(),0);

    // Linearly test every possible capacity from the minimum to the maximum
    for(int i = start; i <= end; i++){
        // Run the simulator to see how many days this specific capacity takes
        int d = helperfunction(arr, i);
        
        // Since we are checking from smallest capacity to largest, the very first 
        // capacity that meets or beats our target days is the minimum valid answer.
        if(d <= day){
            return i; // Found the lowest working capacity, return it immediately
        }
    }

    return -1; // Return -1 if no valid capacity is found (safety fallback)
}

int main(){
    // Sample package weights
    vector <int> arr ={1,2,3,4,5,6,7,8,9,10};
    
    // Target timeframe to deliver all packages
    int day = 5;
    
    // Run the function and print the final calculated minimum capacity
    cout << Capacity_ship(arr, day); 
    
    return 0;
}
