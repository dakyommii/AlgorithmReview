//
//  boj1967.cpp
//  boj
//  memory: 100984 KB
//  time: 64 ms
//  Created by 다곰 on 2023/03/31.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct edge {
    int node;
    int v;
};
vector<vector<edge>> tree;
bool visited[10001][10001];

int leaf;
int dist=-1;
void sol(int cur,int cnt) {
    bool isLeaf=true;
    for(int i=0;i<tree[cur].size();i++) {
        edge e=tree[cur][i];
        int node=e.node;
        int v=e.v;
        
        if(!visited[cur][node]) {
            isLeaf=false;
            visited[cur][node]=true;
            visited[node][cur]=true;
            sol(node,cnt+v);
        }
    }
    
    if(isLeaf && dist<cnt) {
        leaf=cur;
        dist=cnt;
//        cout << dist << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    tree.resize(n+1);
    
    for(int i=1;i<n;i++) {
        int p,c,v;
        cin >> p >> c >> v;
        tree[p].push_back({c,v});
        tree[c].push_back({p,v});
    }
    
    sol(1,0);
    memset(visited,false,sizeof(visited));
//    visited[10001][10001]={false};
    dist=-1;
    sol(leaf,0);

    cout << dist;
}
