// brute force method for the problem 

#include<bits/stdc++.h>
using namespace std;

int Kth_element(vector <int> &arr1, vector <int> &arr2,int k ){
    int n = arr1.size();
    int m = arr2.size();
    vector <int> temp ;
    for(int i = 0; i < n; i++){
        temp.push_back(arr1[i]);
    }
    for(int i = 0; i < m; i++){
        temp.push_back(arr2[i]);
    }

    sort(temp.begin(),temp.end());

    return temp[k - 1];
}


 int main(){
     vector <int> arr1 = {2,3,6,7,9};
     vector <int> arr2 = {1,4,8,10};
     int k = 5;
     cout<<Kth_element(arr1, arr2, k);
     return 0;
 }

// the time complexity of the code is O(n+m log(n + m))
// the space complexity of the code is O(n+m)
