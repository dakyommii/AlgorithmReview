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

void sol(int ey, int ex, int fy, int fx) {
    //끝 도달하면 return
    if(ey == N-1 && ex == N-1) {
        cnt++;
        return;
    }
    
    //현재 가로
    if(ey == fy && ex-1 == fx) {
        //세로 이동
        if(ex+1 < N && a[ey][ex+1] == 0) sol(ey, ex+1, ey, ex);
        
        //대각선 이동
        if(ey+1 < N && ex+1 < N)
            if(a[ey+1][ex+1] == 0 && a[ey+1][ex] == 0 && a[ey][ex+1] == 0) sol(ey+1, ex+1, ey, ex);
        
    }
    //현재 세로
    if(ey == fy+1 && ex == fx){
        //가로 이동
        if(ey +1< N && a[ey+1][ex] == 0) sol(ey+1, ex, ey, ex);

        //대각선 이동
        if(ey +1< N && ex +1< N)
            if(a[ey+1][ex+1] == 0 && a[ey+1][ex] == 0 && a[ey][ex+1] == 0) sol(ey+1, ex+1, ey, ex);
            
    }
    //현재 대각선
    if(ey==fy+1 && ex==fx+1) {
        //가로 이동
        if(ex +1< N && a[ey][ex+1] == 0) sol(ey, ex+1, ey, ex);
        
        //세로 이동
        if(ey +1< N && a[ey+1][ex] == 0) sol(ey+1, ex, ey, ex);

        //대각선 이동
        if(ey+1 < N && ex +1< N)
            if(a[ey+1][ex+1] == 0 && a[ey+1][ex] == 0 && a[ey][ex+1] == 0) sol(ey+1, ex+1, ey, ex);


    }

   
}

int main() {
    cin >> N;
    //웬만하면 i가 0에서 시작하도록 하기
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) cin >> a[i][j];
    }

    //변수를 선언하고 파라미터로 삽입하는 것이 boj 통과에 큰 요소
    int ey = 0, ex = 1, fy = 0, fx = 0;
    sol(ey,ex,fy,fx);
    cout << cnt;
}
