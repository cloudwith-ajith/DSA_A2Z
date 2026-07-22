//---brute force methoed 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,2,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    for(int i = 1; i <= n+1; i++){
        int flag = 0;
        for(int j =0;j < n; j++){
            if(arr[j] == i){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
                cout<<i<<" is the missing value";
            }
        }
    return 0;
}
//-----------------------------------------------------------
//find the missing number in the array
//optimal solution 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {8,1,2,3,7,4,5};
    int sum = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++){
        sum = sum + arr[i];
    }
    int t= n+1;
    long long o_sum = (t *(t+1))/2;
    
    cout<<o_sum -sum;
    return 0;
}

//---------------------------------------XOR method
#include<bits/stdc++.h>
using namespace std;

int mis(int arr[],int n){
    int xor1 = 0;
    int xor2 = 0;
    
    for(int i = 0; i < n; i++){
        xor1 = xor1^arr[i];
        xor2 = xor2^(i+1);
    }
    
    xor2 = xor2 ^ (n+1);
    //missing value
    return xor1^xor2;
}



int main(){
    int arr[] = {1,2,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = mis(arr,n);
    cout<<result;
    return 0;
}
