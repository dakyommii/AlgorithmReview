//
//  boj14719.cpp
//  boj
//  memory: 2144 KB
//  time: 0 ms
//  Created by 다곰 on 2023/11/02.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h,w;
    bool board[501][501]={false};
    cin >> h >> w;
    for(int i=0;i<w;i++) {
        int l;
        cin >> l;
        for(int j=0;j<l;j++) {
            board[j][i]=true;
        }
    }
    
    int ans=0;
    
    for(int i=0;i<h;i++) {
        int k=-1;

        for(int j=0;j<w;j++) {
            if(board[i][j]) {
                if(k!=-1) ans+=(j-k-1);
                k=j;
            }
        }
    }
    
    cout << ans;
}
// 모든 행을 돌면서 고일 수 있는 공간이 있는지 확인
// 첫번째 벽을 만나면 다음 벽을 만날 때까지 공간이 얼마나 있는지 확인
// 다음 벽이 있으면 지금까지 카운트된 공간 저장
    //다음 벽이 없으면 저장하지 않음
