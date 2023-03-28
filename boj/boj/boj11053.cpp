//
//  boj11053.cpp
//  boj
//  memory: 2020 KB
//  time: 0 ms
//  Created by 다곰 on 2023/03/28.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int dp[1001]={};
    int a[1001]={};
    cin >> n;
   
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    
    dp[1]=1;
    int ans=1;
    for(int i=2;i<=n;i++) {
        for(int j=1;j<i;j++) {
            if(a[j]<a[i] && dp[j]>dp[i]) dp[i]=dp[j];
        }
        dp[i]++;
        ans=max(ans,dp[i]);
    }
    
    cout << ans;
}
