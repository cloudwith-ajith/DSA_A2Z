//Sort an array of 0's 1's and 2's
//tried by me , to realiable and not best fit for the timecomplexity 
#include<bits/stdc++.h>
using namespace std;

void sort_sort(int arr[],int n){
    // create the temp array
    vector <int> temp;
    // first loop for the 0 to 2 element
    for(int i = 0 ; i < 3; i++){
        // for the element present in the array 
        for(int j = 0 ; j < n; j++){
            // if the element present push to temp array 
            if(arr[j] == i){
                temp.push_back(arr[j]);
            }
        }
    }
    //copy back the temp to original array 

    for(int i = 0; i < n; i++){
        arr[i] = temp[i];
    }
}

int main(){
    int arr[] = {1,0,2,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort_sort(arr,n);
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}
