
///---------------------------leader-------
//brute force method ---i have tried 
#include<bits/stdc++.h>
using namespace std;

list <int> leader(vector<int>arr){
    list <int> temp;
    int n = arr.size();
    temp.push_front(arr[n-1]);
    for(int i = n - 2; i >= 0; i--){
        int flag = 0;
        for(int j = i + 1; j < n; j++){
            if(arr[i] <= arr[j]){
                flag++;
            }
        }
        if(flag == 0){
            temp.push_front(arr[i]);
        }
    }

    return temp;
}


int main(){
    vector <int> arr = {4, 7, 1, 0};
    list <int> result = leader(arr);
    for(auto i : result){
        cout<<i<<" ";
    }
    return 0;
}


/////---------brute force


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Function to find leaders in an array.
    vector<int> leaders(vector<int>& nums) {
        vector<int> ans;

        // Iterate through each element in nums
        for (int i = 0; i < nums.size(); i++) {
            bool leader = true;

            /* Check whether nums[i] is greater
            than all elements to its right*/
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] >= nums[i]) {
                    /* If any element to the right is greater 
                    or equal, nums[i] is not a leader*/
                    leader = false;
                    break;
                }
            }

            // If nums[i] is a leader, add it to the ans vector
            if (leader) {
                ans.push_back(nums[i]);
            }
        }

       //Return the leaders 
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 5, 3, 1, 2};

    // Create an instance of the Solution class
    Solution finder;

    // Get leaders using class method
    vector<int> ans = finder.leaders(nums);

    cout << "Leaders in the array are: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}


