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

//vector
#include<bits/stdc++.h>
using namespace std;

int main(){
    //decalartion
    vector<int> a;
    vector<pair<int,int>> b;
    vector<int>c(5,100);
    vector<int>d(5);
    //pushing the element to the vector
    a.push_back(3);
    a.push_back(10);
    a.emplace_back(2);
    for(auto it : a){
        cout<<it<<endl;
    }
    b.push_back({1,2});
    b.emplace_back(3,4);
    //iteration in the vector
    for(auto it : b){
        cout<<it.first<<" "<<it.second;
        cout<<endl;
    }
    for(auto it : c){
        cout<<it<<endl;
    }
    for(auto it : d){
        cout<<it<<endl;
    }
    auto x = a[1];
    auto y = a.begin();
    auto z = a.end();
    z--;
    //here the .begin() and .end() function used to collect the memory address of the particular value,so we need to use the itertor with * function
    cout<<x<<" "<<*(y)<<" "<<*(z)<<endl ;
    //delection --> erase()
    a.erase(a.begin());
    for(auto it : a){
        cout<<it<<endl;
    }
    //insertion
    a.insert(a.begin(),3);
    //we can also insert in particular position a.begin()+1,a.insert(position,number of count,value) --> a.insert(begin(a),2,4)-->{4,4,3,10,2}
    a.insert(begin(a),2,4);
    for(auto it : a){
        cout<<it<<endl;
    }
    int r =size(a);
    cout<<r;
    a.pop_back();//delect the last element
    // a.swap(b);//swap the vector value
    a.clear();//clear the element present in the vector
    cout<<a.empty();//return the true if the element present in the vector else false
    return 0;
}

//list<>

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    list<int>l1;
    l1.push_back(1);
    l1.emplace_back(2);
    l1.push_front(0);
    l1.emplace_front(11);
    for(auto it : l1){
        cout<<it<<endl;
    }
    l1.pop_back();
     for(auto it : l1){
        cout<<it<<endl;
    }
    int c = l1.front();
    int c1 = l1.back();
    cout<<c<<" "<<c1;
    
    return 0;
}

//deque

#include<bits/stdc++.h>
using namespace std;
int main(){
    deque<int> dq;
    dq.push_back(10);
    dq.emplace_back(20);
    dq.push_front(2);
    dq.emplace_front(1);
    for(auto it : dq){
        cout<< it <<endl;
    }
    int a = dq.front();
    int b = dq.back();
    cout<<"the front is :"<<a<<endl<<"the last element in the dq is:"<<b<<endl;
    dq.pop_back();
    dq.pop_front();
    int s  = dq.size();
    cout<<s;
    return 0;
    
}

//stack

#include<bits/stdc++.h>
using namespace std;
// stack --> push,pop,top
int main(){
    stack <int> sk;
    sk.push(20);
    sk.push(10);
    sk.push(5);
    cout<<sk.top()<<endl;;
    sk.pop();
    cout<<sk.top();
    
    // we cannot iterate the stack, but in the workaround
    //using pop and top
    //while(!sk.empty())
    while(sk.empty() == false){
        cout<<sk.top()<<endl;
        sk.pop();
    }
    
    return 0;
}

//queue

#include<bits/stdc++.h>
using namespace std;
//queue
int main(){
    queue <int> q;
    q.push(1);
    q.push(10);
    q.push(20);
    //cout<<q.front()<<" "<<q.back()<<endl;;
    q.pop();
    //cout<<q.front()<<endl;
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}
//pq priority_queue

#include<bits/stdc++.h>
using namespace std;

int main(){
    //maximum heap
    priority_queue<int> pq;
    pq.push(10);
    pq.emplace(1);
    cout<<pq.top();
    //minimum heap 
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(10);
    pq.emplace(1);
    cout<<pq.top();
    return 0;
}
