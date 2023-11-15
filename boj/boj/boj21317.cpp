//
//  boj21317.cpp
//  boj
//  memory: 2020 KB
//  time: 0 ms
//  Created by 다곰 on 2023/11/14.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,k;
    bool used=false;
    cin >> n;
    int jump[22][2];
    int dp[22][2];
    for(int i=1;i<n;i++) {
        cin >> jump[i][0] >> jump[i][1];
    }
    
    cin >> k;
    
    for(int i=1;i<=n;i++) {
        dp[i][0]=1e9;
        dp[i][1]=1e9;
    }
    
    dp[1][0]=0;
    dp[2][0]=jump[1][0];
    dp[3][0]=min(jump[1][1],dp[2][0]+jump[2][0]);
    
    for(int i=4;i<=n;i++) {
        // 이전에 매우 큰 점프 안 함
        dp[i][0]=min(dp[i-2][0]+jump[i-2][1],dp[i-1][0]+jump[i-1][0]);
        // 이전에 매우 큰 점프 사용하거나 이번에 사용
        dp[i][1]=min(min(dp[i-2][1]+jump[i-2][1],dp[i-1][1]+jump[i-1][0]),dp[i-3][0]+k);
    }
    
    cout << min(dp[n][0],dp[n][1]);
}

/*
바로 다음으로 점프=작은 점프
하나 건너뛰기=큰 점프
두개 건너뛰기=매우 큰 점프 -> 한번만 할 수 있음. K 에너지 소비
에너지 최솟값 구하기
dp는 현재까지 도달하기까지 에너지 최소값
dp[1]=0;
dp[2]=1에서 작은 점프=1
dp[3]=1에서 큰 점프(2), 2에서 작은 점프(1+2)=2
dp[4]=2에서 큰 점프(1+3), 3에서 작은 점프(2+4), 1에서 매우 큰 점프(4)=>1+3
dp[5]=3에서 큰 점프(2+5), 4에서 작은 점프(4+4), 2에서 매우 큰 점프(1+4)
*/
