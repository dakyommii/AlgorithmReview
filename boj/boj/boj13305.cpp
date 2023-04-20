//
//  boj13305.cpp
//  boj
//  memory: 3588 KB
//  time: 20 ms
//  Created by 다곰 on 2023/04/20.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    long long cnt=1000000001,ans=0;
    cin >> n;
    vector<long long> dist(n-1);
    vector<long long> cost(n);
    
    for(int i=0;i<n-1;i++) {
        cin >> dist[i];
    }
    
    for(int i=0;i<n;i++) {
        cin >> cost[i];
    }
    
    for(int i=0;i<n-1;i++) {
        cnt=min(cnt,cost[i]);
        ans+=cnt*dist[i];
    }
    
    cout << ans;
}
