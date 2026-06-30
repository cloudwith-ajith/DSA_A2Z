//counting the number in brute force method
#include<bits/stdc++.h>
using namespace std;
// normal method 
int main(){
    int arr[] = {1,2,3,4,1,1,1,1,3};
    int count = 0;
    int target = 1;
    for(int i =0;i < sizeof(arr)/sizeof(arr[0]);i++){
        if(arr[i] == target){
            count++;
        }
    }
    cout<<target<<"---->"<<count;
    return 0;
}
// Time complexity of the problem is O(n)

// using hash array 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,1,1,1,1,1,3};
    int hash[5] = {0};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i =0;i < n;i++){
        hash[arr[i]] = hash[arr[i]] + 1;
    }
    int target = 1;
    cout<<hash[target];
    return 0;
}

// TC os this is O(1) + O(n) as per the rule avoid the constant value --> O(n)

//hashing using the unordered map
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,1,1,1,1,5,6,7};
    unordered_map <int,int> mpp;
    for(int i = 0;i < sizeof(arr)/sizeof(arr[0]);i++){
        mpp[arr[i]]++;
    }
    int target = 1;
    cout<<mpp[target];
    return 0;
}

-----------------------------------------------------------------------------
// frequence in string hashing array
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "ajithkumar";
    int hash[26] ={0};
    for(int i = 0; i < s.length();i++){
       hash[s[i]-'a']++; 
    }
    char c = 'a';
    cout<<hash[c -'a'];
    return 0;
}
// same as the upper case  hash[s[i]-'A'] 
// TC of the code is O(n)

//all char
// 256 for all the char hash[s[i]] -->here the hash[] automatically convert into the index value
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "AjithKumar";
    int hash [256] = {0};
    for(int i = 0 ; i < s.length();i++){
        hash[s[i]]++;
    }
    char c = 'A';
    cout<<hash[c];
    return 0;
}

// using unordered mapp
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "AjithKumar";
    unordered_map <char,int> mpp;
    for(int i = 0 ; i < s.length();i++){
        mpp[s[i]]++;
    }
    char c = 'A';
    cout<<mpp[c];
    return 0;
}
//TC is O(1)
//min and max element in the array
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int arr[]= {1,2,3,4,5,5,5,5,6,7,7};
    map <int,int> mpp;
    
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]);i++){
        mpp[arr[i]]++;
    }
    
    //int target = 5;
    //cout<<mpp[target];
    int max = 0;
    int min = 1;
    for(auto x:mpp){
        if (x.second == min){
            cout<<x.first<<" ";
        }
    }cout<<endl;
    int maxx =0;
    for(auto x : mpp){
        if(max < x.second){
            max = x.second;
            maxx = x.first;
        }
    }
    cout<< maxx<< " ";
    return 0;
}

------------------------------------------------recursion--------------


 //fibonacci series   
#include<bits/stdc++.h>
using namespace std;


int fibo(int n){
    if (n <= 1){
        return n;
    }else{
        return fibo(n-2) + fibo(n-1);
    }
}


int main(){
    int n = 5;
    int a = fibo(n);
    cout<<a;
    return 0;
}



//pallindrome or not 

#include<bits/stdc++.h>
using namespace std;

bool pallindrome(string s, int i){
    if (i > s.length()/2){
        return true;
    }else{
        if(s[i] != s[s.length()-i-1]){
            return false;
        }
    return pallindrome(s,i+1);
    }
}


int main(){
    string s = "madem";
    if (pallindrome(s,0) == true){
        cout<<"its pallindrome";
    }else{
        cout<<"not a pallindrome";
    }
    return 0; 
}

// its tc is log n bcz its using the half checking



//reverse the array


#include<bits/stdc++.h>
using namespace std;

//recursion

int rev(int arr[],int start,int n){
    if(start > n/2 ){
        return 0;
    }else{
        swap(arr[start],arr[n-start-1]);
    }
    return rev(arr,start+1,n);
}



int main(){
    int arr[5] ={1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    for(auto x : arr ){
        cout<<x<<" ";
    }
    return 0;
}

//the tc is log n 
