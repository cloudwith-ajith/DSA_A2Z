// ----------------------------------------cpp

// --largest element in the array
// --my code
#include<bits/stdc++.h>
using namespace std;

int max_element(int arr[],int n){
    int max = 0;
    for(int i = 0;i < n;i++){
        if(arr[i] > arr[max]){
            max = i;
        }
    }
    return arr[max];
}

int main(){
    int arr[5] ={2,5,1,3,0};
    int n = size(arr);
    cout<<max_element(arr,n);
    return 0;
}

//--using the sorted method
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[5] ={2,5,1,3,0};
    int n = size(arr);
    sort(arr,arr+n);
    // for(int i :arr){cout<<i<<" ";}
    // return 0;
    
    cout<<arr[n-1];
    return 0;
}
//--------------------------------using vector
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={2,5,1,3,0};
    sort(arr.begin(),arr.end());
    cout<<arr[arr.size()-1];
    return 0;
}
// --------------------------------second --largest element in the array
// --brute force method
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[5] ={39,33,21,39,39};
    int n = size(arr);
    
    sort(arr,arr+n);
    
    int second_large = n-2;
    for(int i = n-1;i > 2;i--){
        if(arr[i] != arr[second_large]){
            break;
        }else{
            second_large =second_large - 1;
        }
    }
    cout<<arr[second_large];
    return 0;
}

//---------better

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[6] ={1,4,3,2,10,7};
    int n =size(arr);
    
    int max = 0;
    for(int i = 1;i < n;i++){
        if(arr[i] > arr[max]){
            max = i;
        }
    }
    int s_max =0;
    for(int i =0;i < n;i++){
        if(arr[i] > arr[s_max] && arr[i] < arr[max]){
            s_max = i;
        }
    }
    cout<<arr[s_max];
    return 0;
}

