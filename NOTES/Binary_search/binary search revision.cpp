#include<bits/stdc++.h>
using namespace std;

int MaxOnes( vector<vector<int>> &arr){
    int n = arr.size();
    int m = arr[0].size();

    int answer = -1;
    int maxcount  = -1;

    for(int i = 0; i < n; i++ ){
        int count = 0;
        for(int  j = 0; j < m; j++){
            if(arr[i][j] == 1){
                count++;
            }
        }

        if(count > maxcount){
            maxcount = count;
            answer = i;
        }
    }

    return answer;
}


int main(){
    vector<vector<int>> mat = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1}
    };
    cout<<MaxOnes(mat);
    return 0;
}


-------------------------------optimal way for the problem 

#include<bits/stdc++.h>
using namespace std;

int MaxOnes(vector<vector<int>> &arr){
    int rows = arr.size();
    int colm = arr[0].size();

    int row = 0;
    int col = colm - 1;
    int answer = -1;

    while(row < rows && col >= 0){
        if(arr[row][col] == 1){
            answer = row;
            col--;
        }else{
            
            row++;
        }
    }

    return answer;

    
    
}

int main(){
    vector<vector<int>> mat = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1}
    };
    cout<<MaxOnes(mat);
    return 0;
}
-----------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

bool searchTwod(vector<vector <int>> &arr, int target){
    // Edge case: Empty matrix
    if(arr.empty() || arr[0].empty()) return false;

    int row = arr.size();
    int col = arr[0].size();

    int low = 0;
    int high = (row * col) - 1; // FIX 1: Set high to the last valid 0-based index

    while(low <= high){
        int mid = low + (high - low) / 2; // Best practice: Prevents potential integer overflow

        int r = mid / col;
        int c = mid % col;

        if(arr[r][c] == target){
            return true;
        }else if(arr[r][c] > target){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return false;
}          

int main(){
    vector <vector <int> > arr = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 2;
    if(searchTwod(arr, target)){
        cout << "true";
    }else{
        cout << "false";
    }
    return 0;
}

-------------------------------------------------------------------------------------------


#include<bits/stdc++.h>
using namespace std;

// FIX: Changed return type from 'int' to 'bool'
bool twod(vector <vector <int>> &arr, int target ){
    // Good practice: Check if matrix is empty
    if(arr.empty() || arr[0].empty()) return false;

    int rows = arr.size();
    int cols = arr[0].size();

    int row = 0;
    int col = cols - 1;

    while(row < rows && col >= 0){
        if(arr[row][col] == target){
            return true;
        }else if(arr[row][col] > target){
            col--; // Move left
        }else{
            row++; // Move down
        }
    }

    return false;
}

int main(){
    vector <vector <int> > arr = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 12;
    if(twod(arr, target)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}



-------------------------------------------------------------


#include<bits/stdc++.h>
using namespace std;

vector <int> peak(vector <vector <int> > &arr){
    int rows = arr.size();
    int colm = arr[0].size();

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < colm; j++){
            int up = -1;

            if(i  > 0 ){
                up = arr[i - 1][j];
            }

            int down = -1;
            if(i + 1 < rows ){
                down = arr[i + 1][j];
            }

            int left = -1;
            if(j > 0 ){
                left = arr[i][j - 1];
            }
            int right = -1;
            if(j + 1 < colm){
                right = arr[i][j + 1];
            }

            if(arr[i][j] > right && arr[i][j] > left && arr[i][j] > up && arr[i][j] > down){
                return {i , j};
            }
        }
    }

    return {-1, -1};
}



int main(){
    vector <vector <int> > arr = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32} 
    };
    vector <int> a = peak(arr);
    for(auto i : a){
        cout<<i<<" ";
    }
    return 0;
}

????????????????????????????????????????????optimal way 




#include<bits/stdc++.h>
using namespace std;

int helper_function(vector <vector <int> > &arr, int n, int m, int col){
    int maxi = -1;
    int answer = -1;

    for(int i = 0; i < n; i++){
        if(arr[i][col] > maxi){
            maxi = arr[i][col];
            answer = i;
        }
    }

    return answer;
}

