//-------------------union of the arrays 
//----using the set
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr_1[] = {1,2,3,4,5,6,7,8,9,10};
    int arr_2[] = {2,3,4,4,5,11,12};
    int  n_1 = sizeof(arr_1)/sizeof(arr_1[0]);
    int  n_2 = sizeof(arr_2)/sizeof(arr_2[0]);
    set <int> sets;
    
    for(int i = 0 ; i < n_1; i++){
        sets.emplace(arr_1[i]);
    }
    
    for(int i = 0; i < n_2; i++){
        sets.emplace(arr_2[i]);
    }
    
    for(int i : sets){
        cout<<i<<" ";
    }
    
    return 0;
}

//---------------optimal approach

#include<bits/stdc++.h>
using namespace std;

vector<int> unionarr(vector<int> arr1,vector<int>arr2){
    int a1_size = arr1.size();
    int a2_size = arr2.size();
    vector <int> temp;
    int i = 0;
    int j = 0;
    while(i < a1_size && j < a2_size){
        if(arr1[i] > arr2[j]){
            if( temp.size() == 0 || temp.back() != arr2[j]){
                temp.push_back(arr2[j]);
            }
            j++;
        }else if(arr1[i] < arr2[j]){
            if(temp.size() == 0 || temp.back() != arr1[i]){
                temp.push_back(arr1[i]);
            }
            i++;
        }else {
            if(temp.size() == 0 || temp.back() != arr1[i]){
                temp.push_back(arr1[i]);
            }
            i++;
            j++; // Move both pointers forward
        }
    }
    
    while(i < a1_size){
        if(temp.size() == 0 || temp.back() != arr1[i]){
                temp.push_back(arr1[i]);
        }i++;
    }
    
    while(j < a2_size){
        if( temp.size() == 0 || temp.back() != arr2[j]){
                temp.push_back(arr2[j]);
        }
        j++;
    }
    return temp;
}
int main(){
    
    vector <int> arr1 ={1,2,3,4,5,6,7,8,9,10};
    vector <int> arr2 ={1,2,3,4,7,8};
    vector<int> result = unionarr(arr1,arr2);
    
    for(int i : result){
        cout<<i<<" ";
    }
    return 0;
    
}
