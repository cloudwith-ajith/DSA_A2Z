// brute force method 

#include<bits/stdc++.h>
using namespace std;

int smallestdivisor(vector <int> &arr, int x){
    int n = arr.size();
    int maxs = *max_element(arr.begin(),arr.end());
    int answer = 0;
    for(int i = 1; i <= maxs; i++){   
        int ans = 0;
        for(int j = 0; j < n; j++){
            ans += (arr[j] + ( i - 1)) / i;
        }
        if(ans <= x){
            answer = i;
            break;
        }
    }

    return answer;
}


int main(){
    vector <int> arr = {8,4,2,3};
    int limit = 10;
    int result = smallestdivisor(arr,limit);
    cout<<result;
    return 0;
}

// the time complexity of the code is O(max * n)
// the space complexity of the code is O(1)




///++++++++++++++++++++++++++++++++++++++++++++++++optimal way


#include<bits/stdc++.h>
using namespace std;

bool findDivisor(vector <int> &arr, int divisor, int threshold){
    int n = arr.size();
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += (arr[i] + (divisor - 1)) / divisor;
    }
    if(sum <= threshold){
        return true;
    }

    return false;
}

int smallestDivisor(vector <int> &arr, int threshold){
    
    int maxy = *max_element(arr.begin(),arr.end());
    int high = maxy;
    int low = 1;
    int answer = -1;

    while(low <= high){
        int mid = (low + high) / 2;
        if(findDivisor(arr,mid,threshold)){
            answer = mid;
            high = mid - 1;
        }else{
            low = mid +1;
        }
    }

    return  answer;
}


int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int threshold = 8;
    cout<<smallestDivisor(nums, threshold);
    return 0;
}

//the time compleity of the code is
//Time Complexity: O(N x log2(max(nums))), N is the length of array, and we perform binary search on our answer range which is 1 to max(nums) taking complexity of log(max(nums)) and each check iterates over full nums.

//Space Complexity: O(1), because constant space is used.
