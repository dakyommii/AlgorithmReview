//
//  boj1213.cpp
//  boj
//  memory: 2028 KB
//  time: 0 ms
//  Created by 다곰 on 2023/10/19.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    map<char,int> mp;
    
    for(int i=0;i<s.size();i++) {
        mp[s[i]]++;
    }
    
    string sub="";
    char mid='.';
    string ms="";
    for(auto it: mp) {
        if(it.second%2==0) {
            sub.append(it.second/2,it.first);
        }
        else if(mid=='.') {
            mid=it.first;
            if(it.second>=3) {
                ms.append(it.second/2,it.first);
            }
        }
        else {
            cout << "I'm Sorry Hansoo";
            return 0;
        }
    }
    
    string ans="";
    if(s.size()%2==0) {
        sort(sub.begin(), sub.end());
        ans+=sub;
        reverse(sub.begin(), sub.end());
        ans+=sub;
    }
    else if(mid!='.') {
        if(ms.size()>0) sub+=ms;
        sort(sub.begin(), sub.end());
        ans+=sub;
        ans+=mid;
        reverse(sub.begin(), sub.end());
        ans+=sub;
    }
    
    cout << ans;
    
}

/*
양쪽 끝에서 시작해서
*/
