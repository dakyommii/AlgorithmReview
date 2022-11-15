//
//  swea 1974.cpp
//  swea
//
//  Created by 다곰 on 2022/11/15.
//

#include<iostream>
#include <cstring>

using namespace std;

int main()
{
    int test_case=1;
    int T;

    cin>>T;

    while (T--) {
        int board[9][9];
        bool chk[10];
        
    
        
        int ans=1;
        // input & 가로 검증
        for (int i=0; i<9; i++) {
            memset(chk, false, sizeof(chk));
            for (int j=0; j<9; j++) {
                int k;
                cin >> k;
                board[i][j]=k;
                
                if (chk[k]) {

                    ans=0;
                    continue;
                }
                else chk[k]=true;
            }

            
        }
        
        // 세로 검증
        for (int i=0; i<9; i++) {
            memset(chk, false, sizeof(chk));
            for (int j=0; j<9; j++) {
                int k= board[j][i];
                
                if (chk[k]) {
                    ans=0;
                    continue;
                }
                else chk[k]=true;
            }
           
        }
        
        // 3by3 검증
        int dx[9]={0,0,0,1,1,1,2,2,2};
        int dy[9]={0,1,2,0,1,2,0,1,2};
        int xx[9]={0,0,0,3,3,3,6,6,6};
        int yy[9]={0,3,6,0,3,6,0,3,6};
        
        for (int i=0; i<9; i++) {
            memset(chk, false, sizeof(chk));
            for (int j=0; j<9; j++) {
                int nx=xx[i]+dx[j];
                int ny=yy[i]+dy[j];
                
                int k=board[nx][ny];
                
                if (chk[k]) {

                    ans=0;
                    continue;
                }
                else chk[k]=true;
            }
        }

        
        cout << "#" << test_case << " " << ans << endl;
        test_case++;
     //   cout << ans << endl;
    }
    
    return 0;
}



//* bool chk[10]; -> false로 초기화
//
//퍼즐 입력 받음
//
//1. 가로 검증
//2. 세로 검증
//3. 3*3 검증
//검증할 때마다 chk 초기화
//
//검증 시 해당 인덱스가 true 이면 return 0
//      해당 인덱스가 false 이면 true로 바꾸기
//끝까지 검증 완료하면 return 1
//


