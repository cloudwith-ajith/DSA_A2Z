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




//------------------check the array is sorted or not 
#include<bits/stdc++.h>
using namespace std;

bool check_sorted(int arr[],int n ){
    for(int i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}

int main(){
    int arr[] ={1,2,6,4,5};
    int n = sizeof(arr)/ sizeof(arr[0]);
    if(check_sorted(arr,n) ==true){
        cout<<"sorted";
    }else{
        cout<<"unsorted";
    }
    
    return 0;
}//----tc is O(n)


//--------------------Remove Duplicates in-place from Sorted Array
//------------------optimal solution 
//-------tc is o(n)
#include<bits/stdc++.h>
using namespace std;

int unique(int arr[], int n ){
    int un = 0;
    for(int i = 0; i < n-1; i++){
        if(arr[i] != arr[i+1]){
            un++;
            arr[un] = arr[i+1];
        }
    }
    
    return un + 1;
}

int main(){
    int arr[] = {1,1,1,2,2,2,3,3,4,4,};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = unique(arr,n);
    
    cout<<result<<endl;
    
    for(int i : arr){
        cout<<i<<" ";
    }
    
    
    return 0;
}

//----------------brute force method
//----using set tc is O(n log n)
#include<bits/stdc++.h>
using namespace std;


int main(){
    int arr[] = {1,1,2,2,2,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    set <int> temp;
    
    for(int i = 0; i < n; i++){
        temp.emplace(arr[i]);
    }
    int j = 0;
    for(int i : temp){
        arr[j] = i;
        j++;
    }
    
    for(int  n : arr){
        cout<<n<<" ";
    }
    return 0;
}
//---------using unordered set
// the tc is O(n)

#include<bits/stdc++.h>
using namespace std;


int main(){
    int arr[] = {1,1,2,2,2,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    unordered_set <int> temp;
    
    for(int i = 0; i < n; i++){
        temp.emplace(arr[i]);
    }
    int j = 0;
    for(int i : temp){
        arr[j] = i;
        j++;
    }
    
    for(int  n : arr){
        cout<<n<<" ";
    }
    return 0;
}

//output 3 2 1 2 2 3 3 

//----------------brute force for the one rotate
#include<bits/stdc++.h>
using namespace std;

void rotate(int arr[],int n){
    vector <int> temp(n);
    for(int i = 1; i < n; i++){
        temp[i-1] = arr[i];
    }
    temp[n-1] = arr[0];
    
    for(int j = 0; j < n; j++){
        arr[j] = temp[j];
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    rotate(arr,n);
    for(int n : arr){
        cout<<n<<" "; 
    }
    return 0;
}


