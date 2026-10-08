

#include<bits/stdc++.h>
using namespace std;


double Median_arrays(vector <int> &arr1, vector <int> &arr2){
    if(arr1.size() > arr2.size()){
        return Median_arrays(arr2, arr1);
    }

    int n = arr1.size();
    int m  = arr2.size();
    int low = 0;
    int high = n;
    int leftside = (n + m + 1) / 2;

    while(low <= high){
        int cut_1 = (low + high) / 2;
        int cut_2 = leftside - cut_1;

        int left1 = (cut_1 == 0) ? INT_MIN : arr1[cut_1 - 1];
        int right1 = (cut_1 == n) ? INT_MAX : arr1[cut_1];
        int left2 =  (cut_2 == 0) ? INT_MIN : arr2[cut_2 - 1];
        int right2 = (cut_2 == m) ? INT_MAX : arr2[cut_2];

        if(left1 <= right2 && left2 <= right1){
            if((n + m ) % 2 == 1){
                return (double)max(left1, left2);
            }else{
                return (((double)max(left1,left2) + min(right1,right2)) / 2.00);
            }
        }else if(left1 > right2){
            high = cut_1 - 1;
        }else{
            low = cut_1 + 1;
        }
    }

    return 0.00;
}
 


int main(){
    vector <int> arr1 = {1,2, 3};
    vector <int> arr2 = {4,5};
    cout<<Median_arrays(arr1, arr2);
    return 0;
}
