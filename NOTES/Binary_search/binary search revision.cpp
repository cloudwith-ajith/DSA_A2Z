#include<bits/stdc++.h>
using namespace std;

int MaxOnes( vector<vector<int>> &arr){
    int n = arr.size();
    int m = arr[0].size();

    int answer = -1;
    int maxcount  = -1;

    for(int i = 0; i < n; i++ ){
        int count = 0;
        for(int  j = 0; j < m; j++){
            if(arr[i][j] == 1){
                count++;
            }
        }

        if(count > maxcount){
            maxcount = count;
            answer = i;
        }
    }

    return answer;
}


int main(){
    vector<vector<int>> mat = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1}
    };
    cout<<MaxOnes(mat);
    return 0;
}


-------------------------------optimal way for the problem 

#include<bits/stdc++.h>
using namespace std;

int MaxOnes(vector<vector<int>> &arr){
    int rows = arr.size();
    int colm = arr[0].size();

    int row = 0;
    int col = colm - 1;
    int answer = -1;

    while(row < rows && col >= 0){
        if(arr[row][col] == 1){
            answer = row;
            col--;
        }else{
            
            row++;
        }
    }

    return answer;

    
    
}

int main(){
    vector<vector<int>> mat = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1}
    };
    cout<<MaxOnes(mat);
    return 0;
}
-----------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

bool searchTwod(vector<vector <int>> &arr, int target){
    // Edge case: Empty matrix
    if(arr.empty() || arr[0].empty()) return false;

    int row = arr.size();
    int col = arr[0].size();

    int low = 0;
    int high = (row * col) - 1; // FIX 1: Set high to the last valid 0-based index

    while(low <= high){
        int mid = low + (high - low) / 2; // Best practice: Prevents potential integer overflow

        int r = mid / col;
        int c = mid % col;

        if(arr[r][c] == target){
            return true;
        }else if(arr[r][c] > target){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return false;
}          

int main(){
    vector <vector <int> > arr = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 2;
    if(searchTwod(arr, target)){
        cout << "true";
    }else{
        cout << "false";
    }
    return 0;
}

-------------------------------------------------------------------------------------------


#include<bits/stdc++.h>
using namespace std;

// FIX: Changed return type from 'int' to 'bool'
bool twod(vector <vector <int>> &arr, int target ){
    // Good practice: Check if matrix is empty
    if(arr.empty() || arr[0].empty()) return false;

    int rows = arr.size();
    int cols = arr[0].size();

    int row = 0;
    int col = cols - 1;

    while(row < rows && col >= 0){
        if(arr[row][col] == target){
            return true;
        }else if(arr[row][col] > target){
            col--; // Move left
        }else{
            row++; // Move down
        }
    }

    return false;
}

int main(){
    vector <vector <int> > arr = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 12;
    if(twod(arr, target)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}



-------------------------------------------------------------


#include<bits/stdc++.h>
using namespace std;

vector <int> peak(vector <vector <int> > &arr){
    int rows = arr.size();
    int colm = arr[0].size();

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < colm; j++){
            int up = -1;

            if(i  > 0 ){
                up = arr[i - 1][j];
            }

            int down = -1;
            if(i + 1 < rows ){
                down = arr[i + 1][j];
            }

            int left = -1;
            if(j > 0 ){
                left = arr[i][j - 1];
            }
            int right = -1;
            if(j + 1 < colm){
                right = arr[i][j + 1];
            }

            if(arr[i][j] > right && arr[i][j] > left && arr[i][j] > up && arr[i][j] > down){
                return {i , j};
            }
        }
    }

    return {-1, -1};
}



int main(){
    vector <vector <int> > arr = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32} 
    };
    vector <int> a = peak(arr);
    for(auto i : a){
        cout<<i<<" ";
    }
    return 0;
}

????????????????????????????????????????????optimal way 




#include<bits/stdc++.h>
using namespace std;

int helper_function(vector <vector <int> > &arr, int n, int m, int col){
    int maxi = -1;
    int answer = -1;

    for(int i = 0; i < n; i++){
        if(arr[i][col] > maxi){
            maxi = arr[i][col];
            answer = i;
        }
    }

    return answer;
}

vector <int> peak(vector <vector <int> > &arr){
    int rows = arr.size();
    int colm = arr[0].size();

    int low = 0;
    int high = colm - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        // FIX 1: Pass rows (not row) and colm correctly
        int row = helper_function(arr, rows, colm, mid); 

        // FIX 2: Check boundaries using 'mid' instead of 'row'
        int left = (mid > 0) ? arr[row][mid - 1] : -1;
        int right = (mid + 1 < colm) ? arr[row][mid + 1] : -1;

        if(arr[row][mid] > left && arr[row][mid] > right){
            return {row, mid};
        }
        // FIX 3: Update low and high to prevent an infinite loop
        else if (arr[row][mid] < right) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    
    return {-1, -1};
}

int main(){
    vector <vector <int> > arr = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32} 
    };
    vector <int> a = peak(arr);
    for(auto i : a){
        cout << i << " ";
    }
    return 0;
}



///-----------------------------------------------

upper bound

#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector <int> &arr, int x){
    int n = arr.size();
    int answer = -1;

    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid =  low + (high - low)/ 2;

        if(arr[mid] > x ){
            answer = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return answer;
}



int main(){
    vector <int> arr = {3,5,8,9,15,19};
    int x = 9;
    cout<<lowerbound(arr, x);
    return 0;
}



-------------------------------------------------
lower bound 


#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector <int> &arr, int x){
    int n = arr.size();
    int answer = -1;

    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid =  low + (high - low)/ 2;

        if(arr[mid] > x ){
            answer = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return answer;
}



int main(){
    vector <int> arr = {3,5,8,9,15,19};
    int x = 9;
    cout<<lowerbound(arr, x);
    return 0;
}


//----------------------------------------ciel  and the foor --------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

vector <int> lowerbound(vector <int> &arr, int x){
    int n = arr.size();
    int ciel = -1;

    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid =  low + (high - low)/ 2;

        if(arr[mid] >= x ){
            ciel = arr[mid];
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    

    low = 0 ;
    high = n - 1;
    int floor =  -1;
    while(low <= high){
        int mid = low + (high - low ) / 2;

        if(arr[mid] <= x){
            floor = arr[mid];
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return vector <int> { floor,ciel };
}



int main(){
    vector <int> arr = {3, 4, 4, 7, 8, 10};
    int x = 5;
    vector <int> c = lowerbound(arr, x);

    for(auto j : c){
        cout<<j<<" ";
    }
    return 0;
}


//-----------------------------------------------------------------------------------------------






