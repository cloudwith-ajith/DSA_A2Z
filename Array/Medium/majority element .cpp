//majority element in the array which mean n/2 
//-------------I tried with my way 
#include<bits/stdc++.h>
using namespace std;

int majority(vector <int> arr){
    //sort the array to find the unique element
    sort(arr.begin(),arr.end());
    // create the temp array to store the unique element
    vector <int> unique;
    //find the unique element 
    for(int i = 0 ; i < arr.size(); i++){
        if(unique.empty() || arr[i] != unique.back() ){
            unique.push_back(arr[i]);
        }
    }
    
    // count the majority element
    int element = 0;
    int max_count = 0;
    for(int i = 0; i < unique.size();i++){
        int count = 0 ;
        for(int j = 0 ; j < arr.size(); j++){
            if(unique[i] == arr[j]){
                count++;
            }
        }
        if(count > max_count){
            max_count = count;
            element = unique[i];
        }
    }
    return element;
}

int main(){
    vector <int> arr = {7, 0, 0, 1, 7, 7, 2, 7, 7};
    int result = majority(arr);
    cout<<result;
    return 0;
}
//------------Time complexity O(3n)
//------------Space complexityO(n)
