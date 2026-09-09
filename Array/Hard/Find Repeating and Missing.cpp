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

///----optimal solution 

#include<bits/stdc++.h>
using namespace std;

vector <int> ReMs(vector<int> &arr){
    int n = arr.size();
    int sn1 = (n*(n+1))/2;
    int sn2 = (n*(n+1) * (2 * n + 1))/6;
    int s1 = 0;
    int s2 = 0;
    for(int i = 0; i < n; i++){
        s1 += arr[i];
        s2 = s2 + (arr[i] * arr[i]);
    }
    int var1 = s1 - sn1;
    int var2 = s2 - sn2;
    var2 = var2 / var1;
    int x =  (var1 + var2) / 2;
    int y =  x - var1;
    vector <int> res  = {x,y};
    return res;
}

int main(){
    vector<int> arr = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> result = ReMs(arr);
    for(auto i : result){
        cout<<i<<" ";
    }
    return 0;
}
// the timecomplexity of the code is O(n);
// the space complexity of the code is O(1);
