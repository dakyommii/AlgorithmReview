//
//  boj22869.cpp
//  boj
//  memory: 2020 KB
//  time: 16 ms
//  Created by 다곰 on 2023/11/15.
//

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n,k;
    int a[5001];
    bool visit[5001]={false};
    cin >> n >> k;
    
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    
    visit[1]=true;
    for(int i=2;i<=n;i++) {
        for(int j=i-1;j>=1;j--) {
            if(!visit[j]) continue;
            
            if((i-j)*(1+abs(a[j]-a[i]))<=k) {
                visit[i]=true;
                break;
            }
        }
    }
    
    if(visit[n]) cout << "YES";
    else cout << "NO";
}

/*
dp[0]
*/
