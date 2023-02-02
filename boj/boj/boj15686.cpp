//
//  boj15686.cpp
//  boj
//  memory: 2032 KB
//  time: 4 ms
//  Created by 다곰 on 2023/02/02.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct edge {
    int x;
    int y;
};

int n,m,ans=2147483647;
int board[50][50];
vector<edge> chicken;
vector<edge> home;
int cmb[14];    // 치킨집 인덱스 조합 저장

void dfs(int depth,int next) {
    if(depth==m) {
        int cnt=0;  //해당 조합 총 치킨거리 저장 변수
        for(int i=0;i<home.size();i++) {
            int nx=home[i].x;
            int ny=home[i].y;

            int dist=2147483647;    // 각 집의 치킨거리 초기화
            //치킨 집 조합 돌면서 치킨거리 계산해서 최소 치킨거리 구하기
            for(int j=0;j<m;j++) {
                int idx=cmb[j];
                int x=chicken[idx].x;
                int y=chicken[idx].y;

                dist=min(dist, abs(x-nx)+abs(y-ny));

            }

            cnt+=dist;  // 해당 조합으로의 각 집의 치킨거리 저장

        }
        
        ans=min(ans,cnt);   //최종적인 최소 치킨 거리 계산

        return;
    }
    
    // 조합 만들기
    for(int i=next;i<chicken.size();i++) {
        cmb[depth]=i;
        dfs(depth+1,i+1);
    }
}

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> board[i][j];
            if(board[i][j]==2) chicken.push_back({i,j});    // 치킨집 좌표 저장
            else if(board[i][j]==1) home.push_back({i,j});  // 집 좌표 저장
        }
    }
    
    dfs(0,0);
    
    cout << ans;
}

//치킨 집 조합
//조합 중에서 최소값 산출

