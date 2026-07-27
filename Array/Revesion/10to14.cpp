//Find the missing numbers
#include<bits/stdc++.h>
using namespace std;

int missing_number(int arr[],int n){
    for(int i = 1; i <= n+1; i ++){
        int flag = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == i){
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[] = {8, 2, 4, 5, 3, 7, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = missing_number(arr,n);
    cout<<result;
    return 0;
}
// THH TIME COMPLEXITY OF THE CODE IS O(N*2)
// THE SPACE COMPLEXITY OF THE CODE IS O(1)

//----------------------hashing
// TC O(N)
// SC O(N)
#include<bits/stdc++.h>
using namespace std;

int missing_number(int arr[],int n ){
    vector <int> temp(n+2);
    
    for(int i = 0; i < n; i++){
        temp[arr[i]]++;
    }
    
    for(int j = 1; j <= n+1; j++){
        if(temp[j] == 0){
            return j;
        }
    }
    
    return -1;
}

int main(){
    int arr[] = {8, 2, 4, 5, 3, 7, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = missing_number(arr,n);
    cout<<result;
    return 0;
}

//----------------OPTIMAL 1
///----------------------------sum of natural numbers
//-------------------n(n+1) / 2
//----------TC O(N)
//-----------SP O(1)


#include<bits/stdc++.h>
using namespace std;

int missing_number(int arr[],int n ){
    int total_sum = ((n+1)* ((n+1) + 1)) / 2;
    int sum  = 0;
    for(int i = 0; i < n; i++){
        sum = sum + arr[i];
    }
    
    int missing =  total_sum - sum;
    return missing;
}

int main(){
    int arr[] = {8, 2, 4, 5, 3, 7, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = missing_number(arr,n);
    cout<<result;
    return 0;
}
//-------------The optimal way to find the missing number
// TC O(n)
// sp O(1)
#include<bits/stdc++.h>
using namespace std;

int missing_number(int arr[],int n ){
    //using XOR
    int xor1 = 0;
    int xor2 = 0;
    for(int i = 0; i < n; i++){
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i +1);
    }
    xor1 = xor1 ^ (n+1);
    int miss = xor1 ^ xor2;
    return miss;
}

int main(){
    int arr[] = {8, 2, 4, 5, 3, 7, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = missing_number(arr,n);
    cout<<result;
    return 0;
}

//-------------count the maximum ones in the array
// optimal  TC----> O(n)
// SC ----> o(1)


#include<bits/stdc++.h>
using namespace std;

int count_max_ones(int arr[],int n){
    int max_count = 0;
    int count = 0;
    
    for(int i = 0 ; i < n; i++){
        if(arr[i] == 1){
            count = count + 1;
            max_count = max(max_count,count);
        }else{
            count = 0;
        }
    }
    
    return max_count;
}


int main(){
    int arr[] = {1,1,0,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = count_max_ones(arr,n);
    cout<<result;
    return 0;
}

//--------------------------find the number one occurence 
//-------------------------Tc O(n*@)
//-------------------------SC O(1)

#include<bits/stdc++.h>
using namespace std;

int find_number_once(int arr[],int n){
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == arr[i]){
                count++;
            }
        }
        
        if(count == 1){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {4,1,2,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = find_number_once(arr,n);
    cout<<result;
    return 0;
}

///------using hashing (better method)
#include<bits/stdc++.h>
using namespace std;

int find_number_once(int arr[],int n){
    unordered_map <int ,int > mpp;
    
    for(int i = 0 ; i < n; i ++){
        mpp[arr[i]]++;
    }
    
    for(int j = 0; j < n; j++){
        if(mpp[arr[j]] == 1){
            return arr[j];
        }
    }
    return -1;
}

int main(){
    int arr[] = {4,1,2,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = find_number_once(arr,n);
    cout<<result;
    return 0;
}

//---TC O(N)
//---SC O(N)
