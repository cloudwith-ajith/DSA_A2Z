// Better solution 

#include<bits/stdc++.h>
using namespace std;

// Function to find the minimized maximum distance between adjacent gas stations
double GasStation(vector <int> &arr, int k ){
    int n = arr.size();
    
    // Tracks how many new gas stations are placed between section i and i+1
    vector <int> howmany (n-1, 0);
    
    // Max-Heap to store pairs of: {current_section_length, section_index}
    // The heap always keeps the largest gap at the very top.
    priority_queue <pair<double,int>> pq;

    // Step 1: Calculate initial distances between all adjacent stations
    // and push them into the priority queue.
    for(int i = 0 ; i < n - 1; i++){
        pq.push({(double)(arr[i + 1] - arr[i]), i});
    }

    // Step 2: Pick the largest available gap and place a station there 'k' times
    for(int i = 1; i <= k; i++){
        // Get the section with the largest gap
        auto top = pq.top();
        pq.pop();
        
        int secindex = top.second; // Index of the chosen section
        howmany[secindex]++;       // Increment the station count for this section
        
        // Calculate the original total length of this specific section
        double original = arr[secindex + 1] - arr[secindex];
        
        // Find the new reduced distance after dividing the section into equal parts
        double newdiff = original / (howmany[secindex] + 1);
        
        // Push the updated gap back into the heap to keep it sorted
        pq.push({newdiff, secindex});
    }

    // Step 3: The top of the heap now contains the minimized maximum distance
    return pq.top().first;
}

int main(){
    // Hardcoded initial coordinates of the existing gas stations
    vector <int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Total number of new gas stations we are allowed to add
    int k = 1;
    
    // Set fixed floating-point notation for clear output formatting
    cout << fixed << setprecision(6);
    
    // Execute the function and display the result
    cout << "Minimized Maximum Distance: " << GasStation(arr, k) << endl;
    
    return 0;
}


// the time complexity of the code is O(nlogn + k logn)
// the space complexity of the code is O(1)
