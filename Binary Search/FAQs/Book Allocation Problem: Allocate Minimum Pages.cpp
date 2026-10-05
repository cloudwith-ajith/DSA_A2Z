// optimal way for the problem 


#include<bits/stdc++.h>
using namespace std;


bool helper_function(vector <int> &arr, int student, int limit){
    int n = arr.size();
    int div = 1;
    int page_count = 0;
    for(int i = 0 ; i < n; i++){
        if(page_count + arr[i] <= limit){
            page_count += arr[i];
        }else{
            div++;
            page_count = arr[i];
        }
    }
    if(div > student){
        return false;
    }

    return true;
    
}


int Book_Allocation(vector <int> &arr, int student){
    int start = *max_element(arr.begin(),arr.end());
    int end = accumulate(arr.begin(),arr.end(),0);

    int amswer = -1;
    while(start <= end){
        int mid = (start + end) / 2;
        if(helper_function(arr,student,mid)){
            amswer = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    
    return amswer;
}


int main(){
    vector <int> arr = {12, 34, 67, 90};
    int student = 2;
    cout<<Book_Allocation(arr, student);
    return 0;
}


// the time complexity of the code is O(max x log n)
// the space complexity of the code is O(1)
