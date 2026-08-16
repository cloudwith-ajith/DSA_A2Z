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
