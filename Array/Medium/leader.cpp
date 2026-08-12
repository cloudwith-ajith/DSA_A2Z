
///---------------------------leader-------
//brute force method ---i have tried 
#include<bits/stdc++.h>
using namespace std;

list <int> leader(vector<int>arr){
    list <int> temp;
    int n = arr.size();
    temp.push_front(arr[n-1]);
    for(int i = n - 2; i >= 0; i--){
        int flag = 0;
        for(int j = i + 1; j < n; j++){
            if(arr[i] <= arr[j]){
                flag++;
            }
        }
        if(flag == 0){
            temp.push_front(arr[i]);
        }
    }

    return temp;
}


int main(){
    vector <int> arr = {4, 7, 1, 0};
    list <int> result = leader(arr);
    for(auto i : result){
        cout<<i<<" ";
    }
    return 0;
}
