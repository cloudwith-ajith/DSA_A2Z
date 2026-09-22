#include<bits/stdc++.h>
using namespace std;

vector <int> FloorCeil(vector <int> &arr, int target){
    int n = arr.size();
    int floor = -1;
    int ciel = -1;

    for(int i = 0 ; i < n; i++){
        if(arr[i] == target){
            floor = arr[i];
            ciel  = arr[i];
            break;
        }else if(arr[i] > target){
            ciel = arr[i];
            break;
        }else{
            floor = arr[i];
        }
    }

    return vector <int> {floor,ciel};
}


int main(){
    vector <int> arr = {3, 4, 4, 7, 8, 10};
    int target = 5;
    vector <int> result = FloorCeil(arr,target);
    for(auto i : result){
        cout<<i<<" ";
    }
    return 0;
}
