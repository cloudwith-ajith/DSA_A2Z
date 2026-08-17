

///-----------------------------two sum 

#include<bits/stdc++.h>
using namespace std;

bool two_sum(vector<int> &arr, int target){
    int n = arr.size();
    int right = n - 1;
    int left = 0;
    sort(arr.begin(),arr.end());
    while(left < right){
        int sum = arr[left]+arr[right];

        if(sum == target){
            return true;
        }else if( sum > target){
            right--;
        }else{
            left++;
        }
    }

    return false;
}

int main(){
    vector <int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    bool result = two_sum(arr,target);
    if(result){
        cout<<"yes";
    }else{
        cout<<"np";
    }
    return 0;
}


//---------better way with hash map
#include<bits/stdc++.h>
using namespace std;

bool two_sum(vector<int> &arr,int target){
    int n = arr.size();
    unordered_map <int,int> mpp;
    for(int i = 0 ; i < n; i++){
        if(mpp.find(target - arr[i]) != mpp.end()){
            return true;
        }

        mpp[arr[i]]++;
    }

    return false;
}

int main(){
    vector <int> arr = {2,6,5,8,11};
    int target = 14;
    bool result = two_sum(arr,target);
    if(result){
        cout<<"yes";
    }else{
        cout<<"No";
    }
    return 0;
}

////brute force 

#include<bits/stdc++.h>
using namespace std;

bool two_sum(vector<int> &arr,int target){
    int n = arr.size();
    for(int i = 0;i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i]+arr[j] == target){
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector <int> arr = {2,6,5,8,11};
    int target = 14;
    bool result = two_sum(arr,target);
    if(result){
        cout<<"yes";
    }else{
        cout<<"No";
    }
    return 0;
}
