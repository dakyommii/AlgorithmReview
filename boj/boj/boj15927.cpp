//
//  boj15927.cpp
//  boj
//  memory: 2912 KB
//  time: 4 ms
//  Created by 다곰 on 2023/10/05.
//

#include <iostream>
#include <string>
using namespace std;

string s;
bool isPalin(int st, int e) {
    while(st<e) {
        if(s[st]!=s[e]) return false;
        st++;
        e--;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    
    char ch=s[0];
    bool same=true;
    for(int i=1;i<s.size();i++) {
        if(s[i]!=ch) {
            same=false;
            break;
        }
    }
    
    if(same) {
        cout << -1 << endl;
        return 0;
    }
    
    int l=0, r=s.size()-1;
    if(isPalin(l, r)) {
        cout << r << endl;
        return 0;
    }
    else cout << r+1 << endl;
   
}

