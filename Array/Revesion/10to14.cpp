//Find the missing numbers
#include<bits/stdc++.h>
using namespace std;

int missing_number(int arr[],int n){
    for(int i = 1; i <= n+1; i ++){
        int flag = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == i){
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[] = {8, 2, 4, 5, 3, 7, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = missing_number(arr,n);
    cout<<result;
    return 0;
}
