//------------------------brute force method for the problem  --------

#include<bits/stdc++.h>
using namespace std;

int LastOccur(vector <int> &arr,int target){
    int  n = arr.size();
    int answer = -1;

    for(int i = 0; i < n; i++){
        if(arr[i] == target){
            answer = i;
        }
    }
    return answer;
}


int main(){
    vector <int> arr = {1, 3, 5, 7, 9};
    int target = 46;
    int result = LastOccur(arr,target);
    cout<<result;
    return 0;
}

// the time complexity of the code is O(n)
// the space complexity of the code is O(1)

//-----------------------optimal way for the problem---------
