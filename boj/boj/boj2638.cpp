//
//  boj2638.cpp
//  boj
//  memory: 2196 KB
//  time: 12 ms
//  Created by 다곰 on 2023/11/03.
//

#include<iostream>
#include<queue>
#include <vector>

using namespace std;

int board[101][101];
int n,m;
int cnt=0;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

bool del(int x, int y) {
  int ice=0;
  for(int i=0;i<4;i++) {
    int nx=dx[i]+x;
    int ny=dy[i]+y;

    if(board[nx][ny]==2) ice++;

    if(ice>=2) return true;
  }
    
  return false;
}

void bfs(int x, int y) {
    queue<pair<int,int>> cq;
    cq.push({x,y});
    board[x][y]=2;
    
    while(!cq.empty()) {
        int cx=cq.front().first;
        int cy=cq.front().second;
        
        cq.pop();
        
        for(int i=0;i<4;i++) {
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            
            if(board[nx][ny]==0) {
                board[nx][ny]=2;
                cq.push({nx,ny});
            }
        }
    }
}

int main() {
    cin >> n >> m;

    vector<pair<int,int>> vp;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
        cin >> board[i][j];
        if(board[i][j]==1) vp.push_back({i,j});
    }
  }

    int ans=0;
    int cnt=vp.size();
    queue<pair<int,int>> eq;
    eq.push({0,0});
    
  while(cnt>0) {
      
    ans++;
      
      // bfs로 바깥공기 2 표시
      while (!eq.empty()) {
          int ex=eq.front().first;
          int ey=eq.front().second;
          
          eq.pop();
          bfs(ex,ey);
      }
      
      for(int i=0;i<vp.size();i++) {
          int ex=vp[i].first;
          int ey=vp[i].second;
          
          if(board[ex][ey]==1) {
              if(del(ex,ey)) {
                  cnt--;
                  eq.push({ex,ey});
              }
          }
      }
      
  }

  cout << ans;
  

   return 0;
}

// n*m 세로,가로
// 모든 얼음은 2변 이상이 얼음 외부 공기와 접촉하면 한시간 만에 녹아버림
// 모두 녹는데 걸리는 시간
// 얼음 녹을 때까지 계속 격자 확인
// 얼음 주변에 외부 공기가 몇 개 있는지 확인, 얼음 주변에 외부 공기가 있다면 이 공기가 외부 공기인지 내부 공기인지 확인
// 녹을 얼음은 큐에 담아두고 하나의 보드판을 모두 탐색한 이후에 한꺼번에 지워주기
// 가장 자리는 놓지 않기 때문에 탐색할 필요 없음

// 치즈가 놓여 있는 위치를 큐에 저장
// bfs로 공기가 갈 수 있는 부분만 2로 표시
// 큐에 저장했던 값들 중 주변에 2가 두개 이상 있으면 0으로 바꾸기 -> 첫번째 위치 저장,
// 저장했던 부터 시작해서 갈 수 있는 모든 0을 2로 바꾸기
