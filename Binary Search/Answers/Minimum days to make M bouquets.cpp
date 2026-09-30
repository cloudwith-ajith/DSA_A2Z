// brute forece method ofor the problem 

#include<bits/stdc++.h>
using namespace std;

int Mbouquetarr(vector <int> &arr, int m, int k){
    int n = arr.size();
    long long roses = (long long)m * k; // Prevention against integer overflow
    if(roses > n){
        return -1;
    }
    
    int maxi = *max_element(arr.begin(),arr.end());
    int mins = *min_element(arr.begin(), arr.end()); 
    
    for(int i = mins; i <= maxi; i++){
        // FIX 1: Reset counts to 0 at the start of each day 'i'
        int boq = 0;
        int flower = 0; 
        
        for(int j = 0; j < n; j++){
            if(arr[j] <= i){
                flower++;
                if(flower == k){
                    boq++;
                    flower = 0;
                }
            } else {
                flower = 0;
            }
        }
        
        // FIX 2: Check if day 'i' is successful AFTER scanning the whole garden
        if(boq >= m){
            return i;
        }
    }
    return -1;
}

int main(){
    vector <int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int bouquet = 2;
    int flowers = 3;
    cout << Mbouquetarr(arr, bouquet, flowers); // Will correctly print 12 now
    return 0;
}

// the time complexity of the code is O(n)
// the space complexity of the code is O(1)
