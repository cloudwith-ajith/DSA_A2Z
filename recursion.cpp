//what is mean by recursion 
//"When a function calls itself","until a specified condition"
#include<bits/stdc++.h>
using namespace std;

void print(){
    cout<<3<<endl;
    print();
}

int main(){
    print();
    return 0;
}

//recursion with base case condition 

#include<bits/stdc++.h>
using namespace std;
int cmt = 0;
void print(){
    if (cmt == 4){
        return;
    }else{
        cout<<cmt<<endl;
        cmt++;
        print();
    }
}

int main(){
    int cmt = 0;
    print();
    return 0;
}

//Print Name N times using Recursion

#include<bits/stdc++.h>
using namespace std;

int cmt = 0 ;
void print(int n,string name){
    if(cmt==n){
        return;
    }else{
        cout<<name<<" ";
        cmt++;
        print(n,name);
    }
}

int main(){
    string  name;
    cin>>name;
    int n;
    cin>>n;
    print(n,name);
    return 0;
}

// 1 to N
#include<bits/stdc++.h>
using namespace std;

int cmt = 1 ;
void print(int n){
    if(cmt==n+1){
        return;
    }else{
        cout<<cmt<<" ";
        cmt++;
        print(n);
    }
}

int main(){
    int n;
    cin>>n;
    print(n);
    return 0;
}

//better version 
#include <iostream>
using namespace std;

// No global variables
void print(int cmt, int n) {
    if (cmt > n) { // Base Case: Stop when counter exceeds N
        return;
    }
    cout << cmt << " ";
    print(cmt + 1, n); // Move to the next number
}

int main() {
    int n;
    cin >> n;
    print(1, n); // Start tracking from 1
    return 0;
}

// n to 1 backtracking
#include<bits/stdc++.h>
using namespace std;
//4 -->1
void print(int i,int n){
    if(i>n){
        return;
    }else{
        print(i+1,n);
        cout<<i;
    }
} 


int main(){
    int n;
    cin>>n;
    print(1,n);
    return 0;
}


// sum of the n numbers 
]#include<bits/stdc++.h>
using namespace std;

void sum_n(int n,int s,int cmt){
    if(cmt==n+1){
        cout<<s;
        return;
    }else{
        s = s + cmt;
        cmt++;
        sum_n(n,s,cmt);
    }
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int cmt =1;
    int s = 0;
    sum_n(n,s,cmt);
    return 0;
}

//factorial number using the recursion
#include<bits/stdc++.h>
using namespace std;

void factorial(int num,int s){
    if(num==0){
        cout<<s;
        return;
    }else{
        s = s * num;
        num--;
        factorial(num,s);
    }
    
}


int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    factorial(num,1);
    return 0;
}
//best version for the above code 

#include <bits/stdc++.h>
using namespace std;

// Recursive function to calculate factorial of a number
int factorial(int n) {
    // Base case: factorial of 0 is 1
    if (n == 0) {
        return 1;
    }

    // Recursive case: n * factorial of (n-1)
    return n * factorial(n - 1);
}

int main() {
    // Define the number to compute factorial
    int n = 3;

    // Call the factorial function and print the result
    cout << factorial(n) << endl;

    return 0;
}


//factorial using the functional method 

#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n == 1){
        return 1;
    }else{
        return n * factorial(n-1);
    }
}


int main(){
    int n;
    cin>>n;
    cout<<factorial(n);
    return 0;
} 




//sum of n numbers using the functional recursion 

#include<bits/stdc++.h>
using namespace std;

int sum_n(int n){
    if(n == 0){
        return 0;
    }else{
        return n+sum_n(n-1);
    }
}


int main(){
    int n;
    cin>>n;
    cout<<sum_n(n);
    return 0;
}

//using recursion


#include<bits/stdc++.h>
using namespace std;

void rev(int i,int arr[]){
    if(i < 0){
        return;
    }else{
        cout<<arr[i]<<" ";
        rev(i-1,arr);
    }
}

int main(){
    int arr[]={1,2,3,4,5};
    int i = sizeof(arr)/sizeof(arr[0]);
    rev(i-1,arr);
    return 0;
}


