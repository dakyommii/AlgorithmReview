//
//  boj13460.cpp
//  boj
//  memory: 2024 KB
//  time: 0 ms
//  Created by 다곰 on 2023/04/03.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct loc {
    int rx;
    int ry;
    int bx;
    int by;
    int cnt;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    char board[11][11];
    int visited[11][11][11][11]={0};
    int n,m;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    cin >> n >> m;

    queue<loc> q;

    loc l;
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        for(int j=0;j<m;j++) {
            board[i][j]=s[j];
            if(board[i][j]=='R') {
                l.rx=i;
                l.ry=j;
            }
            if(board[i][j]=='B') {
                l.bx=i;
                l.by=j;
            }
        }
    }
    l.cnt=0;
    q.push(l);  // 처음 빨간 구슬, 파란 구슬 시작 위치 큐에 push
    visited[l.rx][l.ry][l.bx][l.by]=1;  // 처음 빨간 구슬, 파란 구슬 시작 위치 방문 처리

    int ans=-1;
    while(!q.empty()) {

        loc cur=q.front();
        q.pop();

        if (cur.cnt>10) break;  // 방법을 찾을 수 없는 경우 -> 실패
        // R 만 탈출 -> 성공
        // BFS 풀이를 쓰기 때문에 처음 구멍에 들어가는 순간의 count 가 최소경로가 될 수밖에 없음
        if (board[cur.rx][cur.ry]=='O' && board[cur.bx][cur.by]!='O') {
            ans=cur.cnt;
            break;
        }

        // 상하좌우로 다음에 이어서 큐에 넣을 위치 탐색
        for(int i=0;i<4;i++) {
            int next_rx=cur.rx;
            int next_ry=cur.ry;
            int next_bx=cur.bx;
            int next_by=cur.by;

            // R이 벽에 닿을때까지
            while (1) {
                // 구멍에 빠지면 현재까지 갱신된 next 위치가 전진할 수 있는 최대 위치
                if(board[next_rx][next_ry]=='O') break;
                // 벽을 만나면 현재까지 갱신된 next 위치의 하나 이전 위치가 전진할 수 있는 최대 위치
                else if(board[next_rx][next_ry]=='#') {
                    next_rx-=dx[i];
                    next_ry-=dy[i];
                    break;
                }
                // 벽이 아니거나 구멍이 아니라면 전진할 수 있는 위치
                else {
                    next_rx+=dx[i];
                    next_ry+=dy[i];
                }
            }

            // B가 벽에 닿을때까지
            while (1) {
                // 구멍에 빠지면 현재까지 갱신된 next 위치가 전진할 수 있는 최대 위치
                if(board[next_bx][next_by]=='O') break;
                // 벽을 만나면 현재까지 갱신된 next 위치의 하나 이전 위치가 전진할 수 있는 최대 위치
                else if(board[next_bx][next_by]=='#') {
                    next_bx-=dx[i];
                    next_by-=dy[i];
                    break;
                }
                // 벽이 아니거나 구멍이 아니라면 전진할 수 있는 위치
                else {
                    next_bx+=dx[i];
                    next_by+=dy[i];
                }
            }

            // R 의 최종위치와 B의 최종위치가 구멍이 아니면서 겹치는 경우
            if(next_rx==next_bx && next_ry==next_by && board[next_rx][next_ry]!='O') {
                // 각 구슬이 현재 위치에서 최종위치까지 이동한 거리
                int r_dist= abs(next_ry-cur.ry)+abs(next_rx-cur.rx);
                int b_dist= abs(next_by-cur.by)+abs(next_bx-cur.bx);

                // 더 이동한 거리가 많은 구슬이 다른 구슬보다 앞에 있어야 함
                // RB..# 를 움직이면 ..RB# 이 되고 R과 B가 같은 위치에 도달해야 한다면 R이 더 많이 움직여야 하는 원리
                if(r_dist>b_dist) {
                    next_rx-=dx[i];
                    next_ry-=dy[i];
                }
                else {
                    next_bx-=dx[i];
                    next_by-=dy[i];
                }
            }

            // 최종적으로 R과 B가 다음으로 이동할 위치 방문 처리 및 큐에 push
            if(visited[next_rx][next_ry][next_bx][next_by]==0) {
                visited[next_rx][next_ry][next_bx][next_by]=1;
                loc next;
                next.rx=next_rx;
                next.ry=next_ry;
                next.bx=next_bx;
                next.by=next_by;
                next.cnt=cur.cnt+1;
                q.push(next);
            }
        }
    }

    cout << ans;


}


