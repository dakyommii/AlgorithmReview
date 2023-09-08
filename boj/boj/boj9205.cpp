//
//  boj9205.cpp
//  boj
//  memory: 2028 KB
//  time: 4 ms
//  Created by 다곰 on 2023/09/08.
//

#include <iostream>
#include <queue>
#include <map>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,sx,sy,ex,ey;
        cin >> n;
        cin >> sx >> sy;
        vector<pair<int,int>> vp;
        map<pair<int,int>,int> visit;
        for(int i=0;i<n;i++) {
            int x,y;
            cin >> x>> y;
            vp.push_back({x,y});
            visit[{x,y}]=0;
        }
        cin >> ex >> ey;
        
        
        queue<pair<int,int>> q;
        q.push({sx,sy});
        visit[{sx,sy}]=0;
        int beer=20;
        bool happy=false;

        while(!q.empty()) {
            int cx=q.front().first;
            int cy=q.front().second;
            q.pop();

            if(visit[{cx,cy}]==1) continue;
            visit[{cx,cy}]=1;

            beer=20;
            // 바로 목적지 갈 수 있는지 검사
            if((abs(ex-cx)+abs(ey-cy))<=beer*50) {
                happy=true;
                break;
            }

            // 편의점 가기
            for(int i=0;i<n;i++) {
                int nx=vp[i].first;
                int ny=vp[i].second;

                if(visit[{nx,ny}]==1) continue;
                // 갈 수 있으면 가기
                if((abs(nx-cx)+abs(ny-cy))<=beer*50) {
                    q.push({nx,ny});
                }
            }
        }

        if(!happy) cout << "sad" << endl;
        else cout << "happy" << endl;
    }
       
}

/*
맥주 총 20개
50미터에 맥주 하나
편의점에서 구매 가능 but total 20개 이하
*/

/*
 반례)
 
 1
 2
 0 0
 1000 5
 2000 10
 3000 15
 */
