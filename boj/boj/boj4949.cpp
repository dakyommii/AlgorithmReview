//
//  boj4949.cpp
//  boj
//  memory: 2024 KB
//  time: 4 ms
//  Created by 다곰 on 2023/04/10.
//

#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    stack<char> st;
    
    while(1) {
        string s;
        getline(cin,s,'\n');

        if(s==".") break;

        while(!st.empty()) st.pop();

        string ans="";
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(' || s[i]=='[') st.push(s[i]);
            else if(s[i]==')' ||s[i]==']'){
                if(st.empty()) {
                    ans= "no\n";
                    break;
                }

                if((s[i]==')' && st.top()=='(') || (s[i]==']' && st.top()=='[')) {
                    st.pop();
                }
                else {
                     ans= "no\n";
                    break;
                }
            }
        }

        if(ans=="") {
            if(!st.empty()) ans= "no\n";
            else ans="yes\n";
        }
        cout << ans;
    }
}
