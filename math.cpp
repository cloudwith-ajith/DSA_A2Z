#include<bits/stdc++.h>
using namespace std;

int main(){
    int n =10;
    int start =3;
    for(int i =0;i <n;i++){
        cout<<start;
        start =start+4;
        cout<<endl;
    }
    return 0;
}  

//using formula for the AP

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a = 3;
    int d = 4;
    int result = a+(n-1)*d;
    cout<<result;
    return 0;
}

//Many loop counts secretly follow: 1 + 2 + 3 + ... + n   --->n(n+1)/2
#include<bits/stdc++.h>
 using namespace std;

int main(){
    int n;
    cin>>n;
    int sum =0;
    for(int i =1;i<=n;i++){
        sum =sum+i;
    }
    cout<<sum;
    return 0;
}

//instead of this:
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a =n*(n+1)/2;
    cout<<a;
    return 0;
}

//power method
#include<bits/stdc++.h>
using namespace std;

int main(){
    for(int i = 1;i <=3;i++){
        cout<<(1<<i)<<endl;
        
    }
    return 0;
}
// power 
#include<bits/stdc++.h>
using namespace std;

int main(){
    for(int i = 1;i <=3;i++){
        int a = pow(2,i);
        cout<<a<<endl;
        
    }
    return 0;
}

//reverse with out the array
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        cout<<n-i-1;
        cout<<endl;
    }
    return 0;
}

//reverse math

#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5};
    int n = 5;
    for(int i=0;i<5;i++){
        cout<<arr[n-i-1];
    }
    return 0;
}
