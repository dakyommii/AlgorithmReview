//
//  boj21318.cpp
//  boj
//  memory: 2804 KB
//  time: 40 ms
//  Created by 다곰 on 2023/11/17.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,q;
    cin >> n;
    vector<int> dif(n+1);
    vector<int> dp(n+1,0);
    
    for(int i=1;i<=n;i++) {
        cin >> dif[i];
        
        if(dif[i-1]>dif[i]) dp[i-1]++;
        dp[i]=dp[i-1];
    }
    
    cin >> q;
    
    for(int i=0;i<q;i++) {
        int s,e;
        cin >> s >> e;
        cout << dp[e-1]-dp[s-1] <<'\n';
    }
    
}

// 지금 연주하는 악보가 바로 다음에 연주할 악보보다 어렵다면 실수
