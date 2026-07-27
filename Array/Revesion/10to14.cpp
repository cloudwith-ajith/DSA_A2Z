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
