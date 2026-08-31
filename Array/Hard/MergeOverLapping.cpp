// The brute force method for the problem is using the 2 loops 
#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> MOL(vector<vector<int>> &arr){
    int n = arr.size();
    //sort the array
    sort(arr.begin(),arr.end());
    vector<vector<int>> temp;
    for(int i = 0; i < n;){
        int start = arr[i][0];
        int end = arr[i][1];
        int j = i + 1;
        while( j < n && arr[j][0] <= end){
            end =  max(end, arr[j][1]);
            j++; 
        }
        temp.push_back({start,end});
        i = j;
    }

    return temp;
}

int main(){
    vector<vector<int>> arr = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> result = MOL(arr);
    for(auto i : result){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    } 
    return 0;
}
