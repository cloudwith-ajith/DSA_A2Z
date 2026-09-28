// Brute force method 

#include<bits/stdc++.h>
using namespace std;

int floorsquare(int num) {
    int answer = 0;
    for (int i = 0; i * i <= num; i++) {
        answer = i;
    }
    return answer;
}

int main(){
    int number = 36;
    int result = floatsquare(number);
    cout<<result;
    return 0;
}

// The Time complexity of the code is O(n)
// The Space complexity of the code is O(1)

//------------------------------optimal way----------


#include<bits/stdc++.h>
using namespace std;

int floorSqrt(int target){
    // Handle negative numbers safely
    if (target < 0) return -1; 

    int answer = 0;
    long long low = 0;
    long long high = target;

    while(low <= high){
        long long mid = low + (high - low) / 2; // Prevents overflow during addition

        if((mid * mid) <= target){
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return answer;
}

int main(){
    int number = 50;
    int result = floorSqrt(number);
    cout << result; // Outputs: 7
    return 0;
}

// The Time complexity of the code is O(log n)
// The Space complxity of the code is O(1)

