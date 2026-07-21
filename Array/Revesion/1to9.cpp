// //-------------------brute force
//largeset element in the array

#include<bits/stdc++.h>
using namespace std;

int largest(int arr[],int n){
    
    sort(arr,arr+n);
    return arr[n-1];
}

int main(){
    int arr[] = {2,5,1,3,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<largest(arr,n);
    return 0;
}

//tc is O(n log n) because its using the sorting 
// sc is O(1)

//------------------optimal way

#include<bits/stdc++.h>
using namespace std;

int largest(int arr[],int n){
    int i = arr[0];
    for(int j = 1; j < n; j++){
        if(i < arr[j]){
            i = arr[j];
        }
    }
    return i;
}

int main(){
    int arr[] = {2,5,1,3,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<largest(arr,n);
    return 0;
}

// tc is O(n) linear to the end 
//sp is O(1)

//-------------SECOND LARGESET ELEMENT 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] ={3,2,6,4,0,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int max = arr[0];
    for(int i = 0;i < n;i ++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    
    int second_max = INT_MIN;
    
    for(int j = 0; j < n; j++){
        if(arr[j] > second_max && arr[j] != max){
            second_max = arr[j];
        }
    }
    
    cout<<second_max;
    
    return 0;
}
// tc ----O(2n)
