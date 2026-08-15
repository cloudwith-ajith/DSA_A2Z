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

#include<bits/stdc++.h>
using namespace std;

void set_matrix(vector <vector<int>> &arr){
    //row
    int n = arr.size();
    int m = arr[0].size();
    int col0 = 1;
    for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){

        if(arr[i][j] == 0){

            arr[i][0] = 0;

            if(j == 0){
                col0 = 0;
            }
            else{
                arr[0][j] = 0;
            }
        }
    }
}
 

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(arr[i][0] == 0 || arr[0][j]== 0 ){
                arr[i][j] = 0;
            }
        }
    }
    //asign zero for the first rwo
    if(arr[0][0] == 0){
        for(int j = 0; j < m; j++){
            arr[0][j] = 0;
        }
    }
    //for column
    if(col0 == 0){
        for(int i = 0; i < n; i++){
            arr[i][0] = 0;
        }
    }
}




int main(){
    vector <vector<int>> arr = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    set_matrix(arr);
    for(auto i : arr){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }
    return 0;
}
