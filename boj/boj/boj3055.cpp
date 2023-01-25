//
//  boj3055.cpp
//  boj
//  memory: 2048 KB
//  time: 0 ms
//  Created by 다곰 on 2023/01/25.
//

#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

struct pos {
    int x;
    int y;
};

int r,c,sx,sy;
char board[51][51];
queue<pos> water;

int wdist[51][51];
int sdist[51][51];

// 상하좌우
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void waterCheck() {
    while(!water.empty()) {
        pos p=water.front();
        int x=p.x;
        int y=p.y;
        
        for(int i=0;i<4;i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            int cnt=wdist[x][y];
            if(nx<0 || nx>=r || ny<0 || ny>=c) continue;
            if(board[nx][ny]!='X' && board[nx][ny]!='D'&& wdist[nx][ny]==-1) {
                water.push({nx,ny});
                wdist[nx][ny]=cnt+1;
            }
        }
        water.pop();
    }
}

void sCheck() {
    queue<pos> q;
    q.push({sx,sy});
    sdist[sx][sy]=0;
    
    while(!q.empty()) {
        pos sp=q.front();
        int x=sp.x;
        int y=sp.y;
        
        int cnt=sdist[x][y];
        for(int i=0;i<4;i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx<0 || nx>=r || ny<0 || ny>=c) continue;
            if (board[nx][ny]=='X' || board[nx][ny]=='D' || sdist[nx][ny]!=-1) continue;
            q.push({nx,ny});
            sdist[nx][ny]=cnt+1;
        }
        q.pop();
    }
}

int main() {
    int fx,fy;
    cin >> r >> c;
    
    memset(wdist,-1,sizeof(wdist));
    memset(sdist,-1,sizeof(sdist));
  
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cin >> board[i][j];
            if(board[i][j] == 'S') sx = i, sy = j;
            else if(board[i][j] == 'D') fx = i, fy = j;
            else if(board[i][j] == '*') {
                water.push({i,j});
                wdist[i][j]=0;
            }
        }
    }

    waterCheck();
    sCheck();

    int ans=30000;

    for (int i=0; i<4; i++) {
        int nx=fx+dx[i];
        int ny=fy+dy[i];

        if(nx<0 || nx>=r || ny<0 || ny>=c) continue;
        if(wdist[nx][ny] > 0 && sdist[nx][ny] >= wdist[nx][ny]) continue;
        if(sdist[nx][ny] == -1) continue;
        ans=min(ans, sdist[nx][ny]+1);

    }

    if (ans==30000) cout << "KAKTUS";
    else cout << ans;
    

}
