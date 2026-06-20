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
//min_element(a,a+n)
#include<bits/stdc++.h>
using namespace std;
int main(){
    auto s ={1,2,3,4,5,6};
    int maxi = *min_element(s.begin(),s.end());
    cout<< maxi;
    return 0;
}

//__builtin_popcount() return the how many 1's in the binary number

#include<bits/stdc++.h>
using namespace std;

int main(){
    int num =9;
    int n = __builtin_popcount(num);
    cout << n;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long  num =5678;
    int n = __builtin_popcountll(num);
    cout << n;
    return 0;
}
