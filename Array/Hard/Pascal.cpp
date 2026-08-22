/////pascal triangle
//The Main formula is combination formula nCr
// pascal is n-1Cr-1  
// the observation is the  if the r=3 we can only keep the n 3 time to bring the correct answer 


// This is the code for the picking up the correct element 

#include<bits/stdc++.h>   
using namespace std;

int position(int n, int col){
    long long ans = 1;   
    for(int i = 0; i < col; i++){
        ans = ans * (n-i);  
        ans = ans / (i+1);
    }
    return ans;
}


int main(){
    int n = 5;
    int col = 3;
    int result = position(n-1,col-1);
    cout<<result;
    return 0;
}


//// ------------------------------------code for the pascal triangle 

#include<bits/stdc++.h>
using namespace std;


vector<int> singleposition(int n){
    vector<int> temp;
    int ans = 1;
    temp.push_back(1);
    for(int i = 1; i < n; i++){
        ans = ans * (n - i) / i;
        temp.push_back(ans);
    }

    return temp;
} 

vector<vector<int>> pas(int n ){
    vector<vector<int>> ans;
    for(int i = 1; i < n; i++){
        ans.push_back(singleposition(i));
    }
    return ans;
}

int main(){
    int n = 7;
    vector<vector<int>> res =  pas(n);
    for(auto i : res ){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }
    return 0;
}

//--------------------------Pascal triangle picking the row 


#include<bits/stdc++.h>
using namespace std;


vector<int> singleposition(int n){
    vector<int> temp;
    int ans = 1;
    temp.push_back(1);
    for(int i = 1; i < n; i++){
        ans = ans * (n - i) / i;
        temp.push_back(ans);
    }

    return temp;
}

int main(){
    int n = 5;
    vector<int> res =  singleposition(n);
    for(auto i : res ){
       cout<<i<<" ";
    }
    return 0;
}
