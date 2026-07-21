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

//-------------left rotate, k ELEMENT
//----------------brute-

#include<bits/stdc++.h>
using namespace std;

void rotate(int arr[],int k,int n ){
    int temp[n];
    for(int i = k; i < n; i++){
        temp[i - k] = arr[i];
    }
    for(int j = 0; j < k; j++){
        temp[(n-k)+j] =arr[j];
    }
     for(auto i : temp){
        cout<<temp[i]<<" ";
    }
    
}

int main(){
    int arr[] ={1,2,3,4,5};
    int k = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    rotate(arr,k,n);
    return 0;
}

//-----------------right rotate, k ELEMENT
//---------------------optimal
#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[],int start,int end){
    while (start < end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

void rotate_right(int arr[],int k,int n){
    
    k = k % n;
    //reverse the whole array
    reverse(arr,0,n-1);
    //reverse the first k elemet
    reverse(arr,0,k-1);
    //reverse the balance element
    reverse(arr,k,n-1);
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int k = 2;
    rotate_right(arr,k,n);
    
    for(int n : arr){
        cout<<n<<" ";
    }
    return 0;
}

//---------------------optimal left rotate_right
#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[],int start,int end){
    while (start < end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

void rotate_right(int arr[],int k,int n){
    
    k = k % n;
    //reverse the first k elemet
    reverse(arr,0,k-1);
    //reverse the balance element
    reverse(arr,k,n-1);
    //reverse the whole array
    reverse(arr,0,n-1);
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int k = 2;
    rotate_right(arr,k,n);
    
    for(int n : arr){
        cout<<n<<" ";
    }
    return 0;
}

//----------------linear search
//------tc is O(n)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {28,5,8,3};
    int n = size(arr);
    int s = 3;
    
    for(int i = 0; i < n; i++){
        if(arr[i] == s){
            cout<<"element in the "<<i <<" position";
            break;
        }
    }
    
    return 0;
    
}
//------------------------ union 
//---------------------brute

#include<bits/stdc++.h>
using namespace std;

vector<int> union_set(int arr1[],int arr2[],int n1,int n2){
    set <int> temp;
    //first array
    for(int i = 0; i< n1; i++){
        temp.emplace(arr1[i]);
    }
    //second array
    for(int j = 0; j < n2; j++){
        temp.emplace(arr2[j]);
    }
    
    vector<int> result(temp.begin(),temp.end());
    return result;
}


int main(){
    int arr1[] ={1,2,3,4,5};
    int arr2[] = {2,3,4,4,5};
    int n1 = size(arr1);
    int n2 = size(arr2);
    vector <int> result = union_array(arr1,arr2,n1,n2); 
    
    for(int i : result){
        cout<<i<<" ";
    }
    return 0;
}




//------------------------------ union ---------------------optimal
#include<bits/stdc++.h>
using namespace std;

vector <int> union_array(vector<int> a,vector<int> b){
    vector <int> temp;
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    while(i < n1 && j<n2){
        if(a[i] > b[j]){
            if(temp.empty() || temp.back() != b[j]){
                temp.push_back(b[j]);
            }
            j++;
        }else if(a [i] < b[j] ){
            if(temp.empty() || temp.back() != a[i]){
                temp.push_back(a[i]);
            }
            i++;
        }else{
            if(temp.empty() || temp.back() != a[i]){
                temp.push_back(a[i]);
            }
            i++;
            j++;
        }
    }
    
    while(i < n1){
        if( temp.empty() || temp.back() != a[i] ){
            temp.push_back(a[i]);
        }
        i++;
    }
    
    while(j < n2){
        if (temp.empty() ||temp.back() != b[j]){
            temp.push_back(b[j]);
        }
        j++;
    }
    return temp;
}


int main(){
    vector <int> a = {1,2,3,4,5};
    vector <int> b= {2,3,4,4,5};
    vector <int> result = union_array(a,b);
    
    for(int i : result){
        cout<<i<<" ";
    }
    return 0;
}

//============intersection
#include<bits/stdc++.h>
using namespace std;

vector <int> intersection(vector<int>a1,vector<int>a2){
    int n1 = a1.size();
    int n2 = a2.size();
    int i = 0;
    int j = 0;
    vector <int> temp;
    while(i < n1 && j < n2){
        if (a1[i] < a2[j]){
            i++;
        }
        else if(a1[i] > a2[j]){
            j++;
        }
        else{
            if(temp.empty() || temp.back() != a1[i]){
                temp.push_back(a1[i]);
            }
            i++;
            j++;
        }
    }
    return temp;
}


int main(){
    vector <int> a1 = {1,1,2,2,3,3,4,4,5,5};
    vector <int> a2 = {1,2,2,3,3,4};
    vector <int> result =intersection(a1,a2);
    
    for(int i : result){
        cout<<i<<" ";
    }
    return 0;
}