vector <int> peak(vector <vector <int> > &arr){
    int rows = arr.size();
    int colm = arr[0].size();

    int low = 0;
    int high = colm - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        // FIX 1: Pass rows (not row) and colm correctly
        int row = helper_function(arr, rows, colm, mid); 

        // FIX 2: Check boundaries using 'mid' instead of 'row'
        int left = (mid > 0) ? arr[row][mid - 1] : -1;
        int right = (mid + 1 < colm) ? arr[row][mid + 1] : -1;

        if(arr[row][mid] > left && arr[row][mid] > right){
            return {row, mid};
        }
        // FIX 3: Update low and high to prevent an infinite loop
        else if (arr[row][mid] < right) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    
    return {-1, -1};
}

int main(){
    vector <vector <int> > arr = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32} 
    };
    vector <int> a = peak(arr);
    for(auto i : a){
        cout << i << " ";
    }
    return 0;
}



///-----------------------------------------------

upper bound

#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector <int> &arr, int x){
    int n = arr.size();
    int answer = -1;

    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid =  low + (high - low)/ 2;

        if(arr[mid] > x ){
            answer = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return answer;
}



int main(){
    vector <int> arr = {3,5,8,9,15,19};
    int x = 9;
    cout<<lowerbound(arr, x);
    return 0;
}



-------------------------------------------------
lower bound 


#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector <int> &arr, int x){
    int n = arr.size();
    int answer = -1;

    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid =  low + (high - low)/ 2;

        if(arr[mid] > x ){
            answer = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return answer;
}



int main(){
    vector <int> arr = {3,5,8,9,15,19};
    int x = 9;
    cout<<lowerbound(arr, x);
    return 0;
}


//----------------------------------------ciel  and the foor --------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

