#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector <int> &arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int lower = -1;
    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] >= target){
            lower = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return lower;
}



int upperbound(vector <int> &arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int upper = -1;
    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] > target){
            upper = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return upper;
}
 
pair<int, int> CountOcc(vector <int> &arr, int target){
    int first_occ = lowerbound(arr,target);

    if(arr[first_occ] != target || first_occ == (int) arr.size()){
        return pair<int, int> {0,0};
    }

    int last_occ = upperbound(arr,target);

    return pair<int, int> {first_occ,last_occ - 1};

}
 


int main(){
    vector <int> arr ={1, 1, 2, 2, 2, 2, 3};
    int target = 2;
    pair<int,int> result = CountOcc(arr,target);
    cout << result.first <<" "<<result.second;
    return 0;
}

// the time complexity of the code is O(log n)
// the space cpmplexity of the code is O(1)
