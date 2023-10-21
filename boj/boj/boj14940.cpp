//
//  boj14940.cpp
//  boj
//  memory: 9848 KB
//  time: 84 ms
//  Created by 다곰 on 2023/10/21.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int b[1001][1001]={0};
int v[1001][1001]={0};
int n,m,sx,sy;

struct node{
    int x;
    int y;
    int d;
};

void bfs(int x, int y) {
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    
    queue<node> q;
    q.push({x,y,0});
    v[x][y]=0;
    while(!q.empty()) {
        int cx=q.front().x;
        int cy=q.front().y;
        int d=q.front().d;
        q.pop();

        for(int i=0;i<4;i++) {
            int nx=cx+dx[i];
            int ny=cy+dy[i];
         
            if(nx<0 || nx>=n || ny<0||ny>=m || b[nx][ny]!=1) continue;
            if(v[nx][ny]==-1 || v[nx][ny]>d+1) {
                q.push({nx,ny,d+1});
                v[nx][ny]=d+1;
            }
        }
    }
}

int main() {
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >>b[i][j];
            if(b[i][j]==1) v[i][j]=-1;
            if(b[i][j]==2) {
                sx=i;
                sy=j;
            }
        }
    }
    
    bfs(sx,sy);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << v[i][j]<< " ";
        }
        cout << '\n';
    }
}
