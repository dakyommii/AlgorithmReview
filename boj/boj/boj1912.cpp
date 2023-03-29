//
//  boj1912.cpp
//  boj
//  memory: 2804 KB
//  time: 8 ms
//  Created by 다곰 on 2023/03/29.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    
    vector<int> num(n+1);
    for(int i=1;i<=n;i++) {
        cin >> num[i];
    }

    vector<int> dp(n+1);
    int ans=INT_MIN;
    for(int i=1;i<=n;i++) {
        dp[i]=max(dp[i-1]+num[i],num[i]);
        ans=max(ans,dp[i]);
    }
    
    cout << ans;
}
