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

