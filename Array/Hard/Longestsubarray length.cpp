#include<bits/stdc++.h>
using namespace std;

int lonlen(vector<int> &arr, int target){ 
    int n = arr.size();
    unordered_map <int,int> mpp;
    // max lent 
    int maxlen = 0;
    int sum = 0 ;
    for(int i = 0 ; i < n; i++){
        // add the sum
        sum += arr[i];
        // the sum equal to the target  
        // then the len from the zero to is a subarray
        if(sum == target){  
            maxlen = i + 1;
        }else if(mpp.find(sum) != mpp.end()){                
             maxlen = max(maxlen, i - mpp[sum]);
        }else{
                // the condition is the prefix is not in the array then add
                mpp[sum] = i;     
            }  
        }
    //return the maxlen  
    return maxlen;
}  


int main(){
    vector<int> arr = {9, -3, 3, -1, 6, -5};
    int target = 0 ;
    int result = lonlen(arr,target);
    cout<<result;
    return 0;
}


// brute force method of the length of the longest subarray equal to the zero
#include<bits/stdc++.h>
using namespace std;

int lls(vector<int> &arr) {
	int n = arr.size();
	// To count the length
	int maxlen = 0;
	// first loop for the subarray starting
	for(int i = 0; i < n; i++) {
		// this count the total sum of the subarray
		int sum = 0;
		for(int j = i; j < n; j++) {
			sum += arr[j];
			//if the sum equal to the zero then
			if(sum == 0) {
				// we need to check the lenght of the subarray and
				//need to update in the maxlen
				maxlen = max(maxlen, j - i + 1);
			}
		}
	}
	// finally return the maxlen of the subarray
	return maxlen;
}

int main() {
	vector <int> arr = {9, -3, 3, -1, 6, -5};
	int result = lls(arr);
	cout<<result;
	return 0;
}

// The Time complexity of the code is O(N^2)
// The space complexity of the code is O(1)


// The optimal way for the code
#include<bits/stdc++.h>
using namespace std;
// function to return the length of the subarray
int lls(vector <int> &arr) {
	int n = arr.size();
	// To store the prefix and the indexes
	unordered_map <int,int> mpp;
	// maxlen variable
	int maxlen = 0;
	// counter variable
	int sum = 0;
	// single loop for the check
	for(int i = 0; i < n; i++) {
		//  prefix sum of the array
		sum += arr[i];
		// if the prefix sum equal to the zero
		// then the longest subarray is find in the array
		if(sum == 0) {
			maxlen = i + 1;
		} 
		// if sum is present in the hashmap, then the element between
		//the current sum and the already figure out sum has the zero summation
		else if(mpp.find(sum) != mpp.end()) {
			// get the length of the longest subarray
			maxlen = max(maxlen, i - mpp[sum]);
		} else {
			// if there is no sum present in the hashmap then add
			// because, if you add the sum for every element,
			//it should not give the longest lenght of the subarray
			mpp[sum] = i;
		} 
	}
	// return the maxlen
	return maxlen;
}

int main() {
	vector <int> arr = {9, -3, 3, -1, 6, -5}; 
	int result = lls(arr);
	cout<<result;
	return 0;
}

// The time complexity of the code is O(n )
// n for the single loop iteration and the o(1) for the hashmap searching..
// The space complexity of the code is O(N)
