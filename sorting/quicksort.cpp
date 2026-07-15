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
