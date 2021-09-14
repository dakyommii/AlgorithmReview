//
//  main.cpp
//  boj 17070
//
//  Created by 다곰 on 2021/09/14.
//

#include <iostream>
using namespace std;
int N, a[16][16];
int cnt = 0;

void sol(int c1, int r1, int c2, int r2) {
    //끝 도달하면 return
    if(c2 == N && r2 == N) {
        cnt++;
        return;
    }
    
    //현재 가로
    if(r1 == r2) {
        //가로 이동
        if(c2 < N && a[c2+1][r2] == 0) {
            c1++; c2++;
            sol(c1, r1, c2, r2);
            c1--; c2--;
        }
        //대각선 이동
        if((c2 < N && r2 < N) && (a[c2+1][r2+1] == 0 && a[c2+1][r2] == 0 && a[c2][r2+1] == 0)) {
            c1++; c2++; r2++;
            sol(r1, c1, r2, c2);
            c1--; c2--; r2--;
        }
        //이동 불가
        else return;
        
    }
    //현재 세로
    else if(c1 == c2){
        //세로 이동
        if(r2 < N && a[c2][r2+1] == 0) {
            r1++; r2++;
            sol(c1, r1, c2, r2);
            r1--; r2--;
        }
        //대각선 이동
        if((c2 < N && r2 < N) && (a[c2+1][r2+1] == 0 && a[c2+1][r2] == 0 && a[c2][r2+1] == 0)) {
            r1++; c2++; r2++;
            sol(c1, r1, c2, r2);
            r1--; c2--; r2--;
        }
        //이동 불가
        else return;
    }
    //현재 대각선
    else {
        //가로 이동
        if(c2 < N && a[c2+1][r2] == 0) {
            c1++; r1++; c2++;
            sol(c1, r1, c2, r2);
            c1--; r1--; c2--;
        }
        //세로 이동
        if(r2 < N && a[c2][r2+1] == 0) {
            c1++; r1++; r2++;
            sol(c1, r1, c2, r2);
            c1--; r1--; r2--;
        }
        //대각선 이동
        if((r2 < N && c2 < N) && (a[r2+1][c2+1] == 0 && a[r2+1][c2] == 0 && a[r2][c2+1] == 0)) {
            c1++; r1++; c2++; r2++;
            sol(c1, r1, c2, r2);
            c1--; r1--; c2--; r2--;
        }
        //이동 불가
        else return;
    }
   
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) cin >> a[j][i];
    }

    sol(1,1,2,1);
    cout << cnt;
}
