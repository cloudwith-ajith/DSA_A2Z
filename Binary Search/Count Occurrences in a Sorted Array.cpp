// optimal solution using the lower bound and the upper bound


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
 
int CountOcc(vector <int> &arr, int target){
    int first_occ = lowerbound(arr,target);

    if(arr[first_occ] != target || first_occ == (int) arr.size()){
        return 0;
    }

    int last_occ = upperbound(arr,target);

    return last_occ - first_occ;

}
 


int main(){
    vector <int> arr ={1, 1, 2, 2, 2, 2, 3};
    int target = 2;
    int result = CountOcc(arr,target);
    cout << result;
    return 0;
}

// the time complexity of the code is O(log n)
// the space complexity of the code is O(1)
