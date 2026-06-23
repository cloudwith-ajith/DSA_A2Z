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
