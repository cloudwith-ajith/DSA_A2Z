// brute force method for the problem 

#include<bits/stdc++.h>
using namespace std;

int Kth_element(vector <int> &arr1, vector <int> &arr2,int k ){
    int n = arr1.size();
    int m = arr2.size();
    vector <int> temp ;
    for(int i = 0; i < n; i++){
        temp.push_back(arr1[i]);
    }
    for(int i = 0; i < m; i++){
        temp.push_back(arr2[i]);
    }

    sort(temp.begin(),temp.end());

    return temp[k - 1];
}


 int main(){
     vector <int> arr1 = {2,3,6,7,9};
     vector <int> arr2 = {1,4,8,10};
     int k = 5;
     cout<<Kth_element(arr1, arr2, k);
     return 0;
 }

// the time complexity of the code is O(n+m log(n + m))
// the space complexity of the code is O(n+m)


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++better way to solve the problem is 
// using the two pointer method using the merge sort method

// optimal way for the problem is binary seach 


#include<bits/stdc++.h>
using namespace std;

// Function to find the k-th smallest element from two sorted arrays
int KthElement(vector <int> &arr1, vector <int> &arr2, int k){
    
    // RULE 1: Always binary search on the smaller array.
    // If arr1 is larger, swap them by calling the function with swapped arguments.
    // This keeps the time complexity optimized at O(log(min(n, m))).
    if(arr1.size() > arr2.size()){
        return KthElement(arr2, arr1, k);
    }

    int n = arr1.size(); // Total number of elements in the first array
    int m = arr2.size(); // Total number of elements in the second array
    
    // RULE 2: Set safe boundaries for Binary Search to avoid runtime crashes.
    
    // Why max(0, k - m)? If k is larger than the total size of arr2 (m), 
    // even taking ALL elements of arr2 isn't enough. We MUST take at least (k - m) elements from arr1.
    int low = max(0, k - m); 
    
    // Why min(k, n)? We can never take more elements from arr1 than its actual size (n),
    // and we also cannot take more than 'k' elements in total.
    int high = min(k, n);

    // Start Binary Search to find the correct partition point (cut)
    while(low <= high){
        
        // cut_1: How many elements we are picking from arr1's left side
        int cut_1 = (low + high) / 2;
        
        // cut_2: The remaining elements needed to make a total of 'k' elements
        int cut_2 = k - cut_1;

        // RULE 3: Define boundary elements for the split, managing edge cases (out of bounds)
        
        // If cut_1 is 0, nothing is picked from arr1's left side -> set to minimum possible integer
        int left1 = (cut_1 == 0) ? INT_MIN : arr1[cut_1 - 1];
        
        // If cut_1 is equal to array size n, nothing is left on arr1's right side -> set to maximum integer
        int right1 = (cut_1 == n) ? INT_MAX : arr1[cut_1];
        
        // If cut_2 is 0, nothing is picked from arr2's left side -> set to minimum possible integer
        int left2 = (cut_2 == 0) ? INT_MIN : arr2[cut_2 - 1];
        
        // If cut_2 is equal to array size m, nothing is left on arr2's right side -> set to maximum integer
        int right2 = (cut_2 == m) ? INT_MAX : arr2[cut_2];

        // RULE 4: Validate if the current cross-partition is sorted correctly
        if(left1 <= right2 && left2 <= right1){
            // If valid, the largest element in our left partition is our exact k-th element!
            return max(left1, left2);
            
        } else if(left1 > right2){
            // If left1 is too big, it means we took too many elements from arr1.
            // Move our search window to the left (reduce elements from arr1).
            high = cut_1 - 1;
            
        } else {
            // If left2 is too big (i.e., left2 > right1), we took too few elements from arr1.
            // Move our search window to the right (take more elements from arr1).
            low = cut_1 + 1;
        }
    }

    // Default return statement if no k-th element is found (theoretically unreachable if k is valid)
    return -1;
}

int main(){
    // Input sorted arrays
    vector <int> arr1 = {100, 112, 256, 349, 770};
    vector <int> arr2 = {72, 86, 113, 119, 265, 445, 892};
    
    int k = 7; // We want to find the 7th smallest element
    
    // Call the function and print the result (Expected: 256)
    cout << KthElement(arr1, arr2, k); 
    
    return 0;
}


// The time complexity of the code is O(log min(n,m))
// The space complexiyt of the code is O(1)
