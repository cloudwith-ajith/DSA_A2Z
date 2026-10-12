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

//========================================================
// optimal way for the problem 

#include<bits/stdc++.h>
using namespace std;

bool twoDsearch(vector <vector <int>> &arr, int target){

    if(arr.empty() || arr[0].empty()){
        return false;
    }
    
    int n = arr.size();
    int m = arr[0].size();

    int low = 0;
    int high = m - 1;

    while(low < n && high >= 0){
        if(arr[low][high] == target){
            return true;
        }else if( arr[low][high] > target){
            high--;
        }else{
            low++;
        }
    }

    return false;
}



int main(){
    vector <vector <int> > arr = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 8;
    if(twoDsearch(arr,target)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}

// the time complexity of the code is O(m + n )
// the space complexity of the code is O(1)
