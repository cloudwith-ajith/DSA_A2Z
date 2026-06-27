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

// cout character using hashing

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











