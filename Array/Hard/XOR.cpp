
//----------------------- count the number of subarray with XOR sum 

// brute force method

#include<bits/stdc++.h>
using namespace std;

int xr(vector <int> &arr, int k){
    int n = arr.size();
    int counter = 0 ;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum = sum ^ arr[j];
            if(sum == k){
                counter++;
            }
        }
    }
    return counter;
}

int main(){
    vector <int> arr  = {5, 6, 7, 8, 9};
    int k =  5;
    int result = xr(arr, k);
    cout<<result;
    return 0;
}

// the time complexity of the code is O(n^2)
// the space complexity of the code is O(1)


// ---- optimal way for the code 
// The formula of the code is 
// currentprefix of the array = x ^ k 
// need to find the x = currentprefix ^ k 
// if there is x in the hashmap then increment the counter

#include<bits/stdc++.h>
using namespace std;

int xrr(vector<int> &arr, int k ){
    int n =  arr.size();
    int counter  = 0 ;
    int xr = 0;
    unordered_map <int, int> mpp;
    mpp[xr]++;

    for(int i = 0; i < n; i++){
        //current prefix
        xr = xr ^ arr[i];
        int x = xr ^ k;
        counter += mpp[x];
        mpp[x]++;
    }

    return counter;
}


int main(){
    vector <int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    int result = xrr(arr,k);
    cout<<result;
    return 0;
}
