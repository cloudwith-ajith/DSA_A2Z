#include<bits/stdc++.h>
using namespace std;

void set_matrix(vector<vector<int>> &arr){
    int n = arr.size();
    int m = arr[0].size();
  
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 0){
                for(int row = 0; row < n; row++){
                    if(arr[row][j] != 0){
                        arr[row][j] = -1;
                    }
                }

                for(int col = 0; col < m; col++){
                    if(arr[i][col] != 0){
                        arr[i][col] = -1;
                    }
                }
            }
        }
    }

    // reset the -1 into the 0
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == -1){
                arr[i][j] = 0;
            } 
        }
    }
}



int main(){
    vector<vector<int>> arr = {{1,1,1},{1,0,1},{1,1,1}};
    set_matrix(arr);
    for(auto i : arr){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }
    return 0;
}
  
///----------------------- the better solution for the problem   

#include<bits/stdc++.h>
using namespace std;

void set_matrix(vector<vector<int>> &arr){
    int n = arr.size();
    int m = arr[0].size();

    vector<int> row_arr(n,0);
    vector<int> col_arr(m,0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 0){
                row_arr[i] = 1;
                col_arr[j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(row_arr[i] == 1 || col_arr[j] == 1){
                arr[i][j] = 0;
            }
        }
    }
}



int main(){
    vector<vector<int>> arr = {{1,1,1},{1,0,1},{1,1,1}};
    set_matrix(arr);
    for(auto i : arr){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }
    return 0;
}

// Time Complexity: O(n*m)
// Space Complexity: O(n+m)
