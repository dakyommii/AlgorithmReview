//
//  boj17626.cpp
//  boj
//  memory: 2264 KB
//  time: 12 ms
//  Created by 다곰 on 2023/03/21.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    
    vector<int> dp(n+1,0);
    vector<int> square;
    for(int i=1;i*i<=n;i++) {
        square.push_back(i*i);
        dp[i*i]=1;
    }

    for(int i=1;i<=n;i++) {
        if(dp[i]==1) continue;

        int mx=5;
        for(int j=0;j<square.size();j++) {
            if(square[j]>i) break;

            mx=min(mx,dp[i-square[j]]);
        }

        dp[i]=mx+1;

    }
    
    cout << dp[n];

}
