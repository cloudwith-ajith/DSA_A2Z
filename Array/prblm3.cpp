//find the unique elements in the sorted array 
#include<bits/stdc++.h>
using namespace std;

int unique(int arr[],int n){
    int i = 0;
    for(int j =0;j < n-1;j++){
        if(arr[j] != arr[j+1]){
            i++;
        }
    }
    return i+1;
}

int main(){
    int arr[6] ={1,1,2,3,3,4};
    // output unique-->4,and arr{1,2,3,4,1,3};
    int n =sizeof(arr)/sizeof(arr[0]);
    cout<<unique(arr,n);
    return 0;
}

//-------------brute for method
#include<bits/stdc++.h>
using namespace std;

int func(int arr[],int n ){
    vector <int> temp;
    int i = -1 ;
    for(int j = 0;j <= n-1; j++){
        if(arr[j] != arr[j+1]){
            i++;
            temp.push_back(arr[j]);
        }
    }
    
    for(int k =0; k <= i;k++){
        arr[k] = temp[k];
    }
    
    return i+1;
} 



int main(){
    int arr[] = {1,2,2,3,3,3,4,4,4,5,6,6,7,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<func(arr,n)<<"\n";
    for(int a :arr){
        cout<<a<<" ";
    }
    return 0;
}
//optimal solution 
#include<bits/stdc++.h>
using namespace std;

int func(int arr[],int n ){
    
    int i =0;
    
    for(int j =1; j <= n-1;j++){
        if(arr[j] != arr[j+1]){
            i++;
            arr[i]=arr[j];
        }
    }
    
    return i+1;
} 



int main(){
    int arr[] = {1,2,2,3,3,3,4,4,4,5,6,6,7,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<func(arr,n)<<"\n";
    for(int a :arr){
        cout<<a<<" ";
    }
    return 0;
}
