//
//  boj2156.cpp
//  boj
//  memory: 2020 KB
//  time: 4 ms
//  Created by 다곰 on 2023/04/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n+1,0);
    vector<int> dp(n+1,0);
    
    for(int i=1;i<=n;i++) {
        cin >> v[i];
    }
    
    dp[0]=0;
    dp[1]=v[1];
    dp[2]=v[1]+v[2];
    
    for(int i=3;i<=n;i++) {
        dp[i]=max(max(v[i-1]+dp[i-3],dp[i-2])+v[i],dp[i-1]);
    }
    
    int ans=dp[n];
    cout << ans;
    return 0;
}

/*
dp[1]=v[1]
dp[2]=v[1]+v[2]
dp[3]=max(v[2],v[1])+v[3]
dp[4]=max(v[3]+dp[1],dp[2])+v[4]
*/

