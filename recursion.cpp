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
