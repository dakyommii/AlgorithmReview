//
//  boj15486.cpp
//  boj
//  memory: 196000 KB
//  time: 216 ms
//  Created by 다곰 on 2023/09/06.
//

#include <iostream>
#include <algorithm>
using namespace std;

int t[1500001];
int p[1500001];
int dp[1500001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    
    cin >> n;

    for(int i=1;i<=n;i++) {
        cin >> t[i] >> p[i];  //t,p
    }

    for(int i=1;i<=n;i++) {

        dp[i+t[i]]=max(dp[i+t[i]],dp[i]+p[i]);
        dp[i+1]=max(dp[i+1],dp[i]);
    }

    cout << dp[n+1] << endl;
}

/*
1: 0 dp[4]=10
2: 0 dp[7]=20
3: 0 dp[4]=10
4: 10 dp[5]=20
5: 10+20=30 dp[7]=15
6: 30
7:

1: 0
2: 0
3: 0
4: 0
5: 10
6: 9
7: 8
8: 7
9: 6
10: 10+10

1. 각 날짜부터 일을 시작하면 종료할 수 있는 날짜(dp)에 비용 저장 -> 현재 dp + 비용
2. 현재 날짜에 끝나는 일이 없으면 0
*/

