// three sum   brute force method 
// the time complexity of the code is three loop so 3^n
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threesum(vector<int> &arr){
    int n = arr.size();
    set <vector<int>> temp;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(arr[i]+arr[j]+arr[k] == 0){
                    vector<int> tp = {arr[i],arr[j],arr[k]};
                    sort(tp.begin(),tp.end());
                    temp.insert(tp);
                }
            }   
        }
    }
    vector<vector<int>> res(temp.begin(),temp.end());
    return res;
}


int main(){
    vector <int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int >> result = threesum(arr);
    for(auto i : result){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }
    return 0;
}
//-------------//// better method to solve the THREESUM 3sum 

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threesum(vector<int> &arr){
    int n = arr.size();
    set <vector<int>> tempset;
    for(int i = 0; i < n; i++){
        set <int> eleset;
        for(int j = i + 1; j < n; j++){
            int k = -(arr[i] + arr[j]);
            if(eleset.find(k) != eleset.end()){
                vector<int> tp = {arr[i],arr[j],k};
                sort(tp.begin(),tp.end());
                tempset.insert(tp);
            }
            eleset.insert(arr[j]);
        }
    }
    vector<vector<int>> result(tempset.begin(),tempset.end());
    return result;
}


int main(){
    vector <int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int >> result = threesum(arr);
    for(auto i : result){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }
    return 0;
}

// the time complexity of the code is O(2^n)



#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threesum(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> result;
    //sort the array 
    sort(arr.begin(),arr.end());
    //outer loop 
    for(int i = 0; i < n; i++){
        if(i > 0 && arr[i] == arr[i-1]){
            continue;
        }

        int j = i + 1;
        int k = n - 1;
        while(j < k){
            int sum = arr[i]+arr[j]+arr[k];
            // if the summ is greater than the zero 
            if(sum > 0){
                k--;
            }else if(sum < 0){
                j++;
            }else{
                vector<int> temp = {arr[i],arr[j],arr[k]};
                result.push_back(temp);
                j++;
                k--;
                // to remove the duplicate 
                while(j < k && arr[j] == arr[j-1]){
                    j++;
                }
                while(j < k && arr[k] == arr[k+1]){
                    k--;
                }
            }
        }
    }

    return result;
}


int main(){
    vector <int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int >> result = threesum(arr);
    for(auto i : result){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }
    return 0;
}

// optimal way foe the three sum 
// the time complexity for the code is O(n^2)
// the space complexity for the code is O(1), the vector space is calculate 
// as the ouptut space 


