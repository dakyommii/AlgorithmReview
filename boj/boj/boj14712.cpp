//
//  boj14712.cpp
//  boj
//  memory: 2020 KB
//  time: 228 ms
//  Created by 다곰 on 2023/10/31.
//

#include <iostream>
#include <vector>
using namespace std;

int n,m,ans=0;
bool visit[26][26]={false};

// 좌, 상, 왼쪽 대각선 위
int dx[3]={0,-1,-1};
int dy[3]={-1,0,-1};

void dfs(int x, int y) {
    // 현재 위치가 마지막 위치인 경우
    if(x==n-1 && y==m) {
        ans++;
        return;
    }
        
    // 현재 위치가 y 끝인 경우
    if(y==m) {
        y=0;
        x++;
    }
    
    // 현재 위치가 2*2 만듦
    bool pass=true;
    for(int i=0;i<3;i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(!visit[nx][ny]) {
            pass=false;
            break;
        }
    }
    
    visit[x][y]=true;
    if(!pass) dfs(x,y+1);    // 네모 올리기
    
    visit[x][y]=false;
    //default: 지나침
    dfs(x,y+1);
}

int main() {
    cin >> n >> m;
   
    visit[0][0]=true;
    dfs(0,0);
    
    cout << ans;
    
}
