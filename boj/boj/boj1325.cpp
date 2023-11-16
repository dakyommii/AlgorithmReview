//
//  boj1325.cpp
//  boj
//  memory: 3100 KB
//  time: 2648 KB
//  Created by 다곰 on 2023/11/16.
//

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

vector<int> v[10001];
bool visit[10001]={false};
int ca[10001]={0};

void bfs(int st) {
    queue<int> q;
    q.push(st);
    visit[st]=true;
    int cnt=0;
    while(!q.empty()) {
        int cur=q.front();
        q.pop();
        for(int i=0;i<v[cur].size();i++) {
            int nx=v[cur][i];
            if(!visit[nx]) {
                cnt++;
                q.push(nx);
                visit[nx]=true;
            }
        }
    }
    
    ca[st]=cnt;
}

int main() {
    int n,m;
    
    cin >> n >>m;
    
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        v[b].push_back(a);
    }
    
    for(int i=1;i<=n;i++) {
        memset(visit,false,sizeof(visit));

        bfs(i);
    }
    
    int mx=*max_element(ca, ca+n+1);
    
    for(int i=1;i<=n;i++) {
        if(ca[i]==mx) cout << i <<" ";
    }
    
}

/*
컴퓨터간 신뢰관계, 비신뢰관계 존재
한번에 많이 해킹
*/
