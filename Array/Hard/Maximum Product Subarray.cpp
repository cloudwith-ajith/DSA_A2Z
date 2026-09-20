// breute force method 

#include<bits/stdc++.h>
using namespace std;

int maxproductt(vector <int> &arr){
    int n = arr.size();
    int maxpro = INT_MIN;
    for(int i = 0; i < n; i++){
        int temp = arr[i];
        for(int j = i + 1; j < n; j++){
            temp = temp * arr[j];
            maxpro = max(maxpro, temp);
        }
    }
    return maxpro;
}

int main(){
    vector <int> arr ={2,3,-2,4};
    int result = maxproductt(arr);
    cout<<result;
    return 0;
}

// The Time complexity of the code is O(n^2)
// The Space complexity of the code is O(1)
//--------------------------------------------------------------------------
// The optimal solution 

#include<bits/stdc++.h>
using namespace std;

int MaxProds(vector <int> &arr){
    int n = arr.size();
    int maxprod = INT_MIN;
    int prefix = 1;
    int sufix = 1;
    for(int i = 0; i < n; i++){
        if(prefix == 0) prefix = 1;
        if(sufix == 0) sufix = 1;

        prefix = prefix * arr[i];
        sufix  = sufix * arr[n - i -1];

        maxprod = max(maxprod,max(prefix,sufix));
    }

    return maxprod;
}

int main(){
    vector <int> arr = {2,3,-2,4};
    int result = MaxProds(arr);
    cout<<result;
    return 0;
}

// The Time complexity of the code is O(n)
// The Space complexity of the code is O(1)

// The intution is 
// 1. Every element is the array is positive then product of all the array element is the max product value
// 2. Even number of the negative numbers in the array also same as the condition one 
// 3. IF the negative number present odd time then the prefix or suffix of the negataive is the max prod
// 4. If it contain zero then need to set the prefix and suffix as the defaul number one




