/---------------------------Rearrange the array by sign 

#include<bits/stdc++.h>
using namespace std;

void Rearrange(int arr[], int n){
    vector <int> temp_pos;
    vector <int> temp_neg;
    //get the positive and negative to the temp array 
    for(int i = 0 ; i < n; i++){
        if(arr[i] > 0){
            temp_pos.push_back(arr[i]);
        }else{
            temp_neg.push_back(arr[i]);
        }
    }
    //Rearrange the original array
    // int pos_count = 0;
    // int neg_count = 0;
    // for(int i =0; i < n; i++){
    //     if(i % 2 == 0){
    //         arr[i] = temp_pos[pos_count];
    //         pos_count++;
    //     }else{
    //         arr[i] = temp_neg[neg_count];
    //         neg_count++;
    //     }
    // }
    //another way to rearrange
    for(int i = 0 ; i < n/2; i++){
        arr[i*2] = temp_pos[i];
        arr[i*2+1] = temp_neg[i]; 
    }
}


int main(){
    int arr[] = {1,2,-4,-5};
    int n = sizeof(arr)/sizeof(arr[0]);
    Rearrange(arr,n);
    for(int x : arr){
        cout<<x<<" ";
    }
    return 0;
}
//----------optimal way

#include<bits/stdc++.h>
using namespace std;


vector<int>Rearrange(int arr[],int n){
    vector <int> temp(n,0);

    int posindex = 0;
    int negindex = 1;

    for(int i = 0; i < n ;i++){
        if(arr[i] > 0){
            temp[posindex] = arr[i];
            posindex += 2;
        }else{
            temp[negindex] = arr[i];
            negindex +=2;
        }
    }

    return temp;
    
}


int main(){
    int arr[] = {1, 2, -4, -5};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector <int> result =  Rearrange(arr,n);
    for(auto i : result){
        cout<<i<<" ";
    }
    return 0;
}

// the time complexity of the solution is O(n)
// the space complexity of the solution is o(n)
