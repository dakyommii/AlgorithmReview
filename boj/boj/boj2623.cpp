//
//  boj2623.cpp
//  boj
//  memory: 2024 KB
//  time: 0 ms
//  Created by 다곰 on 2023/11/17.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> dg(n+1,0);
    vector<int> v[1001];
    vector<bool> visit(n+1,false);
    vector<int> ans;
    dg[0]=1001;

    for(int i=0;i<m;i++) {
        int c;
        cin >> c;
        int pre=-1;
        while(c--) {
            int k;
            cin >> k;
            
            // 인접행렬과 현재 원소의 선행 원소 개수 기록
            if(pre!=-1) {
                dg[k]++;
                v[pre].push_back(k);
            }
            pre=k;
        }
    }

    // 차수가 0인 원소 모두 큐에 저장해두고 시작
    queue<int> q;
    for(int i=1;i<=n;i++) {
        if(dg[i]==0) {
            q.push(i);
            visit[i]=true;
        }
        
    }

    while(!q.empty()) {
        int cur=q.front();
        q.pop();

        ans.push_back(cur);

        for(int i=0;i<v[cur].size();i++) {
            int nx=v[cur][i];
            if(visit[nx]) continue;

            dg[nx]--;
            if(dg[nx]==0) {
                q.push(nx);
                v[cur][i]=-1;
                visit[nx]=true;
            }
        }
    }
    
    if(ans.size()==n) {
        for(auto it:ans) cout<<it<<'\n';
    }
    else cout <<0;
    
}
