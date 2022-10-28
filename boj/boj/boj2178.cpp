//
//  boj2178.cpp
//  boj
//
//  Created by 다곰 on 2022/10/28.
//

#include <iostream>
#include <string>
#include <queue>

using namespace std;

char map[100][100];
queue<pair<int,int>> q;
int v[100][100];

int n,m;

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};

void bfs(int x, int y) {
    q.push(make_pair(x, y));
    v[x][y]=1;
    while (!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        
        q.pop();
        
        for (int i=0; i<4; i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx<0 || nx>=n || ny<0 || ny>=m||map[nx][ny]!='1' || v[nx][ny]!=0) continue;
                q.push(make_pair(nx, ny));
                v[nx][ny]=v[x][y]+1;

        }
    }
}

int main() {
    cin>> n >> m;
    
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<m; j++) {
            map[i][j]=s[j];
        }
    }
    
    bfs(0,0);
    
    cout << v[n-1][m-1];

}
