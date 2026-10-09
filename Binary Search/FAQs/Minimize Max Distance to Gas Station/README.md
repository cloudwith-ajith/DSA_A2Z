# Minimise Maximum Distance to Gas Stations

## 📝 Problem Statement
You are given an integer array `arr` of size `N`, representing the positions of existing gas stations on a straight road. You are also given an integer `k`, which represents the number of new gas stations you need to add to the road. 

Your task is to place these `k` new stations such that the **maximum distance between any two consecutive gas stations is minimised**. Return this minimised maximum distance.

---

## 💡 Approaches Explained

### 1. Brute Force (Greedy Approach)
* **Concept:** Place the `k` stations one by one. In each iteration, scan all existing gaps on the road, calculate their current lengths, and place the next station in whichever gap is currently the largest.
* **Time Complexity:** \(\mathcal{O}(k \times N)\) — Causes **Time Limit Exceeded (TLE)** for large inputs.
* **Space Complexity:** \(\mathcal{O}(N)\)

### 2. Better Approach (Max-Heap / Priority Queue)
* **Concept:** Instead of scanning all gaps manually in every iteration, use a Max-Heap (`priority_queue`). The heap automatically keeps the largest gap at the top. We extract the largest gap, increment its station count, recalculate its new split size, and push it back.
* **Time Complexity:** \(\mathcal{O}(k \log N)\)
* **Space Complexity:** \(\mathcal{O}(N)\)

### 3. Optimal Approach (Binary Search on Answer) 🚀
* **Concept:** Instead of placing stations sequentially, we use **Binary Search** to guess the target maximum distance (`mid`). 
  * We establish our search space between `low = 0.0` and `high = largest original gap`.
  * For every guessed distance `mid`, a helper function counts how many stations are required to maintain that maximum spacing using the mathematical formula: `required += (int)(gap_size / mid)`.
  * If the required stations exceed `k`, the distance is too small (`low = mid`). Otherwise, we try to find an even smaller valid distance (`high = mid`).
* **Time Complexity:** \(\mathcal{O}(N \log(\text{Max\_Distance}))\)
* **Space Complexity:** \(\mathcal{O}(1)\) — Most memory efficient.

---

## 🛠️ Optimal C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Solution {
private:
    // Helper function to count how many stations are needed to maintain a max distance of 'dist'
    int numberOfGasStationsRequired(vector<int>& arr, long double dist) {
        int required = 0;
        
        // Check every existing gap between stations
        for (int i = 0; i < arr.size() - 1; i++) {
            // Count how many sections of 'dist' length fit inside the gap
            required += (int)((arr[i + 1] - arr[i]) / dist);
        }
        
        return required;
    }

public:
    // Optimal approach using binary search to find the minimised maximum distance
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        long double low = 0;
        long double high = 0;
        
        // Find the absolute maximum gap to act as the upper search boundary
        for (int i = 0; i < arr.size() - 1; i++) {
            high = max(high, (long double)(arr[i + 1] - arr[i]));
        }
        
        // Loop runs until the search boundaries converge to 6 decimal places of precision
        while (high - low > 1e-6) {
            // Guess the middle distance
            long double mid = low + (high - low) / 2.0;
            
            // Validate if the guessed distance fits within our allowed k stations
            if (numberOfGasStationsRequired(arr, mid) > k) {
                // Too many stations needed, distance is too strict (make distance larger)
                low = mid;
            } else {
                // Feasible distance, attempt to restrict it further (make distance smaller)
                high = mid;
            }
        }
        
        // Return the precise finalized upper bound
        return high;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    
    long double ans = obj.minimiseMaxDistance(arr, k);
    
    // Output the result fixed to 6 decimal places
    cout << fixed << setprecision(6) << ans << endl;
    
    return 0;
}
```

---

## 📊 Complexity Analysis (Optimal Solution)

| Metric | Complexity | Description |
| :--- | :--- | :--- |
| **Time Complexity** | $\mathcal{O}(N \log(\text{Max\_Distance}))$ | The binary search takes logarithmic iterations relative to precision, and each step scans the array of size $N$. |
| **Space Complexity** | $\mathcal{O}(1)$ | No extra space or data structures are allocated. |
