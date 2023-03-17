//
//  boj11403.cpp
//  boj
//  memory: 2032 KB
//  time: 12 ms
//  Created by 다곰 on 2023/03/18.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct edge {
    int s;
    int e;
};

bool board[101][101];
vector<edge> origin;
void sol(int s, int e) {
    for(int i=0;i<origin.size();i++) {
        edge edg=origin[i];
        if(e==edg.s) {

            if (!board[s][edg.e]) {
                board[s][edg.e]=true;
                sol(s,edg.e);
            }
            
        }
    }
}

int main() {
//    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++){
            int k;
            cin >> k;
            if(k==1) {
                board[i][j]=true;
                origin.push_back({i,j});
            }
        }
    }
    
    for(int i=0;i<origin.size();i++) {
        edge edg=origin[i];
        sol(edg.s,edg.e);
    }
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(board[i][j]) cout << 1 << " ";
            else cout << 0 << " ";
        }
        cout << "\n";
    }
}
