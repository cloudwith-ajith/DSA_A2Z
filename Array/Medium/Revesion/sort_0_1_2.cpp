
//--------------------optimal way for the sort 0,1,2
#include<bits/stdc++.h>
using namespace std;

void sort_0_1_2(vector<int> &arr){
    int n = arr.size();
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid <= high){
        if(arr[mid] == 1){
            mid++;
        }else if(arr[mid] == 0){
            swap(arr[low],arr[mid]);
            mid++;
            low++;
        }else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }

    for(auto  i : arr){
        cout<<i<<" ";
    }
}

int main(){
    vector <int> arr = {2, 0, 2, 1, 1, 0};
    sort_0_1_2(arr);
    return 0;
}

//brute force method 

#include<bits/stdc++.h>
using namespace std;

void sort_0_1_2(vector<int> &arr){
    int n = arr.size();
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0) count0++;
        else if(arr[i]==1) count1++;
        else count2++;
    }
    for(int i = 0 ; i < count0; i++){
        arr[i] = 0;
    }
    for(int i = count0 ; i < count0+count1; i++){
        arr[i] = 1;
    }
    for(int i = count0+count1 ; i < n; i++){
        arr[i] = 2;
    }

    for(auto i : arr){
        cout<<i<<" ";
    }

}

int main(){
    vector <int> arr = {2, 0, 2, 1, 1, 0};
    sort_0_1_2(arr);
    return 0;
}
