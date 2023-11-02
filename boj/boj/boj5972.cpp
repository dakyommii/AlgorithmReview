//
//  boj5972.cpp
//  boj
//  memory: 5240 KB
//  time: 156 ms
//  Created by 다곰 on 2023/11/02.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int,int>> vp[50001];
int dist[50001];

void diji(int a) {
    queue<int> q;
    q.push(a);
    while(!q.empty()) {
        int cur=q.front();
        q.pop();
        for(int i=0;i<vp[cur].size();i++) {
            int nx=vp[cur][i].first;
            int d=vp[cur][i].second;
            if(dist[nx]>dist[cur]+d) {
                q.push(nx);
                dist[nx]=dist[cur]+d;
            }
        }
    }
}

int main() {
    int n,m;
    cin >> n >>m;
    for(int i=0;i<m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        vp[a].push_back({b,c});
        vp[b].push_back({a,c});
    }
    
    for(int i=1;i<=n;i++) {
        dist[i]=1e9;
    }
    
    dist[1]=0;
    diji(1);
    
    cout << dist[n];
}
