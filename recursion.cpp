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
