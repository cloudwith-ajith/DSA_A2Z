// majority n/3;
#include<bits/stdc++.h>
using namespace std;

vector <int> majority(vector <int> &arr){
    int n = arr.size();
    vector <int> temp;
    int cnt1 = 0;
    int cnt2 = 0; 
    int el1 = INT_MIN;   
    int el2 = INT_MIN;   

    for(int i = 0; i <  n; i++){
        if(cnt1 == 0 && el2 != arr[i]){
            el1 = arr[i];
            cnt1++;
        }else if(cnt2 == 0 && el1 != arr[i]){
            el2 = arr[i];
            cnt2++;
        }else if(el1 == arr[i]){
            cnt1++;
        }else if(el2 == arr[i]){
            cnt2++;
        }else{
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0;
    cnt2 = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] == el1) cnt1++;
        if(arr[i] == el2) cnt2++;
    }

    if(cnt1 > n/3){
        temp.push_back(el1);
    }

    
    if(cnt2 > n/3){
        temp.push_back(el2);
    }

    return temp;
}


int main(){
    vector <int> arr = {1, 2, 1, 1, 3, 2, 2};
    vector <int> result = majority(arr);
    for(auto i : result){
        cout<<i<<" ";
    }
    return 0;
}
