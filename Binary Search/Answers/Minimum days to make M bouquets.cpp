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


/// optimal way for the problem 

#include<bits/stdc++.h>
using namespace std;


int helperfunction(vector <int> &arr, int k, int day){
    int n = arr.size();
    int flower = 0;
    int buq = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] <= day){
            flower++;
            if(flower == k){
                buq++;
                flower = 0;
            }
        }else{
            flower = 0;
        }
    }

    return buq;
}



int Mbouquets(vector <int> &arr, int m, int k){
    int n = arr.size();
    int maxi = *max_element(arr.begin(),arr.end());
    int mini = *min_element(arr.begin(),arr.end());
    long long roses = (long long)m * k;
    if(n < roses){
        return -1;
    }
    int answer = 0;
    int low = mini;
    int high = maxi;
    while(low <= high){
        int mid = low + (high - low) / 2;
        int x = helperfunction(arr,k,mid);
        if(x >= m){
            answer = mid;
            high  = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return answer;
}


int main(){
    vector <int> arr = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;
    cout<<Mbouquets(arr, m, k);
    return 0;
}

// the time complexity of the code is O(max x log n)
// the space complexity of th code is O(1)
