//
//  boj 1922.cpp
//  boj
//  time: 112 ms
//  memory: 4340 KB
//  Created by 다곰 on 2022/11/10.

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

int parents[1001];

int root(int c) {
    if(parents[c]==c) return c;
    else return root(parents[c]);
}

int main() {
    int n,m;
    cin >> n;
    cin >> m;
    priority_queue<node,vector<node>,cmp> pq;
    for(int i=0;i<m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        pq.push({a,b,c});
    }
    
    for(int i=1;i<=n;i++) parents[i]=i;
    
    int ans=0;
    while(!pq.empty()) {
        int a=pq.top().a;
        int b=pq.top().b;
        int c=pq.top().c;
        pq.pop();
        
        int pa=root(a);
        int pb=root(b);
        if(pa==pb) continue;
        ans+=c;
        if(pa<pb) parents[pb]=pa;
        else parents[pa]=pb;
    }
    
    cout << ans;
}
