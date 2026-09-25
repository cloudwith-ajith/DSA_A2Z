// optimal solution using the lower bound and the upper bound


#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector <int> &arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int lower = n;
    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] >= target){
            lower = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return lower;
}



int upperbound(vector <int> &arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int upper = n;
    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] > target){
            upper = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return upper;
}
 
int CountOcc(vector <int> &arr, int target){
    int first_occ = lowerbound(arr,target);

    if( first_occ == (int) arr.size() || arr[first_occ] != target ){
        return 0;
    }

    int last_occ = upperbound(arr,target);

    return last_occ - first_occ;

}
 


int main(){
    vector <int> arr ={1, 1, 2, 2, 2, 2, 3};
    int target = 2;
    int result = CountOcc(arr,target);
    cout << result;
    return 0;
}

// the time complexity of the code is O(log n)
// the space complexity of the code is O(1)


///++++++++++++++++++++++++++++++++++++++++++++++++using the pure binray search without the lower and upper bound++++++++++++++++++++++++++++




#include<bits/stdc++.h>
using namespace std;

int first_occ(vector <int> &arr, int target){
    int n = arr.size();
    int low = 0; 
    int high = n - 1;
    int first = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target){
            first = mid;
            high = mid - 1;
        }else if(arr[mid] > target){
            high = mid -1 ; 
        }else{
            low = mid + 1;
        }
    }

    return first;
}

int last_occ(vector <int> &arr, int target){
    int n = arr.size();
    int low = 0; 
    int high = n - 1;
    int last = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target){
            last = mid;
            low = mid + 1;
        }else if(arr[mid] > target){
            high = mid -1 ; 
        }else{
            low = mid + 1;
        }
    }

    return last;
}



int CountOcc(vector <int> &arr, int target){
    int firstocc = first_occ(arr,target);

    if(firstocc == -1){
        return 0;
    }

    int lastocc = last_occ(arr,target);

    return ((lastocc - firstocc )+ 1);

}
 


int main(){
    vector <int> arr ={1, 1, 2, 2, 2, 2, 3};
    int target = 2;
    int result = CountOcc(arr,target);
    cout << result;
    return 0;
}



// The Time complexity of the code is O(log n)
// The space complexity of the code is O(1)


