#include<bits/stdc++.h>
using namespace std;


void rotate_matrix(vector<vector<int>> &arr){
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> temparr(arr.begin(),arr.end());
    
    for(int i = 0;i < n; i++){
        for(int j = 0; j < m; j++){
            temparr[j][n-i-1] = arr[i][j];
        }
    }
    
    for(auto i: temparr){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }
}


int main(){
    vector<vector<int>> arr = {{0, 1, 1, 2}, {2, 0, 3, 1}, {4, 5, 0, 5}, {5, 6, 7, 0}};
    rotate_matrix(arr);    
    return 0;
}


///--------------ooptimal way to write the code 


#include<bits/stdc++.h>
using namespace std;

void rotate90(vector<vector<int>> &arr){
    int n =arr.size();
    //traversal
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    // reverse the row to get the correct degree
    for(int i = 0; i < n; i++){
        reverse(arr[i].begin(),arr[i].end());
    }

    for(auto i : arr){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }
}


int main(){
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    rotate90(arr);
    return 0;
}

// time complexity O(n*n+n) ---> O(n*n)
// space complexity O(1)
