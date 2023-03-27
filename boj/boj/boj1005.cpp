//
//  boj1005.cpp
//  boj
//  memory: 2836 KB
//  time: 152 ms
//  Created by 다곰 on 2023/03/27.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> total;
vector<vector<int>> vertex;
vector<int> value;

void sol(int cur) {
    if(vertex[cur].size()==0) {
        total[cur]=value[cur];
        return;
    }
    
    for(int i=0;i<vertex[cur].size();i++) {
        int pre=vertex[cur][i];
        if(total[pre]==-1) sol(pre);
        if(total[cur]<total[pre]) total[cur]=total[pre];
    }
    
    total[cur]+=value[cur];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    
    while(t--) {
        total.clear();
        vertex.clear();
        value.clear();
        
        int n,k;
        cin >> n >> k;
        
        total.resize(n+1,-1);
        value.resize(n+1);

        for(int i=1;i<=n;i++) {
            cin >> value[i];
        }
        
        vertex.resize(n+1);
        for(int i=0;i<k;i++) {
            int x,y;
            cin >> x >> y;
            vertex[y].push_back(x);
        }
        
        int start;
        cin >> start;
        
        sol(start);

        cout << total[start] << '\n';
    }
}
