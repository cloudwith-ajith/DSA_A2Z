#include<bits/stdc++.h>
using namespace std;


void spiral(vector<vector<int>> & arr){
    int n = arr.size();
    int m = arr[0].size();
    //we neeed left-->right-->bottom-->top
    int top = 0;
    int left = 0 ;
    int right = m - 1;
    int bottom = n -1;
    vector <int> temp;

    while(left <= right && top <= bottom){
        //left --> right
        for(int i = left; i <= right; i++){
            temp.push_back(arr[top][i]);
        }
        top++;
        //right --> bottom
        for(int i = top; i <= bottom; i++ ){
            temp.push_back(arr[i][right]);
        }
        right--;
        // store bottom row from right to left (if exists)
        if(top <= bottom){    
            for(int i = right; i >= left; i--){
                temp.push_back(arr[bottom][i]);
            }
            bottom--;
        }// store left column from bottom to top (if exists)
        if(left <= right){
            for(int i = bottom; i >= top; i--){
                temp.push_back(arr[i][left]);
            }
            left++;
        }
    }
    for(auto i : temp){
        cout<<i<<" ";
    }
}



int main(){
    vector<vector<int>> arr ={
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };
    spiral(arr);
    return 0;
}
///---------------Time complexity is O(n*m)
///---------------Space somplexity is O(1)

