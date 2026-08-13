//----------------brute force method 
#include<bits/stdc++.h>
using namespace std;


//helper function 
bool liner_function(vector<int>arr,int num){
    for(int i : arr){
        if(num == i){
            return true;
        }
    }
    return false;
}



int consective(vector <int>arr){
    int n  = arr.size();
    int max_counter = 0;
    for(int i = 0; i < n; i++){
        int num = arr[i];
        int counter = 1;
        while(liner_function(arr,num+1) == true){
            counter = counter + 1;
            num = num + 1;
        }
        max_counter = max(max_counter,counter);
    }
    return max_counter;
}


int main(){
    vector <int> arr = {100, 4, 200, 1, 3, 2};
    int result = consective(arr);
    cout<<result; 
    return 0;
}

//-----------------better method 



#include<bits/stdc++.h>
using namespace std;

int consecutive(vector <int>& arr){ // Passed by reference to avoid copying
    int n = arr.size();
    if (n == 0) return 0; // Edge case fix
    
    int max_counter = 0;
    int counter = 1;
    
    sort(arr.begin(), arr.end());
    
    for(int i = 1; i < n; i++ ){
        if(arr[i] == arr[i-1] + 1){
            counter++;
        }else if(arr[i] == arr[i-1]){
            continue;
        }else{
            max_counter = max(max_counter, counter);
            counter = 1;
        }
    }
    return max(max_counter, counter);
}

int main(){
    vector <int> arr = {100, 4, 200, 1, 1, 3, 2};
    int result = consecutive(arr);
    cout << result; // Outputs 4
    return 0;
}

/-----optimal solution 


#include<bits/stdc++.h>
using namespace std;

int consective(vector <int>arr){
    //createthe set to put all the element in the array
    unordered_set <int> st(arr.begin(),arr.end());
    int n = arr.size();

    int max_counter = 0;
    for(int i = 0; i < n; i++){
        int counter = 0;
        int num =  arr[i];
        //find the element should start from the sequence
        if(st.find(num-1) == st.end()){
            counter = 1;

            while(st.find(num+1) != st.end()){
                counter++;
                num++;
            }

            max_counter = max(max_counter,counter);
        }
    }

    return max_counter;
} 




int main(){
    vector <int> arr = {100, 4, 200, 1, 3, 2};
    int result = consective(arr);
    cout<<result;
    return 0;
}

// the time complexity is O(n)
//-----space complexity is O(n)


