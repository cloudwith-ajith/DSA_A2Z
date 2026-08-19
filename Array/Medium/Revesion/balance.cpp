//-----------------stock buy and sell

#include<bits/stdc++.h>
using namespace std;

int stock(vector<int> &arr){
    int n = arr.size();
    int max_pro = 0;
    for(int i =0; i < n-1; i++){
        int profit = 0;
        for(int j = i+1; j < n; j++){
            profit = arr[j] - arr[i];
            max_pro = max(profit,max_pro);
        }
    }

    return max_pro;
}


int main(){
    vector <int> arr = {7,1,5,3,6,4};
    int result  = stock(arr);
    cout<<result;
    return 0;
}

///----optimal code 

#include<bits/stdc++.h>
using namespace std;

int stock(vector<int> &arr){
    int n = arr.size();
    int max_pro = 0;
    int minn = INT_MAX;
    
    for(int i = 0; i < n; i++){
        if(arr[i] < minn){
            minn = arr[i];
        }else{
            max_pro = max(max_pro, arr[i] - minn);
        }
    }

    return max_pro;
}


int main(){
    vector <int> arr = {7,1,5,3,6,4};
    int result  = stock(arr);
    cout<<result;
    return 0;
}

// the time complexity of the code is O(n)
// the space complexity of the code is O(1)


//-----------------------------rearrange array element by the sign 
// optimal way

#include<bits/stdc++.h>
using namespace std;

void sign(vector<int> &arr){
    int n = arr.size();
    vector <int> temp_arr(n,0);
    int pos = 0; 
    int neg =1;
    for(int i = 0;i < n; i++){
        if(arr[i] > 0){
            temp_arr[pos]  = arr[i];
            pos = pos + 2;
        }else{
            temp_arr[neg] = arr[i];
            neg = neg +2;
        }
    }

    for(auto i : temp_arr){
        cout<<i<<" ";
    }
}

int main(){
    vector <int> arr = {1, 2, -4, -5};
    sign(arr);
    return 0;
}

// the time complexity of the code is O(n)
// the space complexity of the cod is O(n)



//-----------next permutation

#include<bits/stdc++.h>
using namespace std;

void np(vector<int> &arr){
    
    next_permutation(arr.begin(),arr.end());
    for(auto i :arr){
        cout<<i<<" ";
    }
}


int main(){
    vector <int> arr = {1,3,2};
    np(arr);
    return 0;
}

//---optimal way 

#include<bits/stdc++.h>
using namespace std;

void np(vector<int> &arr){
    
    int p = -1;
    int n = arr.size();

    for(int i  = n-2; i >= 0; i--){
        if(arr[i] < arr[i+1]){
            p = i;
            break;
        }
    }
    
    if(p == -1){
        reverse(arr.begin(),arr.end());
        for(auto i :arr){
        cout<<i<<" ";
    }
    }

    for(int i = n - 1; i >= 0; i--){
        if(arr[i] > arr[p]){
            swap(arr[i],arr[p]);
            break;
        }
    }

    reverse(arr.begin()+p+1,arr.end());


    for(auto i :arr){
        cout<<i<<" ";
    }
}


int main(){
    vector <int> arr = {1,3,2};
    np(arr);
    return 0;
}

///---------------leader 
#include<bits/stdc++.h>
using namespace std;

void leader(vector<int> &arr){
    int n = arr.size();
    vector <int> temp;

    for(int i = 0; i< n; i++){
        bool flag = true;
        for(int j = i + 1; j < n; j++){
            if(arr[i] <= arr[j]){
                flag = false;
            }
        }
        
        if(flag){
            temp.push_back(arr[i]);
        }
    }

    for(auto i : temp){
        cout<<i<<" ";
    }

}

int main(){
    vector <int> arr = {4, 7, 1, 0};
    leader(arr);
    return 0;
}

//--------optimal 
#include<bits/stdc++.h>
using namespace std;

void leader(vector<int> &arr){
    int n = arr.size();
    int max = arr[n-1];
    vector <int> temp;
    
    temp.push_back(arr[n-1]);

    for(int i = n-2; i >= 0; i--){
        if(arr[i] > max){
            temp.push_back(arr[i]);
            max = arr[i];
        }
    }

    reverse(temp.begin(),temp.end());

    for(auto i : temp){
        cout<<i<<" ";
    }
}

int main(){
    vector <int> arr = {4, 7, 1, 0};
    leader(arr);
    return 0;
}

//--------------------spiral problem

#include<bits/stdc++.h>
using namespace std;

vector<int> spiral(vector<vector<int>> &arr){
    int n = arr.size();
    int m = arr[0].size();
    vector <int> temp;
    int top = 0;
    int left = 0;
    int right = m-1;
    int bottom = n-1;

    while(left <= right && top <= bottom){
        
        for(int i = left; i <= right; i++){
            temp.push_back(arr[top][i]);
        }
        
        top++;
        
        for(int i = top; i <= bottom; i++){
            temp.push_back(arr[i][right]);
        }
        
        right--;
        
        if(top <= bottom){
            for(int i = right; i >= left; i--){
                temp.push_back(arr[bottom][i]);
            }
            bottom--;
        }

        

        if(left <= right){
            for(int i = bottom; i >= top; i-- ){
                temp.push_back(arr[i][left]);
            }
            left++;
        }

        
    }

    return temp;
}

int main(){
    vector<vector<int>> arr = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };
    vector<int> result = spiral(arr);
    for(auto i : result){
        cout<<i<<" ";
    }
    return 0;
}


