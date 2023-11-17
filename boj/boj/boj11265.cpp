//
//  boj11265.cpp
//  boj
//  memory: 4112 KB
//  time: 472 ms
//  Created by 다곰 on 2023/11/17.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int d[501][501];
int dist[501][501];
int n;

void dij(int st) {
    queue<int> q;
    q.push(st);
    dist[st][st]=0;
    while(!q.empty()) {
        int cur=q.front();
        q.pop();
        
        for(int i=1;i<=n;i++) {
            if(cur==i && i==st) continue;
            if(dist[st][i]>dist[st][cur]+d[cur][i]) {
                dist[st][i]=dist[st][cur]+d[cur][i];
                q.push(i);
            }
            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        
        for(int j=1;j<=n;j++) {
            cin >> d[i][j];
            dist[i][j]=1e9;
        }
    }
    
    for(int i=1;i<=n;i++) {
        dij(i);
    }
    
    for(int i=0;i<m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        
        if(dist[a][b]<=c) cout << "Enjoy other party\n";
        else cout << "Stay here\n";
       
    }
}

/*
일방통행
c 시간 이후에 파티 열리는데 파티 맞춰 갈 수 있는가
n: 파티장 크기 1~n
m: 손님 수

인접행렬로 기록
m개로 a,b 까지 c 시간 내로 갈 수 있는지 확인
*/
