//Merge sort (divide and conquer)

#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int low,int mid,int high){
    vector <int> temp;
    int left = low;
    int right = mid+1;
    
    while(left <= mid && right <= high){
        if (arr[left] > arr[right]){
            temp.push_back(arr[right]);
            right++;
        }else{
            temp.push_back(arr[left]);
            left++;
        }
    }
    
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    
    for(int i= low; i <= high;i++){
        arr[i] = temp[i - low];
    }
}


void merge_sort(int arr[],int low,int high){
    if(low >= high){
        return;
    }else{
        int mid = (low+high)/2;
        merge_sort(arr,low, mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}


int main(){
    int arr[7] = {4,1,29,90,9,14,700};
    merge_sort(arr,0,6);
    
    for(int i : arr){
        cout<<i<<" ";
    }
    
    return 0;
}





// inside the temp array for the math[i-low]
for (int i = low; i <= high; i++) {
    arr[i] = temp[t]; 
    t++; // Move to the next item in temp
}
---------------------revesion

    ---------merge sort revsion 
#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    vector <int > temp;
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
    for(int i  = low; i <= high; i++){
        arr[i] = temp[i -low];
    }
}

void merge_sort(int arr[],int low, int high){
    if (low >= high){
        return;
    }else{
        int mid = (low + high) / 2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}


int main(){
    int arr[6] ={4,1,29,3,14,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr,0,n-1);
    for(int i : arr){
        cout<<i <<" ";
    }
    return 0;
}