///using in built funcion
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5};
    int len = sizeof(arr)/sizeof(arr[0]);
    
    reverse(arr,arr+len);
    
    for(int x : arr){
        cout<<x;
    }
    return 0;
}

//brut 
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector <int> rev;
    int arr[]={10,20,30,40};
    int len  = (sizeof(arr)/sizeof(arr[0]));
    for(int i = len-1; i>=0;i--){
        rev.emplace_back(arr[i]);
    }
    for(auto it : rev){
        cout<<it<<" ";
    }
    return 0;
}


// reverse using two pointers
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5};

    int len = sizeof(arr)/sizeof(arr[0]) - 1;
    for(int i = 0; i < len; i++ ){
        swap(arr[i],arr[len]);
        len--;
    }
    for(int x : arr){
        cout<<x<<" ";
    }
    return 0;
}

//reverse in recursion

#include<bits/stdc++.h>
using namespace std;

void rev(int arr[],int start,int end){
    if(start == end){
        return;
    }else{
        swap(arr[start],arr[end]);
        rev(arr,start+1,end-1);
    }
}

int main(){
    int arr[]={1,2,3,4,5};
    int end = sizeof(arr)/sizeof(arr[0])-1;
    rev(arr,0,end);
    for(int x:arr){
        cout<<x<<" ";
    }
}

//fuctional recursion 
#include<bits/stdc++.h>
using namespace std;

void rev(int arr[],int i,int n){
    if(i >= n/2){
        return;
    }else{
        swap(arr[i],arr[n-i-1]);
        rev(arr,i+1,n);
    }
}

int main(){
    int arr[]={1,2,3,4,5};
    int end = sizeof(arr)/sizeof(arr[0]);
    rev(arr,0,end);
    for(int x:arr){
        cout<<x<<" ";
    }
}


//Palindrome brute force method
#include<bits/stdc++.h>
using namespace std;

int main(){
    string name = "madam";
    string rev ;
    for(int i = name.length()-1;i>=0;i--){
        rev = rev +name[i];
    }
    if(rev==name){
     cout<<"Palindrome";   
    }else{
        cout<<"Not Palindrome";
    }
    return 0;
}

//recursion
#include<bits/stdc++.h>
using namespace std;

bool palindrome(string& s,int start){
    if(start >= s.length()/2) return true;
    
    if (s[start] != s[s.length()-start-1]) return false;
    
    return palindrome(s, start +1);
}


int main(){
    string s ="madam";
    bool ans =palindrome(s,0);
    if (ans == true){
        cout<<"palindrome";
    }else{
        cout<<"Not palindrome";
    }
}

//my way palindrome
#include<bits/stdc++.h>
using namespace std;

bool pali(string name){
    int end = name.length()-1;
    for(int i =0; i < end;i++){
        if (name[i] != name[end]){
            return false;
            break;
        }else{
            end--;
        }
    }return true;
}

int main(){
    string name = "madvbam";

    if(pali (name)== true){
        cout<<"pali";
    }else{
        cout<<"no pali";
    }
    return 0;
}
///fibonacci, my way
#include<bits/stdc++.h>
using namespace std;

void factorial(int n){
    int a = 0;
    int b = 1;
    cout<<a<<" "<<b<<" ";
    for(int i = 2; i <=n ; i++){
        int c = a + b;
        cout<<c<<" ";
        a = b;
        b = c;
    }
}


int main(){
    int n;
    cout<<"enter the number: ";
    cin>>n;
    factorial(n);
    return 0;
}

//brute force method
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 6;

    // Edge case: if n is 0, print only 0
    if (n == 0) {
        cout << 0;
    }
    // Special case: if n is 1, print first two Fibonacci numbers
    else if (n == 1) {
        cout << 0 << " " << 1 << "\n";
    }
    // General case: generate and print Fibonacci series up to nth term
    else {
        int fib[n + 1];    // Array to store Fibonacci numbers up to index n
        fib[0] = 0;
        fib[1] = 1;

        // Fill the Fibonacci series using bottom-up dynamic programming
        for (int i = 2; i <= n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }

        cout << "The Fibonacci Series up to " << n << "th term:" << endl;
        for (int i = 0; i <= n; i++) {
            cout << fib[i] << " ";
        }
    }

    return 0;
}


