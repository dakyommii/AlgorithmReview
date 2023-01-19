//
//  boj11404.cpp
//  boj
//  time: 84 ms
//  memory: 2020 KB
//  Created by 다곰 on 2023/01/19.
//

#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int main() {
    int n,m,a,b,c;
    cin >> n >> m;
    
    vector<vector<int>> edge(n+1,vector<int>(n+1,INF));
    for(int i=1;i<=n;i++) {
        edge[i][i]=0;
    }
    
    for(int i=0;i<m;i++) {
        cin >> a >> b >> c;
        edge[a][b]=min(c, edge[a][b]);
    }
    

    for(int i=1;i<=n;i++) {
        for(int from=1;from<=n;from++) {
            for(int to=1;to<=n;to++) {
                if(from==i || to==i || from==to) continue;
                edge[from][to]=min(edge[from][to],edge[from][i]+edge[i][to]);
            }
        }
    }
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if (edge[i][j]==INF) {
                cout << 0 << " ";
            }
            else cout << edge[i][j] << " ";
        }
        cout << '\n';
    }
    
}
