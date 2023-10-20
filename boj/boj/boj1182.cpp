//
//  boj1182.cpp
//  boj
//  memory: 2020 KB
//  time: 48 ms
//  Created by 다곰 on 2023/10/20.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int ans=0,s,n;

void dfs(int st,int c, int sum,int d) {
    if(c==d) {
        if(sum==s) ans++;
        return;
    }
    
    for(int i=st;i<n;i++){
        dfs(i+1,c+1,sum+v[i],d);
    }
}

int main() {
    cin >> n>>s;
    
    for(int i=0;i<n;i++) {
        int k;
        cin >> k;
        v.push_back(k);
        if(k==s) ans++;
    }
    
    for(int i=2;i<=n;i++) {
        dfs(0,0,0,i);
    }
    
    cout << ans;
}


