//  boj 21608.cpp
//  boj
//  memory: 2368 KB
//  time: 4 ms
//  Created by 다곰 on 2022/11/04.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int n;
bool love[401][401]={false};
int board[21][21]={0,};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

struct node {
    int x;
    int y;
    int lk;
    int emp;
};

struct cmp {

    bool operator()(node& n1, node& n2) {
        if(n1.lk==n2.lk) {
            if(n1.emp==n2.emp) {
                if(n1.x==n2.x) return n1.y>n2.y;
                return n1.x>n2.x;
            }

            return n1.emp<n2.emp;
        }
        return n1.lk<n2.lk;
    }

};

void sit(int cur) {
    priority_queue<node,vector<node>,cmp> pq;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {

            if(board[i][j]!=0) continue;

            int cnt_like=0, cnt_emp=0;
            for(int k=0;k<4;k++) {
                int nx=i+dx[k];
                int ny=j+dy[k];

                if(nx<0 || nx>=n || ny<0 || ny>=n) continue;

                int next=board[nx][ny];

                if(board[nx][ny]==0) cnt_emp++;
                else if(love[cur][next]) cnt_like++;
            }

            pq.push({i,j,cnt_like,cnt_emp});

        }
    }

    node nd=pq.top();
    board[nd.x][nd.y]=cur;

}

int main() {

    cin >> n;

    vector<int> seq;
    for(int i=0;i<n*n;i++) {
        int st;
        cin >> st;
        seq.push_back(st);

        for(int j=0;j<4;j++) {
            int lk;
            cin >> lk;
            love[st][lk]=true;
        }
    }

    for(int i=0;i<seq.size();i++) {
        int cur=seq[i];

        sit(cur);
    }

    int ans=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {

            int cur=board[i][j];
            cout<<cur << " ";
            if(cur==0) continue;
            int cnt=0;
            for(int k=0;k<4;k++) {
                int nx=i+dx[k];
                int ny=j+dy[k];

                if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                int next=board[nx][ny];

                if(love[cur][next]) cnt++;
            }

            ans+=pow(10,cnt-1);
        }
        cout << endl;
    }

    cout << ans;

}

/*
    풀이2 - 우선순위 큐 사용X
    주의: 학생수는 20*20 이 최대 -> OOB 발생
*/
//#include <iostream>
//#include <cmath>
//#include <vector>
//using namespace std;
//
//int n;
//int board[21][21]={0};
//int seq[401];
//int like[401][4];
//int dx[4]={0,0,-1,1};
//int dy[4]={-1,1,0,0};
//
//void seat(int cur) {
//
//    int mx_emp=-1,mx_near=-1,fx=20,fy=20;
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<n;j++) {
//            if(board[i][j]!=0) continue;
//            int emp=0,near=0;
//            for(int k=0;k<4;k++) {
//                int nx=i+dx[k];
//                int ny=j+dy[k];
//                if(nx<0||nx>=n|| ny<0||ny>=n) continue;
//                int c=board[nx][ny];
//                if(c==like[cur][0]||c==like[cur][1]||c==like[cur][2]||c==like[cur][3]) near++;
//                else if(c==0)emp++;
//            }
//
//            if(mx_near==near) {
//                if(mx_emp==emp) {
//                    if(fx>i || (fx==i && fy>j)) {
//                        mx_near=near;
//                        mx_emp=emp;
//                        fx=i;
//                        fy=j;
//                    }
//                }
//                else if(mx_emp<emp) {
//                    mx_near=near;
//                    mx_emp=emp;
//                    fx=i;
//                    fy=j;
//                }
//            }
//            else if(mx_near<near) {
//                mx_near=near;
//                mx_emp=emp;
//                fx=i;
//                fy=j;
//            }
//        }
//    }
//
//    board[fx][fy]=cur;
//}
//
//
//int main() {
//    cin >> n;
//    for(int i=0;i<n*n;i++) {
//        int idx;
//        cin >> idx>> like[idx][0]>>like[idx][1]>>like[idx][2]>>like[idx][3];
//        seq[i]=idx;
//    }
//
//    for(int i=0;i<n*n;i++) {
//        seat(seq[i]);
//    }
//
//    int ans=0;
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<n;j++) {
//            int cur=board[i][j];
//            int cnt=0;
//            for(int k=0;k<4;k++) {
//                int nx=i+dx[k];
//                int ny=j+dy[k];
//                if(nx<0||nx>=n|| ny<0||ny>=n) continue;
//                int c=board[nx][ny];
//                if(c==like[cur][0]||c==like[cur][1]||c==like[cur][2]||c==like[cur][3]) cnt++;
//            }
//            if(cnt!=0) ans+=pow(10,cnt-1);
//        }
//    }
//
//    cout << ans;
//
//}

/*
교실: n*n
학생수: n*n
(1,1) 부터 시작
학생은 1번부터 시작
각 학생 선호 학생 4명
상하좌우에 있으면 인접한 것
1. 선호 학생이 인접자리에 많은 자리
2. 비어 있는 칸이 가장 많은 칸
3. 행<열 작은 순
모든 배치가 끝난 후 만족도 조사
*/
