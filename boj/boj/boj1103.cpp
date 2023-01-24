//
//  boj1103.cpp
//  boj
//  memory: 2048 KB
//  time: 0 ms
//  Created by 다곰 on 2023/01/23.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int board[51][51];
bool visit[51][51];
int dp[51][51];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int n,m;

int dfs(int x, int y) {

    // out of index
    if(x<0 || x>=n || y<0 || y>=m || board[x][y]==0) return 0;

    // loop 발생 -> -1 출력하고 바로 죽여버리기
    if(visit[x][y]) {
        cout << -1;
        exit(0);
    }


    // 이미 방문했을 경우 return
    if(dp[x][y]!=-1) return dp[x][y];
    
    visit[x][y]=true;
    
    dp[x][y]=0;
    for (int i=0; i<4; i++) {
        int nx=x+dx[i]*board[x][y];
        int ny=y+dy[i]*board[x][y];

        dp[x][y]=max(dp[x][y], dfs(nx, ny)+1);    // out of index도 거리에 count
    }

    // 다른 방향 탐색 위해 visit 풀어주기
    visit[x][y]=false;


    // 최종적 ans return 위해
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    cin >> n >> m;

    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        for(int j=0;j<m;j++) {
            if(s[j]=='H') board[i][j]=0;
            else board[i][j]=s[j]-'0';
        }
    }

    memset(dp, -1, sizeof(dp));
    
    cout << dfs(0,0);

}


