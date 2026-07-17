----------------------------------------cpp

--largest element in the array
--my code
#include<bits/stdc++.h>
using namespace std;

int max_element(int arr[],int n){
    int max = 0;
    for(int i = 0;i < n;i++){
        if(arr[i] > arr[max]){
            max = i;
        }
    }
    return arr[max];
}

int main(){
    int arr[5] ={2,5,1,3,0};
    int n = size(arr);
    cout<<max_element(arr,n);
    return 0;
}
