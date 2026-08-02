//Sort an array of 0's 1's and 2's
//tried by me , to realiable and not best fit for the timecomplexity 
#include<bits/stdc++.h>    
using namespace std;

void sort_sort(int arr[],int n){
    // create the temp array
    vector <int> temp;    
    // first loop for the 0 to 2 element   
    for(int i = 0 ; i < 3; i++){    
        // for the element present in the array 
        for(int j = 0 ; j < n; j++){
            // if the element present push to temp array 
            if(arr[j] == i){
                temp.push_back(arr[j]);
            }
        }
    }
    //copy back the temp to original array 

    for(int i = 0; i < n; i++){
        arr[i] = temp[i];
    }
}

int main(){
    int arr[] = {1,0,2,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort_sort(arr,n);
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}

//-----------------------------------------------------------
//////------------------better way to code for this problem 
#include<bits/stdc++.h>
using namespace std;

void sort_sort(int arr[],int n ){
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    //count the frequence 
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){count0++;}
        if(arr[i] == 1){count1++;}
        if(arr[i] == 2){count2++;}
    }
    for(int i = 0; i < count0; i++){
        arr[i] = 0;
    }
    for(int i = count0; i < count0+count1; i++){
        arr[i] = 1;
    }
    for(int i = count0+count1; i < n; i++){
        arr[i] = 2;
    }
}

int main(){
    int arr[] = {1,0,2,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort_sort(arr,n);
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}

// no extra space O(1)
// tc is O(n) but not exact O(n)


//--------------------optimal way to right the code for this problem 

#include<bits/stdc++.h>
using namespace std;

void sort_sort(int arr[],int n ){
    int left = 0;
    int mid = 0;
    int right = n-1;
    
    while(mid <= right){
        if(arr[mid] == 0){
            swap(arr[left],arr[mid]);
            left++;
            mid++;
        }
        else if (arr[mid] == 1){
            mid++;
        }else{
            swap(arr[mid],arr[right]);
            right--;
        }
    }
}

int main(){
    int arr[] = {1,0,2,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort_sort(arr,n);
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}
// tc is exact O(n)
// sc is O(1) not extra space used 

