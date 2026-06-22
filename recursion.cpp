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
