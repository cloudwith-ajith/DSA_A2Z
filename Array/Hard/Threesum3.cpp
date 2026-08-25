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
