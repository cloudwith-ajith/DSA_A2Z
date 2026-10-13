// brute force for the problem 


#include<bits/stdc++.h> // Includes all standard C++ libraries at once
using namespace std;

// Function to find a "peak element" in a 2D matrix.
// A peak element is greater than all of its immediate neighbors (up, down, left, right).
vector <int> PeakinTwoD(vector <vector <int> > &arr){
    int n = arr.size();    // Get the number of rows in the matrix
    int m = arr[0].size(); // Get the number of columns (FIXED from arr.size() to support non-square grids)

    // Outer loop to iterate through each row
    for(int i = 0; i < n ; i ++){
        // Inner loop to iterate through each column inside that row
        for(int j = 0 ; j < m; j++){
            
            // 1. Check the UP neighbor
            int up = -1; // Default value if there is no element above
            if(i > 0){   // If we are not in the top row, get the value of the cell above
                up = arr[i - 1][j];
            }
            
            // 2. Check the DOWN neighbor
            int down = -1;    // Default value if there is no element below
            if(i + 1 < n){    // If we are not in the bottom row, get the value of the cell below
                down = arr[i + 1][j];
            }
            
            // 3. Check the LEFT neighbor
            int left = - 1;  // Default value if there is no element to the left
            if( j > 0){      // If we are not in the leftmost column, get the value of the cell to the left
                left = arr[i][j - 1];
            }

            // 4. Check the RIGHT neighbor
            int right = - 1;  // Default value if there is no element to the right
            if( j + 1 < m){   // If we are not in the rightmost column, get the value of the cell to the right
                right = arr[i][j + 1];
            }

            // If the current element is strictly greater than all four surrounding neighbors, it is a peak!
            if(arr[i][j] > right && arr[i][j] > left && arr[i][j] > up && arr[i][j] > down){
                return {i , j}; // Return the row index (i) and column index (j) of the peak element
            }
        }        
    }

    // Return {-1, -1} if no peak element is found in the matrix
    return {-1, -1};
}

int main(){
    // Create a sample 3x3 2D matrix (vector of vectors)
    vector <vector <int> > arr = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };
    
    // Call the function and store the coordinates of the peak element
    vector <int> i = PeakinTwoD(arr);
    
    // Loop through the coordinate vector and print the row and column index
    for(auto k : i){
        cout<<k<<" "; // Will output "1 1" because 30 at index (1,1) is greater than 20, 16, 21, and 14
    }
    
    return 0; // Signal successful program execution
}



// the time complexity of the code is O(n * m)
// the space complexity of the code is O(1)

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++optimal way for the  problem 

#include<bits/stdc++.h> // Includes all standard C++ libraries
using namespace std;

// Helper function to find the row index of the maximum element in a given column.
// Parameters: 
// - arr: the 2D grid matrix
// - n: the total number of rows (passed as 'm' in parameter, which represents row count)
// - mid: the index of the column we are scanning
int helper_function(vector <vector <int> > &arr, int n, int mid){
    int answer = - 1; // Stores the row index of the maximum value found
    int maxi = -1;    // Stores the maximum value found so far in the column

    // Loop through all rows in this specific column
    for(int i = 0 ; i < n ; i++){
        if(arr[i][mid] > maxi){
            maxi = arr[i][mid]; // Update the maximum value
            answer = i;         // Record the row index
        }
    }

    return answer; // Return the row index of the largest element in this column
}

// Main function to find a peak element in a 2D matrix using Binary Search on columns.
vector <int> PeakinTwoD(vector <vector <int> > &arr){
    int n = arr.size();       // Get total number of rows
    int m = arr[0].size();    // Get total number of columns (correctly handles non-square matrices)

    int low = 0;              // Starting boundary of columns for binary search
    int high = m - 1;         // Ending boundary of columns for binary search

    // Run binary search loop across the columns
    while(low <= high){
        int mid = (low + high) / 2; // Calculate the middle column index
        
        // Find the absolute maximum element in this middle column.
        // Because it is the maximum in its column, it is automatically greater than or equal to its top and bottom neighbors.
        int row = helper_function(arr, n, mid);

        // Fetch left and right neighbors, using ternary operators to safely handle out-of-bounds cases
        int left = mid - 1 >= 0 ? arr[row][mid - 1] : -1;  // Neighbor to the left
        int right = mid + 1 < m ? arr[row][mid + 1] : -1;  // Neighbor to the right

        // If the current element is greater than both its left and right neighbors, it's a 2D peak!
        if(arr[row][mid] > left && arr[row][mid] > right){
            return {row, mid}; // Return the {row, column} coordinates of the peak
        }
        // If the left neighbor is larger, a peak must exist somewhere in the left half
        else if (arr[row][mid] < left){
            high = mid - 1; // Shift binary search window to the left
        }
        // If the right neighbor is larger (or equal), a peak must exist somewhere in the right half
        else{
            low = mid + 1;  // Shift binary search window to the right
        }
    }

    return {-1, -1}; // Fallback return statement (will not be reached if elements are positive/distinct)
}

int main(){
    // Initialize a sample 3x3 matrix
    vector <vector <int> > arr = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };
    
    // Execute the peak finding algorithm
    vector <int> i = PeakinTwoD(arr);
    
    // Print out the coordinates of the found peak
    for(auto k : i){
        cout<<k<<" "; // Will output "1 1" because 30 at index (1,1) is greater than 20, 16, 21, and 14
    }
    return 0;
}




// the time complexity of th code is O(n log m)
// the tie complexity of the code is O(1)

