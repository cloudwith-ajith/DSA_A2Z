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
