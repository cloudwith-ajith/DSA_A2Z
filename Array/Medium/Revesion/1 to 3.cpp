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

////////sort 0 1 2 in the array 
#include<bits/stdc++.h>
using namespace std;

void sot(int arr[],int n){
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == 0 ){
            count0++;
        }else if(arr[i] == 1){
            count1++;
        }else{
            count2++;
        }
    }
    
    for(int i = 0 ; i < count0; i++){
        arr[i] = 0;
    }
    
    for(int i = count0 ; i < count0+count1; i++){
        arr[i] = 1;
    }
    
    
    for(int i = count0+count1 ; i < n; i++){
        arr[i] = 2;
    }
}


int main(){
    int arr[] = {1, 0, 2, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    sot(arr,n);
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}



///------------------majority

//----burte force method

#include<bits/stdc++.h>
using namespace std;

int majority(int arr[],int n){
    for(int i = 0; i < n; i++){
        int num_count = 0;
        for(int j = 0; j < n; j++){
            if(arr[i] == arr[j]){
                num_count++;
            }
        }
        if(num_count > (n/2)){
            return arr[i];
        }
    }
    return -1;
}


int main(){
    int arr[] = {7,0,0,1,7,7,2,7,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res = majority(arr,n);
    cout<<res;
    return 0;
}
//------------------better method

#include<bits/stdc++.h>
using namespace std;

int majority(int arr[],int n){
    unordered_map <int,int> mpp;
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }
    for(auto i : mpp ){
        if(i.second > (n/2)){
            return i.first;
        }
    }
    return -1;
}

int main(){
    int arr[] = {7,0,0,1,7,7,2,7,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res = majority(arr,n);
    cout<<res;
    return 0;
}

//------------------------------optimal way

#include<bits/stdc++.h>
using namespace std;

int majority(int arr[],int n){
    int counter = 0;
    int candiate = 0;
    for(int i = 0 ; i < n ; i++){
        if(counter == 0 ){
            candiate = arr[i];
            counter++;
        }else if(candiate == arr[i]){
            counter++;
        }else{
            counter--;
        }
    }
    //checking the counter
    int check_counter = 0 ;
    for(int i = 0 ; i < n; i++){
        if(arr[i] == candiate){
            check_counter++;
        }
    }
    
    if(check_counter > (n/2)){
        return candiate;
    }

    return -1;
}


int main(){
    int arr[] = {7,0,0,1,7,7,2,7,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res = majority(arr,n);
    cout<<res;
    return 0;
}


//--------------------kadane algo 

#include<bits/stdc++.h>
using namespace std;

int kadane(int arr[],int n){
    int sum = 0;
    int max_sum = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        sum = sum + arr[i];
        max_sum = max(max_sum,sum);
        //zero defined
        if(sum < 0){
            sum = 0;
        }
    }
    return max_sum;
}

int main(){
    int arr[] = {2, 3, 5, -2, 7, -4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res = kadane(arr,n);
    cout<<res;
    return 0;
}






