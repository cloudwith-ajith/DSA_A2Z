#include<bits/stdc++.h>
using namespace std;

int single(vector <int> &arr){
    int n = arr.size();
    int low = 1;
    int high = n - 2;
    int answer = -1;

    if(n == 1){
        return arr[0];
    }

    if(arr[0] != arr[1]){
        return arr[0];
    }

    if(arr[n-2] != arr[n - 1]){
        return arr[n-1];
    }

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] != arr[mid + 1] && arr[mid -1] != arr[mid]){
            answer =  arr[mid];
            break;
        }

        if(mid % 2 != 0 && arr[mid - 1] == arr[mid] || mid % 2 == 0 && arr[mid] == arr[mid + 1]){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return answer;
}


int main(){
    vector <int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int result = single(arr);
    cout<<result;
    return 0;
}

// the time complexity of the code is O(log n)
// the space complexity of the code is O(1)
