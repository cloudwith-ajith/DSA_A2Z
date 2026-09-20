// breute force method 

#include<bits/stdc++.h>
using namespace std;

int maxproductt(vector <int> &arr){
    int n = arr.size();
    int maxpro = INT_MIN;
    for(int i = 0; i < n; i++){
        int temp = arr[i];
        for(int j = i + 1; j < n; j++){
            temp = temp * arr[j];
            maxpro = max(maxpro, temp);
        }
    }
    return maxpro;
}

int main(){
    vector <int> arr ={2,3,-2,4};
    int result = maxproductt(arr);
    cout<<result;
    return 0;
}

// The Time complexity of the code is O(n^2)
// The Space complexity of the code is O(1)
//--------------------------------------------------------------------------
// The optimal solution 





