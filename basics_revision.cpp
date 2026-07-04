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


//factorial

#include<bits/stdc++.h>
using namespace std;

int fac(int n){
    if(n == 0){
        return 1;
    }else{
        return (n * fac(n-1));
    }
}


int main(){
    int n = 3;
    cout<<fac(n);
    return 0;
}
//sum of the n numbes
#include<bits/stdc++.h>
using namespace std;

int fac(int n){
    if(n == 0){
        return 0;
    }else{
        return (n + fac(n-1));
    }
}


int main(){
    int n = 5;
    cout<<fac(n);
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

void print(int i){
    if (i < 1 ){
        return ;
    }else{
        cout<<i<<" ";
        print(i-1);
    }
}

int main(){
    int n = 5;
    print(n);
    return 0;
}
// 1 to namespace
#include<bits/stdc++.h>
using namespace std;

void print(int start,int n ){
    if(start > n){
        return;
    }else{
        cout<<start<<" ";
    }
    print(start+1,n);
}

int main(){
    int n = 5;
    print(1,n);
    return 0;
}

/// printing the name n times 
#include<bits/stdc++.h>
using namespace std;

void print(int start,string s,int e ){
    if(start >e ){
        return;
    }else{
        cout<<s<<" ";
    }
    print(start+1,s,e);
}

int main(){
    string n = "ajith";
    int e = 3; 
    print(1,n,e );
    return 0;
}

//backtracking n to 1
#include<bits/stdc++.h>
using namespace std;

//backtracking
void print(int n,int start){
    if (start > n){
        return;
    }else{
        print(n,start+1);
        cout<<start<<" ";
    }
}




int main(){
    int n = 5;
    print(n,1);
    return 0;
}

---------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n1 = 9;
    int n2 = 12;
    int n = 0;
    if (n1 ==0 || n2 == 0){
        cout<<" 0";
        return 0;
    }
    // min value
    if(n1>n2){
        n = n2;
    }else{
        n =n1;
    }
    
    for (int i = n; i >= 1; i--){
        if(n1 % i == 0 && n2 % i == 0){
            cout<<i<<" ";
            break;
        }
    }
    
    return 0;
}
----------------------------------------------------------------------------------
multiple value  
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n = 36;
    set <int> v ;
    int sq = sqrt(n);
    
    for(int i = 1; i <=sq;i++){
        if(sq % i ==0){
            v.emplace(i);
            if(n/i != i){
                v.emplace(n/i);
            }
        }
    }
    
    for(auto i : v){
        cout<< i<<" ";
    }
    
    return 0;
}

-----------------------stl--------------------------
    #include<bits/stdc++.h>
using namespace std;

int main(){
    pair <int,int> p1 = {'a',1};
  
    cout<<p1.first<<" "<<p1.second; 
    
    return 0;
}

int main(){
    pair <int,pair<char,string>> p1 ={1,{'a',"ajith"}};
    // to acess the second value it has the two value, so we use the second.first/second
    cout<<p1.second.second;
    
    pair <string,int> arr[3] = {{"ajith",1},{"mahi",7},{"boomi",27}};
    for(auto i : arr){
        cout<<i.first<<" "<<i.second;
    }
    return 0;
}




/////////////////////////////////////////vector----------------------------------

#include<bits/stdc++.h>
using namespace std;


int main(){
    ////which id going to  create the 5 space first  and the value whic is return in the space
    //// vector <int> v(5,28);
    ////using the for loop 
    for(auto i : v){
        cout<<i<<" "; 
    }
    
    vector <int> v(5,28);
    //using the iterator
    for(auto i = v.begin();i != v.end();i++){
        cout<<*(i)<<" "; 
    }
    
    return 0;
}

//////////////////////////////////erase---------------------------------
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    vector <int> v;
    
    for(int i  = 1; i <= 10;i++){
        v.emplace_back(i);
    }
    cout<<endl;
    
    
    v.erase(v.begin(),v.begin()+2);
    
    for(auto i = v.begin();i != v.end();i++){
        cout<<*(i)<<" ";
    }
    
    //delect the element using the erase
    
    return 0;
}


////////////insert---------------------------------


#include<bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> v(5,10);
    
    //v.insert(v.begin()+1,9);
    v.insert(v.begin()+1,9,1);
    
    for(auto c :v){
        cout<<c<<" ";
    }
    
    return 0;
}

//////////////list ---- everything is simillar
//but here we can also do the front operation insert-----

#include <iostream>
#include <list>
#include <iterator> // Required for std::next

using namespace std;

int main() {
    list<int> lst = {10, 30, 40, 34, 56, 7, 8, 9};

    // 1. Choose your exact target position index
    int position = 3; 

    // 2. Move the iterator to that exact position
    auto it = std::next(lst.begin(), position);

    // 3. Insert 88 right there
    lst.insert(it, 88);

    // 4. Print the final list
    for (int x : lst) {
        cout << x << " ";
    }
    // Output: 10 30 40 88 34 56 7 8 9
    // Index positions now:
    // 10(0), 30(1), 40(2), 88(3), 34(4)...

    return 0;
}

//////////stack
#include <bits/stdc++.h>
using namespace std;



int main() {
	std::stack<int> stk ;
	stk.push(1);
	stk.push(2);
	cout<<stk.top();
	stk.pop();
	cout<<stk.top();
	return 0;

}

//---------queue-------------------------------
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    queue <int> q ;
    
    q.emplace(2);
    q.push(1);
    cout<<q.front();
    q.pop();
    cout<<q.front();
    
    return  0;
}
--------------//queue cant be iterate, but using this things may-----------
#include<bits/stdc++.h>
using namespace std;

void printqueue(queue<int>qc){
    while(!qc.empty()){
        cout<<qc.front()<<" ";
        qc.pop();
    }
}



int main(){
    queue <int> q ;
    q.push(1);
    q.emplace(2);
    q.push(11);
   // if you need to iterate
    printqueue(q);
    return 0;
    
}

//------------------priority queue-------
//  -------------default------------------priority_queue<int> maxHeap; // Max-heap



