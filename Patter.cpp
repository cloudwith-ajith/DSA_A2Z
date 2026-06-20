#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=n;i <=0;i--){
        for(char ch='A';ch >='A'+i;ch++){
            cout<<ch<<" ";
        }cout<<endl;
    }return 0;
}





















/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    for(int i=0;i<=4;i++){
        for(char ch ='A';ch <= 'A'+i;ch++){
            cout<<ch<<" ";
        }cout<<endl;
    }return 0;
}

A 
A B 
A B C 
A B C D 
A B C D E 
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main(){
       for(int i=0;i<=4;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        for(int k=4;k>i;k--){
            cout<<"  ";
        }
        for(int m=0;m<=i;m++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=1;i<=4;i++){
        //start
        for(int j=4;j>=i;j--){
            cout<<"*";
        }
        //space
        for(int k=0;k<i;k = k+1){
            cout<<"  ";
         }
        //start
        for(int m=4;m>=i;m--){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}


*/

/*

#include<bits/stdc++.h>
using namespace std;

int main(){
    for(int i=0;i<=4;i++){
        //start
        for(int j=4;j>=i;j--){
            cout<<"*";
        }
        //space
        for(int k=0;k<i;k = k+1){
            cout<<"  ";
         }
        //start
        for(int m=4;m>=i;m--){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=0;i<=4;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        for(int k=4;k>i;k--){
            cout<<"  ";
        }
        for(int m=0;m<=i;m++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********
*/

/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    string arr[5]={"A","B","C","D","E"};
    for(int i =0;i<=4;i++){
        for(int j=0;j <=i;j++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


A 
B B 
C C C 
D D D D 
E E E E E   */ 

/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    string arr[5]={"A","B","C","D","E"};
    for(int i =4; i>=0;i--){
        for(int j=0;j <=i;j++){
            cout<<arr[j]<<" ";
        }cout<<endl;
    }
    return 0;
}
A B C D E 
A B C D 
A B C 
A B 
A 
*/


/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    for(int i=1;i <=5;i++){
        if(i ==1){
            cout<<"1";
        }else if(i ==2){
            cout<<"0 1";
        }else if(i==3){
            cout<<"1 0 1";
        }else if(i ==4){
            cout<<"0 1 0 1";
        }else if(i ==5){
            cout<<"1 0 1 0 1";
        }cout<<endl;
    }return 0;


/*
#include <bits/stdc++.h>
using namespace std;

int main(){
    
    for(int i=5; i>= 1; i--){
        for(int j=5; j>=i; j--){
            cout<<"*";
        }cout<<endl;
    }
    for(int x =5;x >1;x--){
        for(int y=1;y<x;y++){
            cout<<"*";
        }cout<<endl;
    }return 0;
}
*
**
***
****
*****
****
***
**
*   */

/*
int main(){
    for(int i=1;i<=5;i++){
        for(int j=5;j >i;j--){
            cout<<" ";
        }
        for(int k=1;k<=(2*i-1);k++){
            cout<<"*";
        }cout<<endl;
    }
    for(int a=5;a>=1;a--){
        for(int b=5;b>a;b--){
            cout<<" ";
        }
        for(int c=1;c<=(2*a-1);c++){
            cout<<"*";
        }cout<<endl;
    }
    return 0;
}
    *
   ***
  *****
 *******
*********
*********
 *******
  *****
   ***
    *
*/






// int main(){
//     for(int i=0;i<5;i++){
//         for(int j=5;j>=i;j--){
//             cout<<" ";
//         }
//         for(int k=0;k<(2*i-1);k++){
//             cout<<"*";
//         }cout<<endl;
    
//     for(int a=1;a<=5;a++){
//         for(int b=1;b<a;b++){
//             cout<<" ";
//         }
//         for(int c=1;c<(2*a-1);c++){
//             cout<<"*";
//         }cout<<endl;
//     }
//     return 0;
//    }
// }
 



/*
int main(){
    for(int i=0;i<5;i++){
        for(int j=5;j>=i;j--){
            cout<<" ";
        }
        for(int k=0;k<(2*i-1);k++){
            cout<<"*";
        }cout<<endl;
    }
    return 0;
}

     *
    ***
   *****
  *******
/*
int main(){
    for(int i=5;i >=1;i--){
        for(int j=1;j<=i;j++){
            cout<<j;
        }cout<<endl;
    }return 0;
}
12345
1234
123
12
1
*/

/*

int main(){
    for(int i=1;i <=5;i++){
        for(int j=5;j>=i;j=j-1){
            cout<<"* ";
        }cout<<endl;
    }return 0;
}


* * * * * 
* * * * 
* * * 
* * 
*    */

/*
int main(){
    for(int i=1;i < 6; i= i+1){
        for(int j = 1; j<=i;j=j+1){
            cout<<i;
        }cout<<endl;
    }return 0;
}
1
22
333
4444
55555   */
/*
int main(){
    for(int i =1;i<6;i = i+1){
        for(int j=1;j<=i;j=j+1){
            cout<<j ;
        }cout<<endl;
    }return 0;
}
1
12
123
1234
12345    */
 
/*
int main(){
    for(int i=0;i<5;i=i+1){
        for(int j =0;j<=i;j = j+1){
            cout<<"* ";
        }cout<<endl;
    }
    return 0;
}
* 
* * 
* * * 
* * * * 
* * * * *  */

/*
int main(){
    for(int i=0;i<5;i=i+1){
        for(int j=0;j<5;j=j+1){
            cout<<"* ";
        }cout<<endl;
    }return 0;
}
* * * * * 
* * * * * 
* * * * * 
* * * * * 
* * * * * */ 