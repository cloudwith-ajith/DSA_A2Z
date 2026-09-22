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
