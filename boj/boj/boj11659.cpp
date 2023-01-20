//
//  boj11659.cpp
//  boj
//  memory: 2288 KB
//  time: 40 ms
//  Created by 다곰 on 2023/01/20.
//

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    
    int sum[100001];
    
    for(int i=0;i<n;i++) {
        int k;
        cin >> k;
        sum[i+1]=sum[i]+k;
    }
    
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        cout <<sum[b]-sum[a-1] << '\n';
    }
}
