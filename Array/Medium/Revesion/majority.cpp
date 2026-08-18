#include<bits/stdc++.h>
using namespace std;

int majorty(vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int counter = 0;
        for(int j = 0; j < n; j++){
            if(arr[i] == arr[j]){
                counter++;
            }
        }

        if(counter > n/2){
            return arr[i];
        }
    }

    return -1;
}

int main(){
    vector <int> arr = {2, 2, 1, 1, 1, 2, 2};
    int result = majorty(arr);
    cout<<result;
    return 0;
}
