//
//  boj1068.cpp
//  boj
//  memory: 2020 KB
//  time: 0 ms
//  Created by 다곰 on 2023/03/28.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[50];
bool visit[51];
int cnt=0;

void dfs(int n) {
    bool isLeaf=true;
    for(int i=0;i<tree[n].size();i++) {
        int next=tree[n][i];
        if(!visit[next]) {
            isLeaf=false;
            visit[next]=true;
            dfs(next);
        }
    }
    
    if(isLeaf) cnt++;
}

int main() {
    int n,node,rt;
    cin >> n;
    
    for(int i=0;i<n;i++) {
        int k;
        cin >> k;
        
        if(k==-1) {
            rt=i;
            continue;
        }
        tree[i].push_back(k);
        tree[k].push_back(i);
    }
    
    cin >> node;
    
    visit[node]=true;
    visit[rt]=true;
    if(rt!=node) dfs(rt);
    
    cout << cnt << endl;

}
