//
//  boj2630.cpp
//  boj
//  memory: 2084 KB
//  time: 4 ms
//  Created by 다곰 on 2023/11/13.
//

#include <iostream>
#include <vector>
using namespace std;

int board[128][128];
int w=0,b=0,t;

int chk(int x,int y,int len) {
    int c=board[x][y];
    for(int i=0;i<len;i++) {
        for(int j=0;j<len;j++) {
            if(board[x+i][y+j]!=c) return -1;
        }
    }
    
    return c;
}

void dfs(int x, int y, int len) {
    int c=chk(x,y,len);
    if(c==0) {
        w++;
        return;
    }
    else if(c==1) {
        b++;
        return;
    }
    
    dfs(x,y,len/2);
    dfs(x+len/2,y,len/2);
    dfs(x,y+len/2,len/2);
    dfs(x+len/2,y+len/2,len/2);
    
}

int main() {
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) cin >> board[i][j];
    }
    
    t=n;
    dfs(0,0,n);
    
    cout << w << '\n';
    cout << b << '\n';
}
// n*n 범위부터 시작해서 1*1 범위까지
// 1. 범위 내의 색상이 모두 같은지 확인
// 2. 모두 같은 것이 아니라면 분할
// 1= 파랑, 0=하양
