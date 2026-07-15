-------------------------quick sort with the front element


#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high){
    //picking the pivot to the first element
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
        if(i < j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}


void Quick_sort(int arr[],int low, int high){
    if(low<high){
        int SI = partition(arr,low,high);
        Quick_sort(arr,low,SI-1);
        Quick_sort(arr,SI+1,high);
    }
}


int main(){
    int arr[6] = {4,1,29,3,14,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    Quick_sort(arr,0,n-1);
    for(int i : arr){cout<<i<<" ";}
    return 0;
}






---------------------------cpp quick sort with the last element
#include<bits/stdc++.h>
using namespace std;

int sort(int arr[],int low,int high){
    // picking the last element in the array
    int pivot = arr[high];
    // create the i as the -1 index bcz we dont have any element 
    //smaller than the high
    int i = low -1;
    //loop the array
    for(int j = low; j < high; j++){
        // if the element is smaller than the pivot 
        // need to place in the left half,so we use the i(index 0 for place the small value)
        if(arr[j] <= pivot){
            i++;
            //swap the large value to the  left half
            swap(arr[i],arr[j]);
        }
    }
    //swap the last element with the i+1, which is the point the larger number started
    swap(arr[i+1],arr[high]);
    return i + 1;
}

void Quick_sort(int arr[],int low, int high){
    //basecase
    if(low >= high){
        return ;
    }
    //recurrsion case
    else{
        //get the sort index 
        int SI  = sort(arr,low,high);
        //split into the two array using the index
        //one from left of the sorted index
        Quick_sort(arr,low,SI-1);
        //one from right of the sorted index
        Quick_sort(arr,SI+1,high);
    }
}
int main(){
    
    int arr[6] = {4,1,29,3,14,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    //calling the function 
    Quick_sort(arr,0,n-1);
    // printing the the element preent inside the array
    for(int n : arr){
        cout<<n<<" ";
    }
    return 0 ;
}
