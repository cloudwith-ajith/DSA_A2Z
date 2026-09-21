// brute force method // linear search 

#include<bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int x){
    int n = arr.size();
    int ind = -1;
    for(int i = 0 ; i < n; i++){
        if(arr[i] == x){
            ind = i;
        }
    }
    return ind;
}


int main(){
    vector <int> arr = {1, 3, 5, 7, 9, 11};
    int target = 7;
    int result = search(arr,target);
    cout<< result;
    return 0;
}

// The Time complexity of the code is O(n)
// The Space complexity of the code is O(1)
