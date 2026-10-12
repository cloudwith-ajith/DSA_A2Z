// brute force method for the problem 

#include<bits/stdc++.h>
using namespace std;

// Function to find the row index with the maximum number of 1s
int Maxi_ones(vector < vector <int> > &arr){
    int n = arr.size();     // Get the total number of rows
    int m = arr[0].size();  // Get the total number of columns
    
    int count = 0;          // Stores the maximum count of 1s found so far
    int answer = -1;        // Stores the index of the row with the most 1s

    // Loop through each row of the matrix
    for(int i = 0; i < n; i++){
        int counter = 0;    // Reset counter to count 1s in the current row
        
        // Loop through each cell in the current row
        for(int j = 0 ;  j < m; j++){
            // If the cell value is 1, increment the current row's counter
            if(arr[i][j] == 1){
                counter++;
            }
        }

        // If the current row has more 1s than the maximum found so far
        if(counter > count){
            count = counter; // Update the maximum count of 1s
            answer = i;      // Update the answer to the current row index
        }
    }

    return answer; // Return the 0-indexed row number (-1 if no 1s exist)
}

int main(){
    // Initialize a 3x4 binary matrix (contains only 0s and 1s)
    vector <vector <int> > arr = {
        {0, 0, 1, 1}, // Row 0: has two 1s
        {0, 1, 1, 1}, // Row 1: has three 1s (Maximum)
        {0, 0, 0, 1}  // Row 2: has one 1
    };
    
    // Call the function and print the final row index to the console
    cout << Maxi_ones(arr); 
    
    return 0;
}

// The Time complexity of the code is O(n * m)
// Th space comeplxity of the code is O(1)


///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++better way 


#include<bits/stdc++.h>
using namespace std;

// Function to find the 0-indexed row with the maximum number of 1s using Binary Search
int Maxi_ones(vector < vector <int> > &arr){
    int n = arr.size();     // Get the total number of rows
    int m = arr[0].size();  // Get the total number of columns
    int answer = -1;        // Stores the index of the row with the most 1s
    int count = 0;          // Stores the maximum count of 1s found so far
    
    // Loop through each row of the matrix
    for(int i = 0;  i < n ; i++){
        int low = 0;
        int high = m - 1;
        int first = -1;     // Tracks the index of the very first '1' in the current row
        
        // Binary search to locate the first occurrence of 1 in the sorted row
        while(low <= high){
            int mid = (low + high) / 2;
            
            if(arr[i][mid] == 1){
                first = mid;     // A '1' is found, record its index
                high = mid - 1;  // Look further to the left for an even earlier '1'
            } else {
                low = mid + 1;   // If it's a '0', look to the right half
            }
        }

        // If 'first' remains -1, it means there are no 1s in this row.
        // Skip the calculation to prevent bugs.
        if (first == -1) {
            continue;
        }

        // Total 1s in the current row = Total columns (m) - index of first '1'
        int current_row_ones = m - first;

        // If the current row has strictly more 1s than our previous maximum
        if(count < current_row_ones){
            count = current_row_ones; // Update maximum count
            answer = i;               // Track this row index as the answer
        }
    }

    return answer; // Return the row index with the maximum 1s
}

int main(){
    // Initialize a 3x4 binary matrix where each row is sorted
    vector <vector <int> > arr = {
        {0, 0, 1, 1}, // Row 0: first '1' at index 2 -> 4 - 2 = 2 ones
        {0, 1, 1, 1}, // Row 1: first '1' at index 1 -> 4 - 1 = 3 ones (Maximum)
        {0, 0, 0, 1}  // Row 2: first '1' at index 3 -> 4 - 3 = 1 one
    };
    
    // Print the final result to the console
    cout << Maxi_ones(arr);
    
    return 0;
}



// The Time complexity of the code is O(n log m)
// The space complexity of the code is O(1)


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++optimal way for the problem 

#include<bits/stdc++.h>
using namespace std;

// Optimal Function to find the row with maximum 1s in O(N + M) time
int Maxi_ones(vector < vector <int> > &arr){
    int n = arr.size();     // Total number of rows
    int m = arr.size();  // Total number of columns
    int answer = - 1;       // Stores the row index with the maximum 1s

    int row = 0;            // Start at the first row (0)
    int col = m - 1;        // Start at the last column (top-right corner)

    // FIX: Changed row <= n to row < n to prevent out-of-bounds array access
    while(row < n && col >= 0){
        // If we find a 1, look left to see if there are more 1s in this row
        if(arr[row][col] == 1){
            answer = row;   // Record this row as the current best answer
            col--;          // Move left to the next column
        }
        // If we find a 0, we can skip the rest of this column and move down
        else{
            row++;          // Move down to the next row
        }
    }

    return answer; // Return the 0-indexed row with the maximum 1s
}

int main(){
    // Sorted row-wise binary matrix
    vector <vector <int> > arr = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1}
    };
    
    // Call the function and print the result
    cout << Maxi_ones(arr); // Outputs: 1
    return 0;
}


// The Time complexity of the code is O(n + m)
// The space complexity of the code is O(1)
