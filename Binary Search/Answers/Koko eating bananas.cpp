// brute force method for the problem 


#include<bits/stdc++.h>
using namespace std;

int KoKoBanana(vector <int> &arr, int h){
    int n = arr.size();
    int maxy = *max_element(arr.begin(), arr.end());

    for(int i = 1; i <= maxy; i++){
        int answer = 0 ;
        for(int j = 0; j < n; j++){
            // To find the ciel 
            answer += (arr[j] + (i - 1)) / i;
        }
        if(answer <= h){
            return i;
        }
    }

    return -1;
}


int main(){
    vector <int> arr = {30, 11, 23, 4, 20};
    int h = 5;
    cout<<KoKoBanana(arr,h);
    return 0;
}


// The time complexity of the code is O(max x n)
// The space complexity of the code is O(1)

///++++++++++++++++++++++optimal way for the problem 


#include<bits/stdc++.h>
using namespace std;

// 1. Changed return type to long long to prevent hour summation overflow
long long helperfunction(vector <int> &arr, int divisor, int n){
    long long sum = 0; // Changed to long long
    for(int i = 0; i < n; i++){
        sum += (arr[i] + (divisor - 1)) / divisor;
    }
    return sum;
}

int KoKoBanana(vector <int> &arr, int h ){
    int n = arr.size();
    int maxie = *max_element(arr.begin(), arr.end());
    
    // REMOVED the incorrect "if(n == h)" base case. 
    // The binary search loop natively handles this safely.

    int answer = -1;
    int low = 1;
    int high = maxie;
    
    while(low <= high){
        // 2. Prevented overflow during mid calculation
        int mid = low + (high - low) / 2; 
        
        long long x = helperfunction(arr, mid, n); // Changed to long long
        
        if (x <= h){
            answer = mid;
            high = mid - 1; // Try to look for a smaller speed
        } else {
            low = mid + 1;  // Speed is too slow, increase it
        }
    }

    return answer;
}

int main(){
    vector <int> arr = {30, 11, 23, 4, 20};
    int h = 5;
    cout << KoKoBanana(arr, h); // Correctly outputs 30
    return 0;
}



/// the time complexity of the code is O(max x log n)
/// the space complexity of the code is O(1)
