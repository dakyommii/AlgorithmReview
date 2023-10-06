//
//  boj1197.cpp
//  boj
//  memory: 4492 KB
//  time: 44 ms
//  Created by 다곰 on 2023/10/06.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int a;
    int b;
    int c;
};

struct cmp {
    bool operator()(node n1, node n2) {
        return n1.c>n2.c;
    }
};

int parent[10001];

int getParent(int n) {
    if(parent[n]==n) return n;
    else return getParent(parent[n]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int v,e;
    cin >> v >> e;
    
    for(int i=1;i<=v;i++) {
        parent[i]=i;
    }
    
    priority_queue<node,vector<node>,cmp> pq;
    long long ans=0;
    for(int i=0;i<e;i++) {
        int a,b,c;
        cin >> a>>b>>c;
        pq.push({a,b,c});
    }
    
    while(!pq.empty()) {
        int a=pq.top().a;
        int b=pq.top().b;
        int c=pq.top().c;
        pq.pop();
        
        int pa=getParent(a);
        int pb=getParent(b);
        if(pa!=pb) {
            if(pa<pb) {
                parent[pb]=pa;
            }
            else parent[pa]=pb;
            
            ans+=c;
        }
        
    }
    
    cout << ans << endl;
}
