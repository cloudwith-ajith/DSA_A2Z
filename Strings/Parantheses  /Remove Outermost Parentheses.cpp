#include<bits/stdc++.h>
using namespace std;

string Remove_Outermost_Parentheses(string s){
    int n = s.size();
    int opened = 0;
    string result = "";
    for(int i = 0 ; i < n; i ++){
        if(s[i] == '('){
            if(opened > 0){
                result += s[i];
            }
            opened++;
        }else{
            opened--;

            if(opened > 0){
                result += s[i];
            }
        }
    }

    return result;
}


int main(){
    string s = "((()))";
    cout<<Remove_Outermost_Parentheses(s);
    return 0;
}
