///----------------------revesion-----------------------------------//
//two sum 
#include<bits/stdc++.h>
using namespace std;


string two_sum(vector<int>arr,int target){
    int n = arr.size();
    for(int i = 0 ; i < n; i++){
        int sum = 0 ;
        for(int j = i+1 ; j < n; j++){ 
            sum = arr[i] + arr[j];
            if(sum == target){
                return "yes";
            }
        }
    }
    return "no";
}


int main(){
    vector <int> arr = {2,6,5,8,11};
    int target = 14;
    string res = two_sum(arr,target);
    cout<< res;
    return 0;
}

///----using the hash map 

#include<bits/stdc++.h>
using namespace std;

string two_sum(vector<int> arr,int target){
    int n  = arr.size();
    unordered_map <int,int> mpp;
    
    for(int i = 0 ; i < n; i++){
        int a = target - arr[i];
        
        if(mpp.find(a) != mpp.end()){
            return "yes";
        }
        if(mpp.find(a) == mpp.end()){
            mpp[arr[i]] = i;
        }
    }
    return "no";
}


int main(){
    vector <int> arr = {2,6,5,8,11};
    int target = 14;
    string res = two_sum(arr,target);
    cout<<res;
    return 0;
}

//-----------------------optimal way

#include<bits/stdc++.h>
using namespace std;

string two_sum(vector<int> arr,int target){
    int n = arr.size();
    int right = n-1;
    int left  = 0 ;
    //sort the array 
    sort(arr.begin(),arr.end());
    while(left < right){
        int sum = 0;
        sum = arr[left] +arr[right];
        
        if(sum > target){
            right--;
        }
        if(sum < target){
            left++;
        }
        if(sum == target){
            return "yes";
        }
    }
    return "no";
}

int main(){
    vector <int> arr = {2,6,5,8,11};
    int target = 14;
    string res = two_sum(arr,target);
    cout<<res;
    return 0 ;
}



