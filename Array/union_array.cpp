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
