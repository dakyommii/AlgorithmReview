//
//  boj2839.cpp
//  boj
//
//  Created by 다곰 on 2023/03/21.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1,-1);
    
    dp[3]=1;
    dp[5]=1;
    
    if(n<6) {
        cout << dp[n];
        exit(0);
    }
        
    for(int i=6;i<=n;i++) {
        if(dp[i-5]!=-1) dp[i]=dp[i-5]+1;
        else if(dp[i-3]!=-1) dp[i]=dp[i-3]+1;
        else dp[i]=-1;
    }
    
    cout << dp[n];
}
