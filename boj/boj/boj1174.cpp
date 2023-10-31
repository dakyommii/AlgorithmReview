//
//  boj1174.cpp
//  boj
//  memory: 2024 KB
//  time: 0 ms
//  Created by 다곰 on 2023/10/31.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> v;
void dfs(string s,int cur) {
    for(int i=cur-1;i>=0;i--) {
        s+=(i+'0');
        v.push_back(stoll(s));
        dfs(s,i);
        s.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=0;i<=9;i++) v.push_back(i);
    
    for(int i=1;i<=9;i++) {
        string s=to_string(i);
        dfs(s,i);
    }
    
    sort(v.begin(),v.end());
    
    if(v.size()<n) cout << -1;
    else cout << v[n-1];
}

