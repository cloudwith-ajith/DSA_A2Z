//-----------------moving the zero to the end 
//-----------------brute force method 
#include<bits/stdc++.h>
using namespace std;

void bz(int arr[], int n){
    vector <int> temp(n,0);
    
    int index = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            temp[index] = arr[i];
            index++;
        }
    }
    //copy back to the original array 
    for(int i = 0; i < n; i++){
        arr[i] =temp[i];
    }
}


int main(){
    int arr[] = {0,0,1,2,0,1,0,4,0};
    int n = sizeof(arr)/ sizeof(arr[0]);
    bz(arr,n);
    for(int a : arr){
        cout<<a<<" ";
    }
    return 0;
}

//--------------------------------------------optimal method

#include<bits/stdc++.h>
using namespace std;

void move_zero(int arr[],int n ){
    //assign the j pointer to the zero,but we need to find the zero so we assign as the -1;
    int j = -1;
    for(int i = 0; i < n;i++){
        if(arr[i] ==0){
            j = i;
            break;
        }
    }
    
    for(int i = j + 1; i < n; i++){
        if(arr[i] != 0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}

int main(){
    int arr[] ={1,0,2,3,2,0,0,4,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    move_zero(arr,n);
    
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}

