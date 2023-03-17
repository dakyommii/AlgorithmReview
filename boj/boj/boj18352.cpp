//
//  boj18352.cpp
//  boj
//  memory: 21724 KB
//  time: 360 ms
//  Created by 다곰 on 2023/03/17.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n,m,k,x;
    cin >> n >> m >> k >> x;
    
    vector<vector<int>> road(n+1);
    vector<int> node(n+1,987654321);
    for(int i=0;i<m;i++) {
        int s,e;
        cin >> s >> e;
        road[s].push_back(e);
    }
    
    queue<int> q;
    node[x]=0;
    q.push(x);
    
    while(!q.empty()) {
        int cur=q.front();
        q.pop();

        for(int i=0;i<road[cur].size();i++) {
            int next=road[cur][i];
            
            if (node[next]>node[cur]+1) {
                node[next]=node[cur]+1;
                q.push(next);
            }
            
        }
        
    }
    
    bool exist=false;
    for(int i=1;i<=n;i++) {
        if(node[i]==k) {
            cout << i << '\n';
            exist=true;
        }
    }
    
    if(!exist) cout << -1;
}

/*
 최대한 if문은 줄이기
 최대값으로 초기화 -> 987654321
 */
