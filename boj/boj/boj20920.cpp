//
//  boj20920.cpp
//  boj
//  memory: 13864 KB
//  time: 144 ms
//  Created by 다곰 on 2023/10/21.
//

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool cmp(pair<string,int> p1, pair<string,int> p2) {
    if(p1.second==p2.second) {
        if((p1.first).size() == (p2.first).size()) {
            return p1.first<p2.first;
        }
        return (p1.first).size()> (p2.first).size();
    }
    return p1.second>p2.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin >>n >>m;
    map<string,int> mp;
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        if(s.size()>=m) mp[s]++;
    }
    
    vector<pair<string,int>> vp(mp.begin(),mp.end());
    sort(vp.begin(),vp.end(),cmp);
    
    for(int i=0;i<vp.size();i++) {
        cout << vp[i].first << '\n';
    }
}

/*
자주 나오는 단어일수록 앞에 배치한다.
해당 단어의 길이가 길수록 앞에 배치한다.
알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다
M이상인 단어들만 외운다고 한다
*/
