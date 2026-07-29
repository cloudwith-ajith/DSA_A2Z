//Two_sum---->google
//-----------------------brute force
#include<bits/stdc++.h>
using namespace std;

bool two_sum(int arr[],int n,int target){
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] + arr[j] == target){
                return true;
            }
        }
    }
    
    return false;
    
}

int main(){
    int arr[] = {2,6,5,8,11};
    int n  = sizeof(arr)/sizeof(arr[0]);
    int target = 14;
    bool result = two_sum(arr,n,target);
    if(result == true){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
    return 0;
}
///-------------Time complexity O(2*n)
///--------------Space complexity O(1)

//---------------------------------for the return the {-1,-1}---------------------------//
#include<bits/stdc++.h>
using namespace std;

vector<int> two_sum(int arr[],int n,int target){
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] + arr[j] == target){
                return {arr[i],arr[j]};
            }
        }
    }
    
    return {-1,-1};
    
}

int main(){
    int arr[] = {2,6,5,8,11};
    int n  = sizeof(arr)/sizeof(arr[0]);
    int target = 14;
    vector<int> result = two_sum(arr,n,target);
    cout<<result[0]<<" + "<<result[1];
    return 0;
}

//same TC AND SC

//--------------------better version with prefix sum and the hashmap
//----------------------target - cuurent values, search in the map

//--------------------beter version using the prefix and the hash map 
#include<bits/stdc++.h>
using namespace std;

vector <int> two_sum(int arr[],int n,int target){
    unordered_map <int,int> mpp;
    for(int i = 0 ; i < n; i++){
        int a = target - arr[i];
        
        if(mpp.find(a) != mpp.end()){
            return {mpp[a],i};
        }
        
        if(mpp.find(a) == mpp.end()){
            mpp[arr[i]] = i;
        }
    }
    
    return {-1,-1};
}

int main(){
    int arr[] = {2,6,5,8,11};
    int target = 14;
    int n = sizeof(arr)/sizeof(arr[0]);
    vector <int> result = two_sum(arr,n,target);
    cout<<result[0]<<" "<<result[1];
    return 0;
}

