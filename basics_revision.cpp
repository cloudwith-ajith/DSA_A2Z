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
//---------------minimum_heap------------------>priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap

#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> pq;
   //pushing the element  
    pq.emplace(10);
    pq.push(20);
    cout<<pq.top();
    // remove the first element like the queue
	pq.pop();
    cout<<pq.top();
    return 0;
}

//--------------------set,unordered_set,multiset---------------
//--------------------map,unordered_map,multimap---------------
// can iterate,unlike stack, queue, pq

//*******************************************************************************************************
//math

//count the digits
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 12345;
    int cnt = 0;
    while(n != 0){
        n =n / 10;
        cnt += 1;
    }
    cout<<cnt;
    return 0;
}


//reverse the digit --- rev = (rev * 10) + i

#include<bits/stdc++.h>
using namespace std;
int rev(int n){
    int rev = 0;
    while(n != 0){
        int i = n % 10;
        n = n/10;
        rev = (rev * 10) + i ;
    }
    return rev;
}
int main(){
    int n =12345;
    cout<<rev(n);
    return 0;
}

//palindrome

#include<bits/stdc++.h>
using namespace std;


void palindrome(int n){
    int rev = 0;
    while(n != 0){
        int i = n % 10;
        n = n/10;
        rev = (rev * 10) + i ;
    }
    if(rev == n) cout<< "palindrome";
    cout<< "not a palindrome";
}


int main(){
    int n =12345;
    palindrome(n);
    return 0;
}//---------prime
#include <iostream> // Better practice than <bits/stdc++.h>
using namespace std;

bool prm(int n) {
    if (n <= 1) return false; // Handles 0, 1, and negative numbers
    if (n == 2) return true;  // 2 is the only even prime number
    if (n % 2 == 0) return false; // Excludes all other even numbers

    // Loop only up to the square root of n (i * i <= n)
    // Step by 2 to skip checking even numbers
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    
    return true;
}

int main() {
    int n = 12;
    if (prm(n)) cout << "prime";
    else cout << "not a prime";
    return 0;
}

//------------------------pattern---------------------------------------
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    for(int i =0; i < 5;i++){
        for(int j = 0; j<5;j++){
            cout<<"* ";
        }cout<<endl;
    }
    
    return 0;
}

// * * * * * 
// * * * * * 
// * * * * * 
// * * * * * 
// * * * * * 

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    for(int i =0; i < 5;i++){
        for(int j = 0; j<=i;j++){
            cout<<"* ";
        }cout<<endl;
    }
    
    return 0;
}
// * 
// * * 
// * * * 
// * * * * 
// * * * * * 

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    for(int i =1; i <= 5;i++){
        for(int j = 1; j<=i;j++){
            cout<< j<<" ";
        }cout<<endl;
    }
    
    return 0;
}

// 1 
// 1 2 
// 1 2 3 
// 1 2 3 4 
// 1 2 3 4 5 

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    for(int i =5; i >= 1;i--){
        for(int j = 1; j<=i;j++){
            cout<<"* ";
        }cout<<endl;
    }
    
    return 0;
}

// * * * * * 
// * * * * 
// * * * 
// * * 
// * 

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    for(int i =5; i >= 1;i--){
        for(int j = 1; j<=i;j++){
            cout<<j<<" ";
        }cout<<endl;
    }
    
    return 0;
}

// 1 2 3 4 5 
// 1 2 3 4 
// 1 2 3 
// 1 2 
// 1 

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    for(int i = 1; i<5 ; i++){
        for(int j = 5; j>i;j--){
            cout<<"  ";
        }
        for(int k = 1; k <= ((i * 2)-1);k++){
            cout<<"* ";
        }cout<<endl;
    }
    
    return 0;
}
  //       * 
  //     * * * 
  //   * * * * * 
  // * * * * * * * 

#include<bits/stdc++.h>
using namespace std;

int main(){
    for(int i=5; i >= 1; i--){
        for(int k = 5 ; k >i;k--){
            cout<<" ";
        }
        for(int j =1; j<=((i*2)-1);j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}

// * * * * * * * * * 
//   * * * * * * * 
//     * * * * * 
//       * * * 
//         * 


#include<bits/stdc++.h>
using namespace std;

int main(){
    for(int i = 0; i < 5; i++){
        for(char j = 'A' ; j <= 'A'+i; j++){
            
            cout<<j<<" ";
        }cout<<endl;
    }
    return 0;
}
// A 
// A B 
// A B C 
// A B C D 
// A B C D E 

#include<bits/stdc++.h>
using namespace std;

int main(){
    char ch = 'A';
    for(int i = 0; i < 5; i++){
        for(char j = 'A' ; j <= 'A'+i; j++){
            
            cout<<ch<<" ";
        }cout<<endl;
        
        ch++;
    }
    return 0;
}
// A 
// B B 
// C C C 
// D D D D 
// E E E E E 




#include<bits/stdc++.h>
using namespace std;

int main(){
    int cnt = 1;
    for(int i = 0; i < 5; i++){
        for(int j = 0 ; j <= i;j++){
            cout<<cnt<<" ";
            cnt++;
        }cout<<endl;
    }
    return 0;
}

// 1 
// 2 3 
// 4 5 6 
// 7 8 9 10 
// 11 12 13 14 15

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n = 5;

    for(int i = 1; i <= n; i++){
        if(i == 1 || i ==n ){
            for(int j = 1; j <= n; j++){
                cout<<"* ";
            }
        }else{
            for(int k = 1; k <= n;k++){
                if(k == 1|| k == n){
                    cout<<"* ";
                }else{
                    cout<<"  ";
                }
            }
        }
        cout<<endl;
    }


    return 0;
}


// * * * * * 
// *       * 
// *       * 
// *       * 
// * * * * * 


//optimized way

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to print hollow square pattern
    void pattern21(int n) {
        // Outer loop for rows
        for (int i = 0; i < n; i++) {
            // Inner loop for columns
            for (int j = 0; j < n; j++) {
                // Print star if it's a border cell
                if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
                    cout << "*";
                // Print space otherwise
                else
                    cout << " ";
            }
            // Move to next line after each row
            cout << endl;
        }
    }
};

int main() {
    // Create solution object
    Solution sol;
    // Define N
    int N = 5;
    // Call pattern function
    sol.pattern21(N);
    return 0;
}

-----------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n =4;
    for(int i = 0; i < (2 *n)-1;i++ ){
        for(int j = 0; j < (2*n)-1;j++){
            int top = i;
            int left = j;
            int right = (2*n-2)-j;
            int down = (2*n-2) - i;

            cout<<(n-min(min(top,down),min(right,left)))<<" ";
        }cout<<endl;
    }


    return 0;
}


// 4 4 4 4 4 4 4 
// 4 3 3 3 3 3 4 
// 4 3 2 2 2 3 4 
// 4 3 2 1 2 3 4 
// 4 3 2 2 2 3 4 
// 4 3 3 3 3 3 4 
// 4 4 4 4 4 4 4 

