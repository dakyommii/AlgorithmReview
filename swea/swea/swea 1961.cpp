//
//  swea 1961.cpp
//  swea
//  memory: 13540 KB
//  time: 9ms
//  Created by 다곰 on 2022/11/16.
//

#include<iostream>

using namespace std;

int main()
{
    int test_case=1;
    int T;

    cin>>T;

    while (T--) {
        int n;
        cin >> n;
        
        int board[7][7];
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                int k;
                cin >> k;
                board[i][j]=k;
            }
        }
        
        int res90[7][7];
        int res180[7][7];
        int res270[7][7];
        
       // 90도
        int nx=0,ny=0;
        for (int i=0; i<n; i++) {
            for (int j=n-1; j>=0; j--) {
                res90[nx][ny]=board[j][i];
                ny++;
            }
            ny=0;
            nx++;
        }
        
        // 180도
        nx=0;
        ny=0;
        for (int i=n-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                res180[nx][ny]=board[i][j];
                ny++;
            }
            ny=0;
            nx++;
        }
        
        //270도
        nx=0;
        ny=0;
        for (int i=n-1; i>=0; i--) {
            for (int j=0; j<n; j++) {
                res270[nx][ny]=board[j][i];
                ny++;
            }
            ny=0;
            nx++;
        }
        
        cout << "#" << test_case << endl;
        test_case++;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout << res90[i][j];
            }
            cout << " ";
            for (int j=0; j<n; j++) {
                cout << res180[i][j];
            }
            cout << " ";
            for (int j=0; j<n; j++) {
                cout << res270[i][j];
            }
            cout << endl;
        }

        
        
        
    }
    
    return 0;
}

//* int board[7][7];

//1. 90도 회전 -> 맨 왼쪽 하단 인덱스가 시작 인덱스가 됨
//2. 180도 회전 -> 맨 오른쪽 하단 인덱스가 시작 인덱스가 됨
//3. 270도 회전 -> 맨 오른쪽 상단 인덱스가 시작 인덱스가 됨


