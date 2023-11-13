//
//  boj1967.cpp
//  boj
//  memory: 2868 KB
//  time: 12 ms
//  Created by 다곰 on 2023/03/31.

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int,int>> tree[10001];
bool visit[10001]={false};
int ans=0,leaf;

void dfs(int cur, int dist) {
    if(visit[cur]) return;
    visit[cur]=true;
    
    if(dist>ans) {
        ans=dist;
        leaf=cur;
    }
    
    for(int i=0;i<tree[cur].size();i++) {
        int nx=tree[cur][i].first;
        int d=tree[cur][i].second;
        
        dfs(nx,dist+d);
    }
    
    
}

int main() {
    int n;
    cin >> n;
    
    for(int i=1;i<n;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }
    
    dfs(1,0);
    ans=0;
    
    memset(visit, 0, sizeof(visit));
    
    dfs(leaf,0);
    cout << ans;
}
