//brute force method 

#include<bits/stdc++.h>
using namespace std;

vector<int> ReMis(vector<int> &arr){
    int n = arr.size();
    // variable to store the missing value
    int missing = -1;
    // to store the repeating value
    int repeating = -1;
    // first loop for the 1 to n
    for(int i = 1; i < n+1; i++){
        bool flag = true;
        int counter = 0;
        //the original array 
        for(int j  = 0; j < n; j++){
            if(i == arr[j]){
                flag = false;
                counter++;
            }
        }
        // To check the flag 
        if(flag){
            missing = i;
        }
        //To check the counter
        if(counter == 2){
            repeating = i;
        }
    }
    // vector to return the answer not for the computation
    vector<int> res = {repeating,missing};
    // return the value
    return res;
}

int main(){
    vector <int> arr = {1, 2, 3, 6, 7, 5, 7};
    vector<int> result = ReMis(arr);
    for(auto i : result){
        cout<<i<<" ";
    }
    return 0;
}// The Time complexity of the code is O(n*2)
// The Space complexity of the code is O(1), we use vector for the returning the answer, not for the process.


//------------------better method 

#include<bits/stdc++.h>
using namespace std;

vector<int> ReMis(vector<int> &arr){
    int n = arr.size();
    int hash[n + 1] ={ 0 };
    for(int i = 0; i < n; i++){
        hash[arr[i]]++;
    }
    int missing = -1;
    int repeat = -1;
    for(int i = 1; i < n; i++){
        if(hash[i] == 0){
            missing = i;
        }else if(hash[i] == 2){
            repeat = i;
        }
    }

    vector<int> res = {repeat ,missing};
    return res;
}

int main(){
    vector<int> arr = {3,5,4,1,1};
    vector<int> result = ReMis(arr);
    for(auto i : result){
        cout<<i<<" ";
    }
    return 0;
}

//------------using the hashing
// The Time complexity of the code is O(n)
// The Space complexity of the code is O(n)
