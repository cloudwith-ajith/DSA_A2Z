// brute force method for the search insert position 
#include<bits/stdc++.h>
using namespace std;

int upper_bound(vector <int> &arr, int target){
    int n = arr.size();
    for(int i = 0 ; i < n; i ++){
        if(arr[i] == target || arr[i] > target){
            return i;
        }
    }
    return -1;
}

int main(){
    vector <int> arr = {1,3,5,7,9,11};
    int target = 6;
    int result = upper_bound(arr,target);
    cout<< result;
    return 0;
}


// the time complexity of the code is O(n)
// hte space complexity of the code is O(1)



// Optimal code for the search insert position
#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector <int> &arr, int target){
    int n = arr.size();
    int answer = n;
    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target){
            answer = mid;
            high = mid - 1;
        }else{
            low = mid + 1; 
        }
    }

    return answer;
}

int main(){
    vector <int> arr = {1, 3, 5, 6};
    int target = 2;
    int result = lowerbound(arr, target);
    cout<< result;
    return 0;
}

// the time complexity of the code is O(log n)
// the space complexity of the code is O(1)
