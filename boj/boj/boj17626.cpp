//
//  boj17626.cpp
//  boj
//  memory: 2264 KB
//  time: 12 ms
//  Created by 다곰 on 2023/03/21.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> dp(n+1,0);
    dp[1]=1;
    for(int i=2;i<=n;i++) {
        int mn=1e9;
        for(int j=1;j*j<=i;j++) {
            int c=i-j*j;
            mn=min(mn,dp[c]);
        }
        dp[i]=mn+1;
    }
    
    cout << dp[n];
}
