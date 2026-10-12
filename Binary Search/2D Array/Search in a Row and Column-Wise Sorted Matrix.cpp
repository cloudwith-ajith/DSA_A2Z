


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
