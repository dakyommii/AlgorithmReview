//
//  boj9465.cpp
//  boj
//  memory: 3464 KB
//  time: 300 ms
//  Created by 다곰 on 2023/03/30.
//

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    int board[2][100001];
    int dp[2][100001];
    while(t--) {
        int n;
        cin >> n;
        memset(board,0,sizeof(board));
        memset(dp,0,sizeof(dp));
        
        dp[0][0]=board[0][0];
        dp[1][0]=board[1][0];
        for(int i=1;i<n;i++) {
            // 대각선 반대
            dp[0][i]=max(dp[0][i],board[0][i]+dp[1][i-1]);
            dp[1][i]=max(dp[1][i],board[1][i]+dp[0][i-1]);
            
            // 2칸 대각선 반대
            if(i==1) continue;
            dp[0][i]=max(dp[0][i],board[0][i]+dp[1][i-2]);
            dp[1][i]=max(dp[1][i],board[1][i]+dp[0][i-2]);
        }
        
        cout << max(dp[1][n-1],dp[0][n-1]) << endl;
        
    }
}

/*
50 40  200 140 250
30 100 120 210 260
*/
