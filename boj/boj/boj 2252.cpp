//
//  boj 2252.cpp
//  boj
//  memory: 3832 KB
//  time: 76 ms
//  Created by 다곰 on 2023/01/20.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    
    queue<int> q;
    vector<vector<int>> edge(n+1);
    vector<int> vertex(n+1,0);
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        vertex[b]++;
        edge[a].push_back(b);
    }
    
    for(int i=1;i<=n;i++) {
        if(vertex[i]==0) q.push(i);
    }
    
    while(!q.empty()) {
        int st=q.front();
        q.pop();
        
        cout << st << " ";
        for(int i=0;i<edge[st].size();i++) {
            int k=edge[st][i];
            vertex[k]--;
            if(vertex[k]==0) q.push(k);
        }
    }
}
