//------------------------intersection
//---------brute force

#include<bits/stdc++.h>
using namespace std;

vector <int> intersation(vector <int> a, vector <int> b){
    int s1 = a.size();
    int s2 = b.size();
    vector <int> temp;
    int vistor[s2] ={0};
    
    for(int i = 0; i < s1; i++){
        for(int j = 0 ;j < s2; j++){
            if(a[i] == b[j] && vistor[j] == 0){
                temp.push_back(a[i]);
                vistor[j] = 1;
                break;
            }
        }
    }
    
    
    return temp;
}

int main(){
    vector <int> a ={1,2,2,3,3,3,4,5,6};
    vector <int> b ={2,2,3,3,6};
    vector <int> result = intersation(a,b);
    for(int i : result){
        cout<<i<<" ";
    }
    return 0;
}

//------------------------intersection
//--------optimal 2 pointers
#include<bits/stdc++.h>
using namespace std;

vector <int> intersation(vector <int> a, vector <int> b){
    int s1 = a.size();
    int s2 = b.size();
    vector <int> temp;
    int i = 0;
    int j = 0;
    while(i < s1 && j < s2){
        if(a[i] < b[j]){
            i++;
        }else if(a[i] > b [j]){
            j++;
        }else{
            temp.push_back(a[i]);
            i++;
            j++;
        }
    }

    return temp;
}

int main(){
    vector <int> a ={1,2,2,3,3,3,4,5,6};
    vector <int> b ={2,2,3,3,6};
    vector <int> result = intersation(a,b);
    for(int i : result){
        cout<<i<<" ";
    }
    return 0;
}


