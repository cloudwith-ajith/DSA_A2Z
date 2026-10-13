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

