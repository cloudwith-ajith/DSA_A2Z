// brute force method for the problem
#include<bits/stdc++.h>
using namespace std;

int CountInver(vector <int> &arr){
    int n = arr.size();
    int counter = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){
                counter++;
            }  
        }
    }
    return counter;
}

int main(){
    vector <int> arr = {5,3,2,1,4};
    int res = CountInver(arr);
    cout<<res;
    return 0;
}
// The Time complexity of the code is O(n^2)
// The Space complexity of the code is O(n)
