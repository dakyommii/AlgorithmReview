//
//  boj2096.cpp
//  boj
//  Retry
//  memory: 3072 KB
//  time: 60 ms
//  Created by 다곰 on 2023/02/06.
//

#include <iostream>
using namespace std;

int main() {
    int board[100001][3];
    int mx[2][3];
    int mn[2][3];
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) {
            cin >> board[i][j];
        }
    }
    
    // 1열의 최대값, 최소값을 board 1열 값으로 초기화
    for (int i=0; i<3; i++) {
        mx[0][i]=board[0][i];
        mn[0][i]=board[0][i];
    }

    for(int i=1;i<n;i++) {
        int x1=mx[0][0];
        int x2=mx[0][1];
        int x3=mx[0][2];
        
        mx[1][0]=max(x1,x2)+board[i][0];
        mx[1][1]=max(x1,max(x2,x3))+board[i][1];
        mx[1][2]=max(x2,x3)+board[i][2];
        
        int n1=mn[0][0];
        int n2=mn[0][1];
        int n3=mn[0][2];
        
        mn[1][0]=min(n1,n2)+board[i][0];
        mn[1][1]=min(n1,min(n2,n3))+board[i][1];
        mn[1][2]=min(n2,n3)+board[i][2];
        
        // 이번 열 최대값, 최소값 계산한 이후에는 앞 열로 위치 옮겨주기
        for (int j=0; j<3; j++) {
            mx[0][j]=mx[1][j];
            mn[0][j]=mn[1][j];
        }
    }

    int maxScore=max(mx[0][0],max(mx[0][1],mx[0][2]));
    int minScore=min(mn[0][0],min(mn[0][1],mn[0][2]));
    
    cout << maxScore << " " << minScore;
}
