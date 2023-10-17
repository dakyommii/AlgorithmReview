//
//  boj12919.cpp
//  boj
//  memory: 2024 KB
//  time: 0 ms
//  Created by 다곰 on 2023/10/17.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s1,s2;
bool success=false;
bool dfs(string s) {

    if(s==s1) return true;
    if(s.size()<=s1.size()) return false;
    
    if(s.back()=='A') {
        s.pop_back();
        if(dfs(s)) return true;
        s.push_back('A');
    }
    
    reverse(s.begin(), s.end());
    if(s.back()=='B') {
        s.pop_back();
        return dfs(s);
    }

    return false;
}

int main() {
    string s,t;
    cin >> s>>t;
    
    // 둘 중 길이가 짧은 것을 바꾸기 s1 -> s2
    if(s.size()<t.size()) {
        s1=s;
        s2=t;
    }
    else if(s.size()>t.size()) {
        s1=t;
        s2=s;
    }
    else {
        cout << 0;
        return 0;
    }
    
    cout <<dfs(s2);
    
}

/*
a -> baba
aa -> x
ba -> 포함
-------
baa -> x
bab -> 포함
--------
baba -> 완성

BAAAAABAA
BAABAAAAAB

BAAAAABAAA -> x
BAABAAAAAB -> 완성

A -> ABBA

AA->x
BA
------
BAA->x
BAB->x
*/
