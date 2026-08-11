// best time to buy and sell the stock 

#include<bits/stdc++.h>
using namespace std;

int stock(int arr[],int n ){
    int profit = 0;
    for(int i = 0 ; i < n; i++){
        int t_p = 0;
        for(int j = i; j < n; j++){
            if(arr[j] > arr[i]){
                t_p = arr[j] - arr[i];
                profit = max(profit,t_p);
            }
        }
    }
    return profit;
}

int main(){
    int arr []  = {7,1,5,3,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res = stock(arr,n);
    cout<<res;
    return 0;
}

// the time complexity of the solution is O(2n)
// the space complexity of the solution is O(1)


//optimal way ----------------greedy algo 
#include<bits/stdc++.h>
using namespace std;

int stock(int arr[], int n){
    int max_element = 0;
    int min_element  = INT_MAX;
    //single loop 
    for(int i = 0 ; i < n; i++){
        if(arr[i] < min_element){
            min_element = arr[i];
        }
        max_element = max(max_element,arr[i] - min_element);
    }

    return max_element;

}



int main(){
    int arr[] = {7,1,5,3,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = stock(arr,n);
    cout<< result;
    return 0;
}
//the time complexity od the solution O(n)
//the space complexityof the solution O(1)
