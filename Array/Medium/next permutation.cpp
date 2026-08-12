#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {3,2,1};
    
    // Modifies arr to the next permutation in-place
    next_permutation(arr.begin(), arr.end()); 
    
    for(int i : arr){
        cout << i << " ";
    }
    return 0;
}

//brute force method

#include<bits/stdc++.h>
using namespace std;

vector <int> next_permutitation(vector <int> arr){
    //create the vector to store the permutation element
    vector <vector <int>> temp;
    vector<int> original_arr = arr;
    //sort the given array to do permutation 
    sort(arr.begin(),arr.end());
    //create the combination using the cpp stl
    //next_permutation
    do{
        temp.push_back(arr);
    }while(next_permutation(arr.begin(),arr.end()));
    //return the next permutation 
    for(int i = 0 ; i < temp.size();i++){
        if(temp[i] == original_arr){
            if(i == temp.size() - 1){
                return temp[0];
            }
            return temp[i+1];
        }
    }
    return original_arr;
}

int main(){
    vector <int> arr = {1,3,2};
    vector result = next_permutitation(arr);
    for(int i : result){
        cout<<i<<" ";
    }
    return 0;
}
