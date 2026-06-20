// #include<bits/stdc++.h>
// using namespace std;

// int printnumber(int x){
//     cout<< x;
//     return x;
// }

// int main(){
//     int x;
//     cin >> x;
//     printnumber(x);
//     return 0;
// }

// adult or not
#include<bits/stdc++.h>
using namespace std;

int main(){
    int age;
    cout<<"Enter the age: ";
    cin>>age;
    if (age >= 18){
        cout<<"adult"; 
    }else{
        cout<<"not adult ";
    }
    return 0;
}