//
//  boj2960.cpp
//  boj
//  memory: 2020 KB
//  time: 0 ms
//  Created by 다곰 on 2023/02/21.
//

#include <iostream>
#include <cstring>
using namespace std;

bool check(int k) {
    for(int i=2;i<k;i++) {
        if(k%i==0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k,p;
    int cnt=0,cur=2;
    cin >> n >> k;
    
    bool visit[1001];
    memset(visit, 0, sizeof(visit));
    
    while(cnt<n-1 && cnt!=k) {
        //if(cnt==k) break;
        if(visit[cur]) {
            cur++;
            continue;
        }
        
        if(check(cur)) {
            p=cur;
            visit[p]=true;
            cnt++;
//            cout << "소수 " << p << endl;
        }
        for(int i=2;i<=n/cur;i++) {
            if(cnt==k) break;
            p=cur*i;
            if(visit[p]) continue;
            visit[p]=true;
            cnt++;
//            cout << p << endl;
        }
        cur++;
    }
    
    cout << p;
}
