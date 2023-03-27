//
//  boj14567.cpp
//  boj
//  memeory: 8296 KB
//  time: 152 ms
//  Created by 다곰 on 2023/03/27.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    
    vector<int> dp(n+1,1);
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        pq.push({a,b});
    }
    
    while(!pq.empty()) {
        int a=pq.top().first;
        int b=pq.top().second;
        pq.pop();
        
        if(dp[b]-1<dp[a]) dp[b]=dp[a]+1;
    }
    
    for(int i=1;i<=n;i++) {
        cout << dp[i] << " ";
    }
}