vector <int> lowerbound(vector <int> &arr, int x){
    int n = arr.size();
    int ciel = -1;

    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid =  low + (high - low)/ 2;

        if(arr[mid] >= x ){
            ciel = arr[mid];
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    

    low = 0 ;
    high = n - 1;
    int floor =  -1;
    while(low <= high){
        int mid = low + (high - low ) / 2;

        if(arr[mid] <= x){
            floor = arr[mid];
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return vector <int> { floor,ciel };
}



int main(){
    vector <int> arr = {3, 4, 4, 7, 8, 10};
    int x = 5;
    vector <int> c = lowerbound(arr, x);

    for(auto j : c){
        cout<<j<<" ";
    }
    return 0;
}


//-----------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;


int lastOccu(vector <int> &arr, int target){
    int n = arr.size();

    int low = 0;
    int high = n - 1;
    int answer = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target){
            answer = mid;
            low = mid + 1;
        }else if(arr[mid] < target ){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return answer;
}

int main(){
    vector <int> arr = {5, 7, 7, 8, 8, 10};
    int target = 8;
    cout<<lastOccu(arr,target);
    return 0;
}



-------------------------------------------------------------------------
//search in rotate array 


#include<bits/stdc++.h>
using namespace std;


bool search(vector <int> &arr, int target){
    int n = arr.size();

    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[mid] == target){
            return true;
        }
        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target < arr[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else{
            if(arr[mid] < target && target <= arr[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }

    return false;
}



int main(){
    vector <int>  arr = {4,5,6,7,0,1,2,3};
    int target = 8;
    if(search(arr, target)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}



---------------------------------- duplicate


#include<bits/stdc++.h>
using namespace std;



bool search(vector <int>  &arr, int target){
    int n = arr.size();

    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[mid] == target){
            return true;
        }
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            high--;
            low++;
        }

        else if(arr[low] <= arr[mid]){
            if(arr[low] <= target && arr[mid] >  target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else{
            if(arr[mid] < target && arr[high] >= target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }

    return false;
}




int main(){
    vector <int> arr = {3,1,2,3,3,3,3};
    int target = 1;
    if(search (arr,target)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}



----------------------------------------------------------------------------
Find the mini in the rotate array 
#include<bits/stdc++.h>
using namespace std;


int MiniArray(vector <int> &arr){
    int n = arr.size();

    int low = 0;
    int high = n - 1;
    int mini = INT_MAX;
    while(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[low] <= arr[mid]){
            mini = min(mini, arr[low]);
            low = mid + 1;
        }else{
            mini = min(mini, arr[mid]);
            high = mid - 1;
        }
    }

    return mini;
}

int main(){
    vector <int> arr = {4, 5, 6, 7, 1, 2, 3};
    cout<<MiniArray(arr);
    return 0;
}


//-------------------------------------------------------------

// what is the rotation of the array 

#include<bits/stdc++.h>
using namespace std;


int Rotation(vector <int> &arr){
    int n = arr.size();
    int index = -1;
    int mini = INT_MAX;

    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[low] <= arr[mid]){
            if(mini > arr[low]){
                mini = arr[low];
                index = low;
            }
            low = mid + 1;
        }else{
            if(arr[mid] < mini){
                mini = arr[mid];
                index = mid;
            }

            high  = mid - 1;
        }
    }

    return index;
}


int main(){
    vector <int> arr = {4, 5, 6, 7, 0, 1, 2};
    cout<<Rotation(arr);
    return 0;
}



//////////////////////////////////////////////////single element\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

#include<bits/stdc++.h>
using namespace std;

int single(vector <int> &arr){
    int n = arr.size();
    int ans = -1;

    int low = 1;
    int high = n  - 2;

    if(arr[0] != arr[1]){
        return arr[0];
    }

    if(arr[n - 1] != arr[high]){
        return arr[n-1];
    }

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1 ]){
            ans = arr[mid];
            break;
        }else if(arr[mid] == arr[mid - 1] && mid % 2 != 0 || arr[mid] == arr[mid + 1] && mid % 2 == 0){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return ans;
}


int main(){
    vector <int>  arr = {1,1,2,2,3,3,4,5,5,6,6};
    cout<<single(arr);
    return 0;
}


////#include <iostream>
using namespace std;

int perfect_Square(int n) {
    // Handle edge cases for 0 and 1 immediately
    if (n == 0 || n == 1) return n;

    long long low = 1;
    long long high = n; // Changed from n/2 to handle n=1 properly
    long long answer = -1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long square = mid * mid; // Prevents integer overflow

        if (square <= n) {
            answer = mid;
            low = mid + 1; // Look for a larger potential square root
        } else {
            high = mid - 1; // Look for smaller numbers
        }
    }

    return answer;
}

int main() {
    int n = 28;
    cout << "Integer square root of " << n << " is: " << perfect_Square(n) << endl;
    return 0;
}




////////////////////////////
 find the nth root of the number 

#include<bits/stdc++.h>
using namespace std;



int helper_function(int mid, int n){
    int ans = 1;

    for(int i = 0 ; i < n; i++){
        ans = ans * mid;
    }

    return ans;
}



int Root_p(int n , int m){
    int  low = 0;
    int high = m;

    while(low <= high){
       int mid = low + ( high - low  ) / 2;

        int x = helper_function(mid, n);


        if(x == m){
            return mid;
        }

        else if(x < m){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return -1;
}


int main(){
    int n = 4;
    int m = 69;
    cout<<Root_p(n,m);
}

// the time complexity of the code is O(log n + m)
// the space complexity of the code is O(1)



//////////////////////////////////////////////////// find the smallest divisor in the array 

#include<bits/stdc++.h>
using namespace std;



int helper_function(vector <int> arr, int div){
    int n  = arr.size();
    int count = 0;

    for(int i = 0; i < n; i++){
        count += (arr[i] + div - 1) / div;
    }

    return count;
}



int Small_divisor(vector <int> &arr, int threshould){
    int n = arr.size();

    int low = 1;
    int high = *max_element(arr.begin(),arr.end());
    int answer = -1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        int x = helper_function(arr, mid);

        if(x <= threshould){
            answer = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return answer;
}


int main(){
    vector <int> arr = {1,2,5,9};
    int threshould = 6;
    cout<<Small_divisor(arr,threshould);
    return 0;
}


// KOKO banana


#include<bits/stdc++.h>
using namespace std;


int helper_function(vector <int> &arr, int div){
    int n = arr.size();

    int sum = 0;

    for(int i = 0; i < n ; i ++){
        sum += ceil((double)arr[i] / div);
    }

    return sum;
}


int kokoBanana(vector <int> &arr, int h){
    int n = arr.size();
    int low = 1;
    int high = *max_element(arr.begin(),arr.end());

    int answer = -1;

    while(low <= high){
        int mid = low + ( high - low ) / 2;

        int x = helper_function(arr, mid);

        if(x <= h){
            answer = mid;
            high = mid - 1;
        }else{
            low = mid  + 1;
        }
    }

    return answer;
}


int main(){
    vector <int> arr = {30, 11, 23, 4, 20};
    int h = 5;
    cout<<kokoBanana(arr,h);
    return 0;
}



/// bouquets problem


// brute force moethod for the problem

#include<bits/stdc++.h>
using namespace std;


int bouque(vector <int> &arr, int m, int k){
    int n = arr.size();
    int high = *max_element(arr.begin(),arr.end());

    for(int i = 1; i <= high; i++){
        int b = 0;
        int f = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] <= i){
                f++;

                if(f == k){
                    b++;
                    f = 0;
                }
            }else{
                f = 0;
            }
        }

        if( b >= m){
            return i;
        }
    }

    return -1;
}



int main(){
    vector <int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int m = 2;
    int k = 3;
    cout<<bouque(arr,m,k);
    return 0;
}

// optimal code for the problem

#include<bits/stdc++.h>
using namespace std;


int helper_function(vector <int> &arr, int m, int k, int target){
    int b = 0;
    int f = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(arr[i] <= target){
            f++;

            if(f == k){
                b++;
                f = 0;
            }
        }else{
            f = 0;
        }
    }

    return b;
}



int bouquets(vector <int> &arr, int m , int k){
    int low = 0;
    int high = *max_element(arr.begin(), arr.end());
    int answer = -1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        int x = helper_function(arr,m,k,mid);
        if(x >= m ){
            answer = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return answer;
}

int main(){
    vector <int> arr = {7,7,7,7,13,11,12,7};
    int m = 2;
    int k = 3;
    cout<<bouquets(arr,m,k);
    return 0;
}

//------------------------------------------------capacity of the ship

#include<bits/stdc++.h>
using namespace std;

int capacity(vector <int> &arr, int days){
    int n = arr.size();
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(), arr.end(),0);

    for(int i = low; i <= high; i++){
        int sum = 0;
        int day = 1;
        for(int j = 0; j < n; j++){
            if(sum + arr[j] > i){
                sum = arr[j];
                day++;
            }else{
                sum += arr[j];
            }
        }

        if(day <= days){
            return i;
        }
    }
    return -1;
}


int main(){
    vector <int> arr ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    cout<<capacity(arr,days);
    return 0;
}
// optimal way



#include<bits/stdc++.h>
using namespace std;

bool helper_function(vector <int> &arr, int days, int target){
    int n = arr.size();
   
    int sum = 0;
    int day = 1;
    for(int j = 0; j < n; j++){
        if(sum + arr[j] > target){
            sum = arr[j];
            day++;
        }else{
            sum += arr[j];
        }
    }

    if(day <= days){
        return true;
    }

    return false;
}


int capacity(vector <int> &arr, int days){
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(), arr.end(),0);
    int answer = -1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(helper_function(arr, days,mid)){
            answer  = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return answer;
}



int main(){
    vector <int> arr ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    cout<<capacity(arr,days);
    return 0;
}

//--------------------------------
//finding the missing number from the sorted array 

#include<bits/stdc++.h>
using namespace std;

int Missing(vector <int> &arr, int k ){
    int low = 0;
    int high = arr.size() - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid  + 1);
        if(missing < k ){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return low + k;
    // return low + k
    // have been from the formula from the arr[high] + k + 1 or low + k
    //number + missing - k 
}


int main(){
    vector <int> arr = {3, 5, 7, 10};
    int k = 6;
    cout<<Missing(arr,k);
    return 0;
}


// page allocaion
//This is the optimal contiguous division.



// The aggressive cows

#include<bits/stdc++.h>
using namespace std;


int helper_function(vector <int> &arr, int target, int k){
    int n = arr.size();
    int cow = 1;
    int last_placed = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] - last_placed >= target){
            cow++;
            last_placed = arr[i];
        }
        if(cow >= k){
            return true;
        }
    }

    return false;
}


int Aggressive_cows(vector <int> &arr, int k ){
    int low = 1;
    int maxi = *max_element(arr.begin(),arr.end());
    int mini = *min_element(arr.begin(),arr.end());
    int high = maxi - mini;
    int ans = -1;
    sort(arr.begin(),arr.end());
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(helper_function(arr,mid,k)){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return ans;
}


int main(){
    vector <int>  arr = {10, 1, 2, 7, 5};
    int k = 3;
    cout<<Aggressive_cows(arr, k);
    return 0;
}
