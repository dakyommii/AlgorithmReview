//
//  boj2056.cpp
//  boj
//  memory: 9776 KB
//  time: 288 ms
//  Created by 다곰 on 2023/11/17.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >>n;

    vector<int> time(n+1,0);
    vector<int> dp(n+1,0);
    vector<int> v[10001];
    queue<int> q;

    for(int i=1;i<=n;i++) {
        int c;
        cin >> time[i] >> c;
        if(c==0) {
            q.push(i);
            dp[i]=time[i];
            continue;
        }
        
        while(c--) {
            int k;
            cin >> k;
            v[k].push_back(i);
        }
    }
    
    
    while(!q.empty()) {
        int cur=q.front();
        q.pop();
        
        for(int i=0;i<v[cur].size();i++) {
            int nx=v[cur][i];
            
            if(dp[nx]<time[nx]+dp[cur]) {
                dp[nx]=time[nx]+dp[cur];
                q.push(nx);
            }
        }
    }
    
    cout << *max_element(dp.begin()+1, dp.end());
}

// 해당 작업 소요시간, 선행 작업 개수, 선행 작업 입력

