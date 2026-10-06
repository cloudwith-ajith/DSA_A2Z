// brute force method for the problem 



#include<bits/stdc++.h>
using namespace std;

bool helper_function(vector <int> &arr, int k, int i){
    int cows = 1;
    int n = arr.size();
    int last_placed = arr[0];
    for(int j = 1; j < n; j++){
        if(arr[j] - last_placed >= i){
            cows++;
            last_placed = arr[j];
        }
        if(cows >= k){
            return true;
        }
    }
    return false;
}

int Aggressive_cows(vector <int> &arr, int k ){
    // Fix 1: Always sort the array first so greedy placement works
    sort(arr.begin(), arr.end());

    int maxi = *max_element(arr.begin(),arr.end());
    int mini = *min_element(arr.begin(),arr.end());
    int end = maxi - mini;
    
    for(int i = 1; i <= end; i++){
        // If 'i' is impossible, the maximum possible distance was the previous one (i - 1)
        if(!helper_function(arr, k, i)){
            return i - 1;
        }
    }
    
    // Fix 2: If the loop never fails, the answer is the maximum possible range
    return end; 
}

int main(){
    vector <int> arr = {1, 2, 4, 8, 9};
    int k = 3;
    cout << Aggressive_cows(arr, k); // Correctly outputs 3
    return 0;
}



// The time complexity of the code is O(n x (max - min))
// the space complexity if the code is (1)
