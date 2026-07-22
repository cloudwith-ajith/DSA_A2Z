//---------Count Maximum Consecutive One's in the array

#include<bits/stdc++.h>
using namespace std;

int max_cons(int arr[],int n){
    int maxx = 0;
    int counter = 0;
    
    for(int i = 0;i < n;i++){
        if(arr[i] == 1){
            counter++;
            // maxx = max(counter,maxx);
            if(counter > maxx){
                maxx = counter; 
            }
        }else{
            counter = 0;
        }
    }
    return maxx;
}

int main(){
    int arr[] ={1,1,1,0,0,1,1,0,1,1,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = max_cons(arr,n);
    cout<<result;
    return 0;
}

