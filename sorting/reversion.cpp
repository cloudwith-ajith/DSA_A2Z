#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int arr[6] = {7,12,9,11,13,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = n-1; i >= 0 ; i--){
        for(int j  = 0; j <= i-1; j++){
            if(arr[j] > arr[j +1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    
    for(int i : arr){
        cout<<i<<" ";
    }
    
    return 0;
}

#-------------------------------------------------------   
#insertion sort
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[5] = {7,12,9,11,3};
    int n  = sizeof(arr)/sizeof(arr[0]);
    
    for(int i = 0; i <= n-1; i++){
        int j = i;
        while(j > 0 && arr[j-1] > arr[j] ){
            swap(arr[j-1],arr[j]);
            j--;
        }
    
    }
    
    for(int i : arr) cout<<i<<" ";
    return 0;
}
//---------------------------------------quick sort 

#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low - 1;
    
    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    
    swap(arr[high],arr[i+1]);
    return i + 1;
}


void Quick_sort(int arr[],int low,int high){
    if (low >= high){
        return ;
    }else{
        int sorted_index = partition(arr,low,high);
        Quick_sort(arr,low,sorted_index -1);
        Quick_sort(arr,sorted_index + 1,high);
    }
}
int main(){
    int arr[6] = {34,34,23,32,5,62};
    int n = sizeof(arr) / sizeof(arr[0]);
    Quick_sort(arr,0,n-1);
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}
