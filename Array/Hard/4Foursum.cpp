#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> foursum(vector<int> &arr,int target){
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i = 0; i < n; i++){   
        if(i > 0 && arr[i] == arr[i-1]){
            continue;
        }
        for(int j = i + 1; j < n; j++){
            if(j != i+1 && arr[j] == arr[j-1]){
                continue;
            }

            int k = j + 1;
            int l = n - 1;
            while( k < l){
                long long sum = (long long)arr[i] + arr[j] + arr[k] + arr[l];
                if(sum == target){
                    vector<int>temp = {arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while( k < l && arr[k] == arr[k-1]){
                        k++;
                    }
                    while( k < l && arr[l] == arr[l+1]){
                        l--;
                    }
                }else if(sum < target){
                    k++;
                }else{
                    l--;
                }
            }
        }
    }

    return ans;
}


int main(){
    vector<int> arr ={4,3,3,4,4,2,1,2,1,1};
    int target = 9;
    vector<vector<int>> result = foursum(arr,target);
    for(auto i : result){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }
    return 0;
}
/// the time complexity of the code is O(n^3)
// the space complexity of the code is O(no.of.element array ) and the that too used to return the array 
