#include<bits/stdc++.h>
using namespace std;


int count_substring(string s){
    int n = s.length();
    int vaild_count  = 0;

    for(int i = 0 ; i < n; i++){
        for(int j = i; j < n; j++){
            // this is bcuz of the a to j char in the problem
            int arr[10] = {0};

            for(int k = i; k <= j; k++){
                arr[s[k] - 'a']++;
            }

            int odd_cout = 0;
            for( auto m : arr){
                if(m % 2 == 1){
                    odd_cout++;
                }
            }

            if(odd_cout <= 1){
                vaild_count++;
            }
        }
    }

    return vaild_count;
} 

int main(){
    string s = "aabb";
    cout<<count_substring(s);
    return 0;
}
