// code for the count the subarray 
//brute force method 
// the time complexity of the code is O(n*n) which mean 2n
// the space complxity of the code is O(1)

#include<bits/stdc++.h>
using namespace std;

int count_subarray(vector <int> &arr,int k){
    int n = arr.size();
    int count = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i;j < n;j++){
            sum = sum + arr[j]; 
            if(sum == k){
                count++;
            }
        }
    }

    return count;
}


int main(){
    vector <int> arr = {1,2,3};
    int k = 3;
    int result = count_subarray(arr,k);
    cout<<result;
    return 0;
}


/// we can optimal the code into the O(n)
// using the hash map 

#include<bits/stdc++.h>
using namespace std;

int count_subarray(vector <int> &arr,int k){
    int n = arr.size();
    unordered_map <int,int> mpp;
    //base case for
    mpp[0] = 1;
    int prefix_sum = 0;
    int count = 0;
    for(int i = 0 ; i < n; i++){
        // sum of the all element before element
        prefix_sum = prefix_sum + arr[i];
        //element to check 
        int remove = prefix_sum - k;
        //check the k- orefix in the map
        if(mpp.find(remove) != mpp.end()){
            count++;
        }
        //update the element tot the map 
        mpp[prefix_sum]++;
    }

    return count;
}


int main(){
    vector <int> arr = {1,2,3};
    int k = 3;
    int result = count_subarray(arr,k);
    cout<<result;
    return 0;
}
