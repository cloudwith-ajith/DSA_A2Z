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
----------------------------------
#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    
    while(i < j){
        while(arr[i] <= pivot && i < high){
            i++;
        }
        while(arr[j] > pivot && j > low){
            j--;
        }
        if (i < j){
            swap(arr[i],arr[j]);
        }
    }
    
    swap(arr[low],arr[j]);
    return j;
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
    int arr[6] = {34,7,23,32,5,62};
    int n = sizeof(arr) / sizeof(arr[0]);
    Quick_sort(arr,0,n-1);
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}

----------insertion
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[6] = {34,7,23,32,5,62};
    int n = sizeof(arr)/ sizeof(arr[0]);
    for(int i = 0; i < n; i++){
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
    
    for(int i  :  arr){
        cout<<i <<" ";
    }
    return 0;
}

//-------------bubble sort 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[6] = {34,7,23,32,5,62};
    int n  = sizeof(arr) / sizeof(arr[0]);
    
    for(int i = n-1; i >= 0; i--){
        for(int j = 0 ; j < i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}
//------------selection sort 


#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[8] = {1,46,24,52,20,9,2,13};
     int n = sizeof(arr)/sizeof(arr[0]);
     
     for(int i = 0;i < n-1; i++){
         int min = i;
         for(int j = i; j< n; j++){
             if(arr[j] < arr[min]){
                 min = j;
             }
         }
         swap(arr[i],arr[min]);
     }
     
     for(int i : arr){
         cout<<i <<" ";
     }
    return 0;
}
//----merge sort
#include<bits/stdc++.h>
using namespace std;


void merge(int arr[],int low,int mid,int high){
    
    vector <int> temp;
    int i = low;
    int j = mid+1;
    
    while(i <= mid && j <= high){
        if(arr[i] > arr[j]){
            temp.push_back(arr[j]);
            j++;
        }else{
            temp.push_back(arr[i]);
            i++;
        }
    }
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= high){
        temp.push_back(arr[j]);
        j++;
    }
    
    for(int i = low; i <= high; i++){
        arr[i] = temp[i -low];
    }
}


void merge_sort(int arr[],int low,int high){
    if (low < high){
        int mid = (low+ high) / 2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}


int main(){
    int arr[6] = {34,7,23,32,5,62};
    int n = sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr,0,n-1);
    
    for(int n : arr){
        cout<<n<<" ";
    }
    
    return 0;
}
