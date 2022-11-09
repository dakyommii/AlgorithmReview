//
//  boj 11724.cpp
//  boj
//  memory: 2156 KB
//  time: 276 ms
//  Created by 다곰 on 2022/11/09.
//

#include <iostream>
#include <vector>

using namespace std;

int n;

void dfs(int node,vector<vector<bool>> &graph,vector<bool> &visit) {
    for(int i=1;i<=n;i++) {
        if(graph[node][i] && !visit[i]) {
            visit[i]=true;
            dfs(i,graph,visit);
        }
    }
}

int main() {
    
    int n, m,u,v;
    cin >> n >> m;
    
//    간선 연결 기록
    vector<vector<bool>> graph(n+1,vector<bool>(n+1,false));
//    정점 방문 기록 벡터
    vector<bool> visit(n+1,false);
    
    int cnt=0;
    
    while (m--) {
        cin >> u >> v;
        graph[u][v]=true;
        graph[v][u]=true;
    }
    
    for(int i=1;i<=n;i++) {
        if(!visit[i]) {
            cnt++;
            visit[i]=true;
            dfs(i,graph,visit);
        }
    }
    
    cout << cnt;
    
}

//<input>
//n: 정점의 개수
//m: 간선의 개수
//u: 간선의 시작 점
//v: 간선의 끝 점
//
//<output>
//연결 요소 개수 출력

//* 간선 연결 기록 벡터: vector<vector<bool>> graph; -> (n+1)*(n+1) 크기
//* 정점 방문 기록 벡터: vector<bool> visit;

//1. 간선 연결 여부를 등록
//2. 1번 노드부터 탐색 시작
//    1) 1번 노드 방문 표시
//    2) 1번 노드와 연결되어 있는 노드 있으면 이동
//    3) 새로운 시작 노드 발견할 때마다 cnt++
