//
//  boj1890.cpp
//  boj
//  memory: 2060 KB
//  time: 0 ms
//  Created by 다곰 on 2023/03/31.
//

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long board[101][101];
    long long dp[101][101];
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> board[i][j];
        }
    }
    
    dp[0][0]=1;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int jump=board[i][j];
            if(jump==0) continue;
            
            if(i<n-1 && i+jump<n) dp[i+jump][j]+=dp[i][j];
            if(j<n-1 && j+jump<n) dp[i][j+jump]+=dp[i][j];
        }
    }
    
    
    cout << dp[n-1][n-1];
    
}
