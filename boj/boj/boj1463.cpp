//
//  boj1463.cpp
//  boj
//  memory: 5928 KB
//  time: 4 ms
//  Created by 다곰 on 2023/10/24.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1,0);
    
    dp[1]=0;
    for(int i=2;i<=n;i++) {
        int mn=1e9;
        if(i%2==0) mn=min(mn,dp[i/2]);
        if(i%3==0) mn=min(mn,dp[i/3]);

        mn=min(mn,dp[i-1]);

        dp[i]=mn+1;
    }
    cout << dp[n];
}
