//
//  boj1915.cpp
//  boj
//  time: 12 ms
//  memory: 5816 KB
//  Created by 다곰 on 2023/01/23.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    int n,m,ans=0;
    int dp[1001][1001];
    cin >> n >> m;
    
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        for(int j=0;j<m;j++) {
            dp[i][j]=s[j]-'0';
            if(dp[i][j]==1) ans=1;
        }

    }
    
    for(int i=1;i<n;i++) {
        for(int j=1;j<m;j++) {
            if(dp[i][j]!=0) {
                dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                ans=max(ans,dp[i][j]);
            }
            
        }
    }
    
    cout << ans*ans;

}
