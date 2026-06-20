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

//sorting sort(a,a+n),sort(a.begin,a.end()),sort(a.begin,a.end(),greater<int>())
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v = {6,4,1,8,2,10};
    sort(v.begin(),v.end(),greater<int>());
    for(auto it : v){
        cout<<it<<" ";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v = {6,4,1,8,2,10};
    sort(v.begin(),v.end();
    for(auto it : v){
        cout<<it<<" ";
    }
    return 0;
}

//bool comp() --> creating the own way to sort

#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a,pair<int,int> b){
    if (a.second < b.second){
        return true;
    }
    if (a.second > b.second){
        return false;
    }
    if (a.first>b.first){
        return true;
    }else{
        return false;
    }
}

int main(){
    pair<int,int> arr[] = {{1,2},{3,1},{4,1}};
    sort(begin(arr), end(arr), comp);
    for(auto it : arr){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}
