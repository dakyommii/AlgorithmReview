//
//  boj2579.cpp
//  boj
//  memroy: 2020 KB
//  time: 0 ms
//  Created by 다곰 on 2023/01/20.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int stair[301];
    int dp[301];
    
    for(int i=1;i<=n;i++) {
        cin >> stair[i];
    }
    
    dp[1]=stair[1];
    dp[2]=stair[1]+stair[2];
    
    for (int i=3; i<=n; i++) {
        dp[i]=max(dp[i-2], stair[i-1]+dp[i-3])+stair[i];
    }
    
    cout << dp[n];
}
