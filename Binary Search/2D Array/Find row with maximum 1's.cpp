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
