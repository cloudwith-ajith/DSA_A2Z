// optimal way for the problem


#include<bits/stdc++.h>
using namespace std;

// Function to find the median of a row-wise sorted matrix
int Median(vector<vector <int>>&arr){
    int row = arr.size();
    int col = arr[0].size();

    // Initialize low and high to find the search space boundaries
    int low = INT_MAX;
    int high = INT_MIN;
    
    // The matrix is row-wise sorted. 
    // The absolute minimum will be in the first column, 
    // and the absolute maximum will be in the last column.
    for(int i = 0 ; i < row; i++){
        low = min(low, arr[i][0]);
        high = max(high, arr[i][col - 1]);
    }
    
    // 'required' is the number of elements that must be less than 
    // or equal to the median. For a matrix of size N, required = N / 2.
    int required = (row * col) / 2;
    
    // Binary search within the value range [low, high]
    while(low <= high){
        // Calculate mid safely to prevent integer overflow
        int mid = low + (high - low) / 2;
        int count = 0;

        // Count how many elements in the entire matrix are <= mid
        for(int i = 0 ; i < row; i++){
            // upper_bound finds the first element strictly greater than mid.
            // Subtracting .begin() gives the count of elements <= mid in this row.
            count += (int)(upper_bound(arr[i].begin(), arr[i].end(), mid) - arr[i].begin());
        }

        // If the count of elements <= mid is less than or equal to 'required',
        // then 'mid' is too small to be the median. Search the right half.
        if(count <= required){
            low = mid + 1;
        }
        // Otherwise, 'mid' could be the median or a valid candidate. 
        // Search the left half to see if a smaller valid number exists.
        else{
            high = mid - 1;
        }
    }

    // When low exceeds high, 'low' will point precisely to the median element.
    return low;
}

int main() {
    // Example matrix where each row is sorted individually
    vector<vector<int>> mat = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
 
    // Output the calculated median (Expected output: 5)
    cout << "The median is: " << Median(mat) << endl;
 
    return 0;
}

// The time  complexity of the code is O(n log m)
// the space  compelxity  of the code is O(1)
