// brute force method for the problem 


#include<bits/stdc++.h>
using namespace std;

int KoKoBanana(vector <int> &arr, int h){
    int n = arr.size();
    int maxy = *max_element(arr.begin(), arr.end());

    for(int i = 1; i <= maxy; i++){
        int answer = 0 ;
        for(int j = 0; j < n; j++){
            // To find the ciel 
            answer += (arr[j] + (i - 1)) / i;
        }
        if(answer <= h){
            return i;
        }
    }

    return -1;
}


int main(){
    vector <int> arr = {30, 11, 23, 4, 20};
    int h = 5;
    cout<<KoKoBanana(arr,h);
    return 0;
}

