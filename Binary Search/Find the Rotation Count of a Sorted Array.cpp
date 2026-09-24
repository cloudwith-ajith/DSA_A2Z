//  optimal way for the problem

#include<bits/stdc++.h>
using namespace std;

int findrotation(vector <int> &arr){
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int value = INT_MAX;
    int index = -1;

    while(low <= high){
        if(arr[low] <= arr[high]){
            if(arr[low] < value){
                index = low;
                value = arr[low];
            }
        }
        int mid = (low + high) / 2;

        if(arr[low] <= arr[mid]){
            if(arr[low] < value){
                value = arr[low];
                index = low;
            }
            low = mid + 1;
        }else{
            if(arr[mid] < value){
                value = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }

    return index;
}



int main(){
    vector <int> arr = {4, 5, 6, 7, 0, 1, 2};
    int result = findrotation(arr);
    cout<<result;
    return 0;
}

// the time complexity of the code is O(log n )
// the space complexity of the code is O(1)
