//
//  boj1647.cpp
//  boj
//  memory: 20972 KB
//  time: 528 ms
//  Created by 다곰 on 2023/10/27.
//

#include <iostream>
#include <vector>
#include <queue>
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

priority_queue<node,vector<node>,cmp> pq;
int parents[100001]={0};

int par(int a) {
    if(parents[a]==0) return a;
    else return par(parents[a]);
}

 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int a,b,c;
        cin >>a >>b>>c;
        pq.push({a,b,c});
    }
    
    int ans=0;
    int mx=0;
    cout << endl;
    
    
    while(!pq.empty()) {
        int a=pq.top().a;
        int b=pq.top().b;
        int c=pq.top().c;
        
        pq.pop();
        
        int pa=par(a);
        int pb=par(b);
        if(pa==pb) continue;
        if(pa>pb) parents[pa]=pb;
        else parents[pb]=pa;
        
        cout << a<<" " <<b << " "<< c << endl;
        
        ans+=c;
        mx=c;
    }
    
    cout << ans-mx;
}

// 전체 최소 경로를 구하고 간선을 선택할 때마다 최대간선 저장
