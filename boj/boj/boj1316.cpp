//
//  boj1316.cpp
//  boj
//  memory: 2024 KB
//  time: 0 ms
//  Created by 다곰 on 2023/03/09.
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool visited[26];
bool isGrp(string s) {
    char c=s[0];
    visited[c-'a']=true;
    for(int i=1;i<s.size();i++) {
        char ch=s[i];
        if(c==ch) continue;
        
        if(visited[ch-'a']) return false;
        else {
            c=ch;
            visited[ch-'a']=true;
        }
    }
    return true;
}

int main() {
    int n,cnt=0;
    cin >> n;
    while(n--) {
        memset(visited,false,sizeof(visited));
        string s;
        cin >> s;
        if(isGrp(s)) cnt++;
    }
    cout << cnt;
}
