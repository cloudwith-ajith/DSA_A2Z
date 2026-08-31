//The optimal solution 1

#include<bits/stdc++.h>
using namespace std;

void mergetwoarray(vector<int> &arr1, vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();

    int i = n - 1;
    int j = 0;
    while(i >= 0 && j < m){
        if(arr1[i] > arr2[j]){
            swap(arr1[i],arr2[j]);
            i--;
            j++;
        }else{
            break;
        }
    }

    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
}


int main(){
    vector<int> arr1 = {1, 3, 5};
    vector<int> arr2 = {2, 4, 6};
    mergetwoarray(arr1,arr2);
    for(int i : arr1){
        cout<<i<<" ";
    }
    for(int i : arr2){
        cout<<i<<" ";
    }
    return 0;
}
