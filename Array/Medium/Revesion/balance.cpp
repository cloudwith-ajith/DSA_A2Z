//-----------------stock buy and sell

#include<bits/stdc++.h>
using namespace std;

int stock(vector<int> &arr){
    int n = arr.size();
    int max_pro = 0;
    for(int i =0; i < n-1; i++){
        int profit = 0;
        for(int j = i+1; j < n; j++){
            profit = arr[j] - arr[i];
            max_pro = max(profit,max_pro);
        }
    }

    return max_pro;
}


int main(){
    vector <int> arr = {7,1,5,3,6,4};
    int result  = stock(arr);
    cout<<result;
    return 0;
}

///----optimal code 

#include<bits/stdc++.h>
using namespace std;

int stock(vector<int> &arr){
    int n = arr.size();
    int max_pro = 0;
    int minn = INT_MAX;
    
    for(int i = 0; i < n; i++){
        if(arr[i] < minn){
            minn = arr[i];
        }else{
            max_pro = max(max_pro, arr[i] - minn);
        }
    }

    return max_pro;
}


int main(){
    vector <int> arr = {7,1,5,3,6,4};
    int result  = stock(arr);
    cout<<result;
    return 0;
}

// the time complexity of the code is O(n)
// the space complexity of the code is O(1)


//-----------------------------rearrange array element by the sign 
// optimal way

#include<bits/stdc++.h>
using namespace std;

void sign(vector<int> &arr){
    int n = arr.size();
    vector <int> temp_arr(n,0);
    int pos = 0; 
    int neg =1;
    for(int i = 0;i < n; i++){
        if(arr[i] > 0){
            temp_arr[pos]  = arr[i];
            pos = pos + 2;
        }else{
            temp_arr[neg] = arr[i];
            neg = neg +2;
        }
    }

    for(auto i : temp_arr){
        cout<<i<<" ";
    }
}

int main(){
    vector <int> arr = {1, 2, -4, -5};
    sign(arr);
    return 0;
}

// the time complexity of the code is O(n)
// the space complexity of the cod is O(n)



//-----------next permutation

#include<bits/stdc++.h>
using namespace std;

void np(vector<int> &arr){
    
    next_permutation(arr.begin(),arr.end());
    for(auto i :arr){
        cout<<i<<" ";
    }
}


int main(){
    vector <int> arr = {1,3,2};
    np(arr);
    return 0;
}

//---optimal way 

#include<bits/stdc++.h>
using namespace std;

void np(vector<int> &arr){
    
    int p = -1;
    int n = arr.size();

    for(int i  = n-2; i >= 0; i--){
        if(arr[i] < arr[i+1]){
            p = i;
            break;
        }
    }
    
    if(p == -1){
        reverse(arr.begin(),arr.end());
        for(auto i :arr){
        cout<<i<<" ";
    }
    }

    for(int i = n - 1; i >= 0; i--){
        if(arr[i] > arr[p]){
            swap(arr[i],arr[p]);
            break;
        }
    }

    reverse(arr.begin()+p+1,arr.end());


    for(auto i :arr){
        cout<<i<<" ";
    }
}


int main(){
    vector <int> arr = {1,3,2};
    np(arr);
    return 0;
}

///---------------leader 
#include<bits/stdc++.h>
using namespace std;

void leader(vector<int> &arr){
    int n = arr.size();
    vector <int> temp;

    for(int i = 0; i< n; i++){
        bool flag = true;
        for(int j = i + 1; j < n; j++){
            if(arr[i] <= arr[j]){
                flag = false;
            }
        }
        
        if(flag){
            temp.push_back(arr[i]);
        }
    }

    for(auto i : temp){
        cout<<i<<" ";
    }

}

int main(){
    vector <int> arr = {4, 7, 1, 0};
    leader(arr);
    return 0;
}

//--------optimal 


