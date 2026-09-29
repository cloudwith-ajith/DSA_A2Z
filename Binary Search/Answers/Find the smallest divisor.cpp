// brute force method 

#include<bits/stdc++.h>
using namespace std;

int smallestdivisor(vector <int> &arr, int x){
    int n = arr.size();
    int maxs = *max_element(arr.begin(),arr.end());
    int answer = 0;
    for(int i = 1; i <= maxs; i++){
        int ans = 0;
        for(int j = 0; j < n; j++){
            ans += (arr[j] + ( i - 1)) / i;
        }
        if(ans <= x){
            answer = i;
            break;
        }
    }

    return answer;
}


int main(){
    vector <int> arr = {8,4,2,3};
    int limit = 10;
    int result = smallestdivisor(arr,limit);
    cout<<result;
    return 0;
}

// the time complexity of the code is O(max * n)
// the space complexity of the code is O(1)
