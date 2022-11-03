//
//  boj 2667.cpp
//  boj
//  memory:2028 KB
//  time: 12ms
//  Created by 다곰 on 2022/11/03.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
int map[25][25];

int dx[4] ={-1,1,0,0};
int dy[4] = {0,0,-1,1};

int cnt=0;

void dfs(int x, int y) {
    for (int i=0; i<4; i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && ny>=0 && nx<n && ny<n && map[nx][ny]==1) {
            cnt++;
            map[nx][ny]=0;
            dfs(nx,ny);
        }
    }
}

int main() {
    vector<int> ans;
    
    cin >> n;
    
    string str;
    for (int i=0; i<n; i++) {
        cin >> str;
        for (int j=0; j<n; j++) {
            map[i][j]=str[j]-'0';
        }
    }
    
    for (int i=0; i<n; i++) {
        for(int j=0;j<n;j++) {
            if(map[i][j]==1) {
                map[i][j]=0;
                cnt=1;
                dfs(i,j);
                ans.push_back(cnt);
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int i=0; i<ans.size(); i++) cout << ans[i] << endl;

}

//연결: 좌우, 상하로 동일한 집이 있는 경우
//n: 지도의 크기
// return: 단지 수, 단지 속하는 집의 수 오름차순 정렬

//1. 벽을 만나거나 지도 벗어나지 않을 경우, 이전 노드와 같은 숫자이면 더해주고 visit 표시
// 2. 더 이상 갈 곳이 없으면 answer에 개수 push
// 3. 마지막 노드 map[n-1][n-1] 에 도달하면 끝
// 4. answer 오름차순 정렬하고 출력
