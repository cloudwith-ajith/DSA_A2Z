//brute force method 

#include<bits/stdc++.h>
using namespace std;

vector<int> ReMis(vector<int> &arr){
    int n = arr.size();
    int missing = -1;
    int repeating = -1;

    for(int i = 1; i < n+1; i++){
        bool flag = true;
        int counter = 0;
        for(int j  = 0; j < n; j++){
            if(i == arr[j]){
                flag = false;
                counter++;
            }
        }

        if(flag){
            missing = i;
        }
        
        if(counter == 2){
            repeating = i;
        }
    }

    vector<int> res = {repeating,missing};
    return res;
}

int main(){
    vector <int> arr = {1, 2, 3, 6, 7, 5, 7};
    vector<int> result = ReMis(arr);
    for(auto i : result){
        cout<<i<<" ";
    }
    return 0;
}
