//
//  boj10451.cpp
//  boj
//  memory: 2020 KB
//  time: 192 ms
//  Created by 다곰 on 2022/10/29.
//

#include <iostream>
#include <vector>

using namespace std;

int dfs(int strt,vector<bool> &visit, vector<int> &v) {
    visit[strt]=true;
    if(v[strt]==strt) return strt;
    else if(visit[v[strt]]) return v[strt];
    else return dfs(v[strt],visit,v);
}

int main() {
    int t,n;
    cin >> t;
    while(t--) {
        cin >> n;
        
        vector<int> v(n+1,-1);
        vector<bool> visit(n+1,false);
        for(int i=1;i<=n;i++) {
            int k;
            cin >> k;
            v[i]=k;
        }
        
        int cnt=0;
        for(int i=1;i<=n;i++) {
            if(!visit[i]) {
                if(dfs(i,visit,v)==i) cnt++;
            }
        }
        
        cout << cnt << endl;
    }
}
