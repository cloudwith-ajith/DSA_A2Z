
// problem -1
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int m;
//     cin>>m;

//     if (m >= 80 && m <= 100){
//         cout<<"A";
//     }else if(m >= 60 && m <= 79){
//         cout<<"B";
//     }else if(m >= 50 && m <= 59){
//         cout<<"C";
//     }else if(m >= 45 && m <= 49){
//         cout<<"D";
//     }else if(m >=25  && m <=44 ){
//         cout<<"E";
//     }else{
//         cout<<"F";
//     }
//     return 0;
// }

//problem - 2

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     string a ="ajith";
//     // cout<<a.length();
//     int len = a.size(); 
//     cout <<len;
//     return 0 ;
// }




// length
// int main(){
//     string a = "ajith";
//     int len = a.size();
//     a[len-1] = 'a';
//     cout<<a;
//     return 0;
// }









#include<bits/stdc++.h>
using namespace std;

int main(){
    for(int i = 0;i < 4; i=i+1){
        for (int j = 0; j <=i; j= j+1 ){
            cout<<"*";
        }cout << endl;

    }
    return 0 ;
}