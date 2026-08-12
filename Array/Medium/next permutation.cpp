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


//---optimal and the Narayana Pandita's Algorithm/ next permutation algo 

#include<bits/stdc++.h>
using namespace std;


void nxt_permutation(vector<int> &arr){
    //create the pivot that used to find the first smallest element than the right one 
    int pivot = -1;
    //size of the vector
    int n =  arr.size();
    //getting the pivot
    for(int i = n-2; i >= 0; i--){
        if(arr[i] < arr[i+1]){
            pivot = i;
            break;
        }
    }

    //if the pivot is still -1 or it is the last permutation of the number 
    // so just reverse the number and return 
    if(pivot == -1){
        reverse(arr.begin(),arr.end());
        return ;
    }
    //finding the first largest element thatn the pivot 
    //and swap with the pivot 
    for(int i  = n -1; i >= 0 ; i--){
        if(arr[i] > arr[pivot]){
            swap(arr[i],arr[pivot]);
            break;
        }
    }
    //after swap if you see the element right after the pivot all in the descending order
    // try to reverse the number 
    reverse(arr.begin()+pivot+1,arr.end());
}



int main(){
    vector <int> arr = {1,3,2};
    nxt_permutation(arr);
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}

//----- the time complexity of the solution is O(n)
//----- the space complexity of the solution of the solution is O(1)

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//////------------------previous permutation-----------//
//---simple do all opposite the algo 


#include<bits/stdc++.h>
using namespace std;

void prev_permutation_custom(vector<int> &arr) {
    int n = arr.size();
    int pivot = -1;

    // Step 1: Find the first element breaking the ascending order from right
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > arr[i + 1]) {
            pivot = i;
            break;
        }
    }

    // Step 2: If no pivot found, reverse the entire array
    if (pivot == -1) {
        reverse(arr.begin(), arr.end());
        return;
    }

    // Step 3: Find the largest element to the right of pivot that is smaller than arr[pivot]
    for (int i = n - 1; i > pivot; i--) {
        if (arr[i] < arr[pivot]) {
            swap(arr[i], arr[pivot]);
            break;
        }
    }

    // Step 4: Reverse the suffix to make it lexicographically largest
    reverse(arr.begin() + pivot + 1, arr.end());
}

int main() {
    vector<int> arr = {1, 3, 2};
    prev_permutation_custom(arr);
    
    for (int i : arr) {
        cout << i << " ";
    }
    // Output: 1 2 3
    return 0;
}
