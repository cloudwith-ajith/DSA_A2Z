//----------------brute force method 
#include<bits/stdc++.h>
using namespace std;


//helper function 
bool liner_function(vector<int>arr,int num){
    for(int i : arr){
        if(num == i){
            return true;
        }
    }
    return false;
}



int consective(vector <int>arr){
    int n  = arr.size();
    int max_counter = 0;
    for(int i = 0; i < n; i++){
        int num = arr[i];
        int counter = 1;
        while(liner_function(arr,num+1) == true){
            counter = counter + 1;
            num = num + 1;
        }
        max_counter = max(max_counter,counter);
    }
    return max_counter;
}


int main(){
    vector <int> arr = {100, 4, 200, 1, 3, 2};
    int result = consective(arr);
    cout<<result; 
    return 0;
}
