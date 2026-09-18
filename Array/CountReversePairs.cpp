//brute force method for the problem 

#include<bits/stdc++.h>
using namespace std;

int CountReverse(vector <int> &arr){
    int n = arr.size();
    int counter = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > (2 * arr[j])){
                counter++;
            }
        }
    }
    return counter;
}
int main(){
    vector <int> arr = {4, 1, 2};
    int result = CountReverse(arr);
    cout<<result;
    return 0;
}

// The time complexity of the code is  O(n^2)
// The Space complexity of the code is O(1)

///Optimal way 


#include<bits/stdc++.h>
using namespace std;

int Merge(vector <int> &arr, int low, int mid, int high){
    
    //---------------------Reverse count part------------
    int j = mid + 1;
    int counter = 0;
    for(int i = low; i <= mid; i++){
        while( j <= high && arr[i] > 2LL * arr[j]){
            j++;
            counter = counter + (j - (mid + 1));
        }
    }
    //---------------------Merge part--------------------
    int left = low;
    int right = mid + 1;
    vector <int> temp;
    while( left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
     while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
    //--------------return the counter;
    return counter;
}


int Mergesort (vector <int> &arr,int low, int high){
    int count = 0;
    if(low < high){
        int mid =  (low + high) / 2;
        count += Mergesort(arr,low,mid);
        count += Mergesort(arr,mid+1,high);
        count += Merge(arr,low,mid,high);
    }
    return count;
}

int CountReverse( vector <int> &arr,int n ){
    return Mergesort(arr, 0, n-1);
}

int main(){
    vector <int> arr = {1,3,2,3,1};
    int n = arr.size();
    int result = CountReverse(arr,n);
    cout<<result;
    return 0;
}

// The Time complexity of the code is O(nlogn)
// The Space complexity of the code is O(1)
