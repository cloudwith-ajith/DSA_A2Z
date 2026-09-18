
#include<bits/stdc++.h>
using namespace std;

int CountReverse(vector <int> &arr){
    int n = arr.size();
    int counter = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > (2 * arr[j])){
                counter++;
            }
        }
    }
    return counter;
}
int main(){
    vector <int> arr = {4, 1, 2};
    int result = CountReverse(arr);
    cout<<result;
    return 0;
}
