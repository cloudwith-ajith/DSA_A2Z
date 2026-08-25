// three sum   brute force method 
// the time complexity of the code is three loop so 3^n
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threesum(vector<int> &arr){
    int n = arr.size();
    set <vector<int>> temp;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(arr[i]+arr[j]+arr[k] == 0){
                    vector<int> tp = {arr[i],arr[j],arr[k]};
                    sort(tp.begin(),tp.end());
                    temp.insert(tp);
                }
            }
        }
    }
    vector<vector<int>> res(temp.begin(),temp.end());
    return res;
}


int main(){
    vector <int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int >> result = threesum(arr);
    for(auto i : result){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }
    return 0;
}
//-------------//// better method to solve the THREESUM 3sum 

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threesum(vector<int> &arr){
    int n = arr.size();
    set <vector<int>> tempset;
    for(int i = 0; i < n; i++){
        set <int> eleset;
        for(int j = i + 1; j < n; j++){
            int k = -(arr[i] + arr[j]);
            if(eleset.find(k) != eleset.end()){
                vector<int> tp = {arr[i],arr[j],k};
                sort(tp.begin(),tp.end());
                tempset.insert(tp);
            }
            eleset.insert(arr[j]);
        }
    }
    vector<vector<int>> result(tempset.begin(),tempset.end());
    return result;
}


int main(){
    vector <int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int >> result = threesum(arr);
    for(auto i : result){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }
    return 0;
}

// the time complexity of the code is O(2^n)

