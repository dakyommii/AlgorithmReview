//
//  boj11660.cpp
//  boj
//  memory: 6004 KB
//  time: 136 ms
//  Created by 다곰 on 2023/01/20.
//

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    
    int board[1025][1025];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int k;
            cin >> k;
            board[i][j]=k+board[i-1][j]+board[i][j-1]-board[i-1][j-1];
        }
    }
    
    for(int i=0;i<m;i++) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        cout << board[x2][y2]-(board[x1-1][y2]+board[x2][y1-1])+board[x1-1][y1-1] << '\n';
    }
}
