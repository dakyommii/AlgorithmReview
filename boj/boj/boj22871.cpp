//
//  boj22871.cpp
//  boj
//  memory: 2212 KB
//  time: 60 ms
//  Created by 다곰 on 2023/08/11.
//

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int n;
long long dp[5001];
long long stone[5001];

long long go(int a) {
    if(a==n-1) return 0;
    long long& cur=dp[a];
    if(cur!=0) return cur;
    
    cur=1e10;
    for(int i=a+1;i<n;i++) {
        cur=min(cur,max(go(i),(i-a)*(1+abs(stone[i]-stone[a]))));
    }
    return cur;
}

int main() {
    
    cin >> n;
    
    for(int i=0;i<n;i++) {
        cin >> stone[i];
    }
    
    cout << go(0) << endl;
}
