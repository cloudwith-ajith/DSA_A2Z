#include <bits/stdc++.h>
using namespace std;

/* here the code is good but the
 cin strick with the whitespace so it only take the first part */

// int main(){
//     string str;
//     cout<<"enter the name:";
//     cin>>str;
//     cout<<"hi "<<str;
//     return 0;
// }

// The clear code is.. using the getline(cin,string)

int main(){
    string str;
    cout<<"enter the name ";
    getline(cin,str);
    cout<<"hi "<<str;
    return 0;
}
