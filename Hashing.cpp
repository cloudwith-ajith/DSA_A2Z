// Number Hashing 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,2,2,1,10,4,5,5,5};
    int hash[11]={0};
    //prestoring
    for(int i =0;i <sizeof(arr)/sizeof(arr[0]);i++){
        hash[arr[i]] = hash[arr[i]] + 1;
    }
    
    int  fetch =5;
    cout<<hash[fetch]<<" "<< "is the count";
    return 0;
}  

// char and ascii relation
#include<bits/stdc++.h>
using namespace std;

int main(){
    //The lowercase letter 'a' has a decimal ASCII value of 97
    char a = 'a';
    //Lowercase 'b': 98 (Decimal)
    char b = 'b';
    // 97 - 98 = -1;
    cout<<a-b;
    return 0;
}




//count character present in the string using brute force methoed

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s  = "madam";
    int count = 0;
    char target = 'm';
    for(int i =0; i < s.length();i++){
        if(s[i]==target){
            count += 1;
        }
    }
    cout<<count;
    return 0;
}

// cout character using hashing for small letter

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "madam";
    int hash[26] = {0};
    //pre process
    for(int i = 0; i < s.length();i++){
            //ascii value for m -->109 - 97 = 12
            //in hash array index 12 goin to increase by one 
        hash[s[i]-'a'] += 1;
    }
    //fetch
    char target = 'm';
    cout<<hash[target-'a'];
    
    return 0;
}

//counting the char using hashing for the uppercase 
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "MADAM";
    int hash[26] = {0};
    //pre process
    for(int i = 0; i < s.length();i++){
        hash[s[i]-'A'] += 1;
    }
    //fetch
    char target = 'M';
    cout<<hash[target-'A'];
    
    return 0;
}

// 256 character 
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "Madam,this is ajith ";
    int hash[256] = {0};
    //pre process
    for(int i = 0; i < s.length();i++){
        hash[s[i]] += 1;
    }
    //fetch
    char target = ',';
    cout<<hash[target];
    
    return 0;
}

//couting the number in the array using the hashing with map data structure 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] ={1,2,2,4,6,1};
    map <int,int> mpp;
    //pre process
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0])+1;i++ ){
        // just create the key and store the value
        mpp[arr[i]] = mpp[arr[i]] + 1;
    }
    //fetch
    int num = 6;
    cout<<mpp[num];
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "madam";
    map <char,int> mpp;
    
    //pre process
    for(int i = 0;i < s.size();i ++){
        mpp[s[i]] += 1;
    }
    
    //fetch 
    char target = 'm';
    cout<<mpp[target];
    return 0;
    
}

//unordered map ------using this is the best for time complexity ,o(1)
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "madam";
    unordered_map <char,int> mpp;
    
    //pre process
    for(int i = 0;i < s.size();i ++){
        mpp[s[i]] += 1;
    }
    
    //fetch 
    char target = 'm';
    cout<<mpp[target];
    return 0;
    
}


//hashing problem statement 2

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] ={1,2,2,4,4,4,6,1,5,5,1,1,1,1,1,1};
    map <int,int> mpp;
    //pre process
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]);i++ ){
        // just create the key and store the value
        mpp[arr[i]] = mpp[arr[i]] + 1;
    }
    //fetch
    //int num = 6;
    //cout<<mpp[num];
    
    int maxx = 0;
    int max_second = 0;
    for(auto y : mpp){
        if(y.second>max_second){
            max_second =  y.second ;
            maxx = y.first;
        }
    }
    cout<<maxx<<" ";
    
    int mini = 1;
    for(auto x : mpp){
        if(x.second == mini){
            cout<<x.first<<" ";
        }
    }
    return 0;
}

// hashing work in three differnt way 
// division method 
// mid square method
// folding methoed















