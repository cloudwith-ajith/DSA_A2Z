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
