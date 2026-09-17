// brute force method for the problem
#include<bits/stdc++.h>
using namespace std;

int CountInver(vector <int> &arr){   
    int n = arr.size();   
    int counter = 0; 
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){ 
                counter++;
            }    
        }
    } 
    return counter;
}

int main(){
    vector <int> arr = {5,3,2,1,4};
    int res = CountInver(arr);
    cout<<res;
    return 0;
}
// The Time complexity of the code is O(n^2)
// The Space complexity of the code is O(n)


//-----------------optimal way with merge sort 


#include<bits/stdc++.h>
using namespace std;

int merge(int arr[], int low, int mid, int high){
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    int counter = 0;

    // Correct condition: both pointers must stay within their respective halves
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        } else {
            // If arr[left] > arr[right], all elements from 'left' to 'mid' form inversions
            counter += (mid - left + 1);
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy remaining elements of the left half, if any
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements of the right half, if any
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the sorted elements back into the original array from low to high
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
    
    return counter;
}

int merge_sort(int arr[], int low, int high){
    int counter = 0;
    if(low < high){
        int mid = low + (high - low) / 2;
        
        counter += merge_sort(arr, low, mid);       // Left half
        counter += merge_sort(arr, mid + 1, high); // Right half
        counter += merge(arr, low, mid, high);     // Merge halves
    }
    return counter; // Returns 0 if low >= high
}

int CountInversions(int arr[], int n){
    return merge_sort(arr, 0, n - 1);
}

int main(){
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = CountInversions(arr, n);
    cout << "Number of inversions: " << result; // Expected Output: 10
    return 0;
}


// the time complexity of the code is O(nlogn)
// The Space complexity of the code is O(1)
