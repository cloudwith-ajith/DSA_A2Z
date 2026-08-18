#include<bits/stdc++.h>
using namespace std;

int majorty(vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int counter = 0;
        for(int j = 0; j < n; j++){
            if(arr[i] == arr[j]){
                counter++;
            }
        }

        if(counter > n/2){
            return arr[i];
        }
    }

    return -1;
}

int main(){
    vector <int> arr = {2, 2, 1, 1, 1, 2, 2};
    int result = majorty(arr);
    cout<<result;
    return 0;
}

// the time complexity of the code is O(n*n)
// the space complexity of the code is O(1)

////---------------------better method for the majorty

#include<bits/stdc++.h>
using namespace std;

int majorty(vector<int> &arr){
    int n = arr.size();
    unordered_map <int,int> mpp;
    //pre process
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }
    //get the majority of the element 
    for(auto i : mpp){
        if(i.second > n/2){
            return i.first;
        }
    }

    return -1;
}

int main(){
    vector <int> arr = {7, 0, 0, 1, 7, 7, 2, 7, 7};
    int result = majorty(arr);
    cout<<result;
    return 0;
}

//----- the time compleity of the code is O(n)
// the space complexity of the code is O(n) because of the hash map 


//------------------optimal way 


#include<bits/stdc++.h>
using namespace std;

int majorty(vector<int> &arr){
    int n = arr.size();
    int counter = 0;
    int voter = 0;

    for(int i = 0; i < n; i++){
        if(counter == 0){
            voter = arr[i];
            counter++;
        }else if(voter == arr[i]){
            counter++;
        }else{
            counter--;
        }
    }
    int check  = 0;
    for(int i = 0; i < n; i++){
        if(voter == arr[i]){
            check++;
        }
    }
    if(check > n/2){
        return voter;
    }

    return -1;

}


int main(){
    vector <int> arr = {7, 0, 0, 1, 7, 7, 2, 7, 7};
    int result = majorty(arr);
    cout<<result;
    return 0;
}


// the time compleity of the problem is O(n);
// the space coomplexity of the code is O(1);
