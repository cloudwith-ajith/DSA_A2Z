//permutation algo
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s =  "gcd";
    do{
        cout<<s<<" ";
    }while(next_permutation(s.begin(),s.end()));
    return 0;
}

//max_element algo
#include<bits/stdc++.h>
using namespace std;
int main(){
    auto s ={1,2,3,4,5,6};
    int maxi = *max_element(s.begin(),s.end());
    cout<< maxi;
    return 0;
}
