/////pascal triangle

#include<bits/stdc++.h>
using namespace std;

int position(int n, int col){
    long long ans = 1;
    for(int i = 0; i < col; i++){
        ans = ans * (n-i);
        ans = ans / (i+1);
    }
    return ans;
}


int main(){
    int n = 5;
    int col = 3;
    int result = position(n-1,col-1);
    cout<<result;
    return 0;
}