//--------------------Longest Consecutive Sequence in an Array
//------------------- brute force method
// the time complexity of the code is O(2n)
//------------the space complexity of the code is O(1)
#include<bits/stdc++.h>
using namespace std;

bool linear(vector <int> arr,int num){
    bool flag = false;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == num){
            flag = true;
        }
    }

    return flag;
}

int consective(vector <int> &arr){
    int n = arr.size();
    int max_counter = 0;
    
    for(int i = 0; i < n; i++){
        int counter = 1;
        int num = arr[i]+1;
        while(linear(arr, num)){
            counter++;
            num++;
        }

        max_counter = max(max_counter,counter);
    }

    return max_counter;
}

int main(){
    vector <int> arr = {100,4,200,1,3,2};
    int result = consective(arr);
    cout<<result;
    return 0;
}

//--- the better way 
// the timecpmplexit of the code is O(nlogn)

#include<bits/stdc++.h>
using namespace std;

int consective(vector <int> &arr){
    int n = arr.size();
    //sort the arr
    sort(arr.begin(),arr.end());
    int max_counter = 1;
    int counter =1;
    for(int i = 1; i < n; i++){
        if(arr[i]-1 == arr[i-1]){
            counter++;
        }else if(arr[i] == arr[i -1]){
            continue;
        }else{
            counter = 1;
        }
        max_counter = max(counter,max_counter);
    }
    return max_counter;
}

int main(){
    vector <int> arr = {100,4,200,1,3,2};
    int result = consective(arr);
    cout<<result;
    return 0;
}


////--------optimal wya for the problem

#include<bits/stdc++.h>
using namespace std;



int consective(vector <int> &arr){
    int n = arr.size();
    unordered_set <int> st(arr.begin(),arr.end());
    int max_counter = 0;
    for(int i = 0; i < n; i++){
        int start = 0;
        int counter = 1;
        if(st.find(arr[i] - 1) == st.end()){
            start = arr[i];

            while(st.find(start + 1) != st.end()){
                counter++;
                start++;
            }

            max_counter = max(max_counter,counter);
        }
    }

    return max_counter;
}

int main(){
    vector <int> arr = {100,4,200,1,3,2};
    int result = consective(arr);
    cout<<result;
    return 0;
}

// the time complexity of the code is O(n)
// the space complexity of the cpde is O(n)

/// set matrix 
//optimal way 

#include<bits/stdc++.h>
using namespace std;

void matrix(vector <vector<int>> &arr){
    int n = arr.size();
    int m = arr[0].size();
    int firstrow = true;
    int firstcol = true;

    for(int i = 0 ; i < m; i++){
        if(arr[0][i] == 0 ){
            firstrow = false;
        }
    }

    for(int i = 0 ; i < n; i++){
        if(arr[i][0] == 0 ){
            firstcol = false;
        }
    }

    for(int i = 1;i < n; i++){
        for(int j = 1; j < m; j++){
            if(arr[i][j] == 0){
                arr[i][0] = 0;
                arr[0][j] = 0;
            }
        }
    }

    for(int i = 1; i <n; i++){
        for(int j = 1; j < m; j++){
            if(arr[i][0] == 0 || arr[0][j] == 0){
                arr[i][j] = 0;
            }
        }
    }

    if(firstcol == false){
        for(int  i = 0; i < n; i++){
            arr[i][0] = 0;
        }
    }
    
    if(firstrow == false){
        for(int  i = 0; i < m; i++){
            arr[0][i] = 0;
        }
    }
}



int main(){
    vector <vector<int>> arr = {{1,1,1},{1,0,1},{1,1,1}};
    matrix(arr);
    for(auto  i : arr){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }
    return 0;
}
//---------------------better 
#include<bits/stdc++.h>
using namespace std;

void matrix(vector<vector<int>>&arr){
    int n = arr.size();
    int m = arr[0].size();
    vector<int> row(n,1);
    vector<int> col(m,1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 0){
                row[i] = 0;
                col[j] = 0; 
            } 
        }
    }

    for(int i = 0; i <n; i++){
        for(int j = 0; j < m; j++){
            if(row[i] == 0 || col[j] == 0){
                arr[i][j] = 0;
            }
        }
    }
} 


int main(){
    vector <vector<int>> arr = {{1,1,1},{1,0,1},{1,1,1}};
    matrix(arr);
    for(auto  i : arr){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }
    return 0;
}


//---------------90 degree rotation
#include<bits/stdc++.h>
using namespace std;

void deg90(vector<vector<int>> &mat){
    int n = mat.size();
    vector <vector <int>> temp (n , vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j <  n; j++){
            temp[j][n-i-1] = mat[i][j];
        }
    }
    for(auto i : temp){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }

    

}


int main(){
    vector <vector <int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    deg90(mat);
   
    return 0;
}
//--------- this is the code, just print the 90degree not touch the 
//---original array 


#include<bits/stdc++.h>
using namespace std;

void deg90(vector<vector<int>> &mat){
    int n = mat.size();
    //traveral the array 
    for(int i = 0; i < n ; i++){
        for(int j = i+1; j < n; j++){
            swap(mat[i][j],mat[j][i]);
        }
    }

    for(int i = 0; i < n; i++){
        reverse(mat[i].begin(),mat[i].end());
    }

}


int main(){
    vector <vector <int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    deg90(mat);

    for(auto i : mat){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }
   
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

int main(){
    vector <vector <int>> arr = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };
    vector <int> result = spiral(arr);
    for(auto i : result){
        cout<<i<<" ";
    }
    return 0;
}
