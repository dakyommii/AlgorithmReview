//
//  boj 1939.cpp
//  boj
//  memory: 5556 KB
//  time: 72 ms
//  Created by 다곰 on 2023/10/03.
//

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int,int>> bridge[10001];
bool visit[10001]={false};
int st,e;

bool sol(int cnt) {

    queue<int> q;
    q.push(st);
    visit[st]=true;
    
    bool arrived=false;
    while(!q.empty()) {
        int cur=q.front();
        
        q.pop();
        
        if(cur==e) {
            arrived=true;
            break;
        }
        
        for(int i=0;i<bridge[cur].size();i++) {
            int next=bridge[cur][i].first;
            int c=bridge[cur][i].second;
            
            if(!visit[next] && c>=cnt) {
                visit[next]=true;
                q.push(next);
            }
        }
    }
    
    if(arrived) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin >> n >>m;
   
    int right=-1;
    for(int i=0;i<m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        right=max(right,c);
        bridge[a].push_back({b,c});
        bridge[b].push_back({a,c});
    }
    
    cin >> st>>e;
    
    int left=1;
    int ans=-1;
    while(left<=right) {
        memset(visit, false, sizeof(visit));
        int mid=(left+right)/2;
        
        if(sol(mid)) {
            left=mid+1;
            ans=mid;
        }
        else right=mid-1;
    }
    
    cout << ans;
    
}
