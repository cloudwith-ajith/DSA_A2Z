#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {3,2,1};
    
    // Modifies arr to the next permutation in-place
    next_permutation(arr.begin(), arr.end()); 
    
    for(int i : arr){
        cout << i << " ";
    }
    return 0;
}
