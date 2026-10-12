// brute force mothod 
#include<bits/stdc++.h>
using namespace std;

bool twoDsearch(vector <vector <int> > &arr, int target ){
    // 1. ALWAYS check for empty vectors first!
    if(arr.empty() || arr[0].empty()){
        return false;
    }

    // 2. Safe to access dimensions now
    int n = arr.size();
    int m = arr[0].size();

    // 3. Fixed loop condition
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == target){
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector <vector <int> > arr ={
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 11;
    if (twoDsearch(arr, target)){
          cout<< "true"; 
    }else{
          cout<<  "false";
    }
    return 0;
}

// The Time complexity of the code is O(n * m)
// The space complexity of the code is O(1)

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++optimal way for the problem 


#include<bits/stdc++.h>
using namespace std;

bool twoDsearch(vector <vector <int> > &arr, int target ){
    // 1. CRITICAL SAFETY CHECK: Always check for an empty matrix first.
    // Checking arr[0] before this would cause a segmentation fault if arr is empty.
    if(arr.empty() || arr[0].empty()){
        return false;
    }

    int n = arr.size();     // Number of rows
    int m = arr[0].size();  // Number of columns

    // 2. INITIALIZE BOUNDS: Treat the 2D matrix as a flat 1D array of size (n * m)
    int low = 0;
    int high = (n * m) - 1;

    // 3. BINARY SEARCH LOOP
    while(low <= high){
        // Calculate the middle index (prevents overflow in larger datasets)
        int mid = low + (high - low) / 2;

        // Map the 1D 'mid' index back to its 2D coordinates (row, col)
        int row = mid / m;  // Row index is obtained by integer division
        int col = mid % m;  // Column index is obtained by modulo operation

        // Check if the current element matches the target
        if(arr[row][col] == target){
            return true; // Target found!
        }
        // If current element is greater, the target must be in the left half
        else if(arr[row][col] > target){
            high = mid - 1;
        }
        // If current element is smaller, the target must be in the right half
        else {
            low = mid + 1;
        }
    }

    // Target was not found anywhere in the matrix
    return false;
}

int main(){
    // Sample sorted 2D matrix
    vector <vector <int> > arr ={
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    
    int target = 12; // 12 is not in the matrix, expected output: false
    
    // Call the search function and print the result
    if (twoDsearch(arr, target)){
          cout << "true"; 
    } else {
          cout << "false";
    }
    return 0;
}


// The time complexity of the code is O(n * m)
// The space complexity of the code is O(1)
