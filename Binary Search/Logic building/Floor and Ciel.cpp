// brute force method for the problem 
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

// the time complexity of the code is O(n);
// the space complexity of the code is O(1)  vector used only for the answer returns not for the execution 



// ----------------------------------------------------Optimal  way (created by myself)--------------------------
// here i have use the single while loop to find the floor and ciel with the condition modified 
#include<bits/stdc++.h>
using namespace std;

vector <int> FloorCiel(vector <int> &arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int floor = -1;
    int ciel = - 1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] == target){
            floor = target;
            ciel = target;
            break;
        }
        else if(arr[mid] > target){
            ciel = arr[mid];
            high = mid -1;
        }else{
            floor = arr[mid];
            low = mid + 1;
        }
    }

    return vector <int> {floor,ciel};
}


int main(){
    vector <int> arr = {3, 4, 4, 7, 8, 10};
    int target = 8;
    vector <int> result = FloorCiel(arr,target);
    for(auto i : result){
        cout<<i<<" ";
    }
    return 0;
}

//----------------------------------------------optimal solution ---------------------------
// the differnce between the first code and the second code is 
// the second code use the two while loops to find the floor and ciel seperatly 
// both the code is correct, here you need to change the low and high back to 0,n-1 after the first while loop


#include <bits/stdc++.h>
using namespace std;

vector<int> FloorCeil(vector<int> &arr, int target) {
    int n = arr.size();
    int low = 0, high = n - 1;
    int floor = -1;
    int ceil = -1;

    // 1. Find Floor using Binary Search
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] <= target) {
            floor = arr[mid]; // Potential floor found
            low = mid + 1;    // Try to find a larger value closer to target
        } else {
            high = mid - 1;   // Value is too big, move left
        }
    }

    // Reset pointers to find Ceiling
    low = 0; 
    high = n - 1;

    // 2. Find Ceiling using Binary Search
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] >= target) {
            ceil = arr[mid];  // Potential ceiling found
            high = mid - 1;   // Try to find a smaller value closer to target
        } else {
            low = mid + 1;    // Value is too small, move right
        }
    }

    return {floor, ceil};
}

int main() {
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int target = 5;
    
    vector<int> result = FloorCeil(arr, target);
    for (auto i : result) {
        cout << i << " ";
    }
    return 0;
}


