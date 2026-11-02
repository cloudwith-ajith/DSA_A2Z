#include<bits/stdc++.h>
using namespace std;

int Maximum_Depth(string s){
    int n = s.size();

    int opened = 0; // Tracks currently open parentheses
    int answer = 0; // Tracks the maximum depth seen so far
    
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            opened++;
            answer = max(answer , opened); // Update max depth if current depth is higher
        } else if (s[i] == ')') {
            opened--; // Close the innermost open parenthesis
        }
        // Ignores numbers (0-9) and operators (+, -, *, /) automatically
    }

    return answer;
}

int main(){
    string s = "(1+(2*3)+((8)/4))+1";
    cout << Maximum_Depth(s); // Outputs: 3
    return 0;
}

// th
