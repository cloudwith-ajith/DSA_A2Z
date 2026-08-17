

/////------------------------------revesion --- prefix sum
/////Longest Subarray with given Sum K(Positives)
// brute force method and ##--##the optimal for the negative values ##--##
#include<bits/stdc++.h>
using namespace std;

int longest_subarray_k(vector<int> &arr,int k ){
    int n = arr.size();
    int max_counter = 0;
    for(int i = 0 ; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum = sum + arr[j];
            if(sum == k){
                max_counter = max(max_counter,((j-i)+1));
            }
        }
    }

    return max_counter;
}

int main(){
    vector<int> arr = { 10, 5, 2, 7, 1, 9 };
    int k = 15;
    int result  = longest_subarray_k(arr,k);
    cout<<result;
    return 0;
}
///---optimal method for the longest subarray negative number 
#include<bits/stdc++.h>
using namespace std;

int longest_subarray_k(vector<int> &arr,int k ){
    int n = arr.size();
    int left = 0 ;
    int right = 0 ;
    int max_count = 0;
    int sum = 0;
    while(right < n){
        sum  = sum + arr[right];

        while(sum > k && left <= right){
            sum = sum - arr[left];
            left++;
        }if(sum == k){
            max_count = max(max_count,(right -left) + 1);
        }
        right++;
    }


    return max_count;
}

int main(){
    vector<int> arr = { 10,5,2,7,1,9};
    int k = 15;
    int result  = longest_subarray_k(arr,k);
    cout<<result;
    return 0;
}
