//
//  boj7576.cpp
//  boj
//  memory: 12372 KB
//  time: 84 ms
//  Created by 다곰 on 2023/04/12.
//

#include <iostream>
#include <queue>
using namespace std;

struct tomato{
    int x;
    int y;
    int day;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int m,n,ans=0;
    int board[1001][1001];
    cin >> m >> n;
 
    queue<tomato> q;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> board[i][j];
            if(board[i][j]==1) {
                q.push({i,j,0});
                board[i][j]=-1;
            }
        }
    }
    
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    while(!q.empty()) {
        tomato t=q.front();
        q.pop();
        
        for(int i=0;i<4;i++) {
            int nx=t.x+dx[i];
            int ny=t.y+dy[i];
            
            if(nx>=n || ny>=m || nx<0 || ny<0) continue;
            if(board[nx][ny]==0) {
                q.push({nx,ny,t.day+1});
                board[nx][ny]=-1;
                ans=max(t.day+1,ans);
            }
        }
    }
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(board[i][j]!=-1) {
                cout << -1;
                exit(0);
            }
        }
    }
    cout << ans;
}
