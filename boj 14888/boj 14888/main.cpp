//
//  main.cpp
//  boj 14888
//
//  Created by 다곰 on 2021/09/13.
//

#include <iostream>
using namespace std;

int N, P, MN, MT, D;
int minn = 0, maxx = 0;
int A[100];

void sol(int p, int mn, int mt, int d, int idx, int rs) {
    //모든 연산자 사용해 A 수열 연산했을 때 최대, 최소 값 갱신하고 return
    if (idx == N) {
        //min, max 값 초기화
        if (minn == 0 && maxx == 0) minn = maxx = rs;
        else {
            //모든 연산자를 사용해서 연산하고 나면 최소, 최대값 판별 후 저장
            minn = min(minn, rs);
            maxx = max(maxx, rs);
            return;
        }
    }
        //덧셈
        if (p > 0) {
            p--;    //연산자 사용
            sol(p, mn, mt, d, idx +1, rs+A[idx]);
            p++;    //sol이 return됐을 때는 끝까지 연산자 사용해 연산한 경우이므로 backtracking 으로 이어서 다른 방법도 시도해보기 위해 다시 더해줌
        }
    
        //뺄셈
        if (mn > 0) {
            mn--;
            sol(p, mn, mt, d, idx+1, rs-A[idx]);
            mn++;
        }
    
        //곱셈
        if (mt > 0) {
            mt--;
            sol(p, mn, mt, d, idx+1, rs*A[idx]);
            mt++;
        }
    
        //나눗셈
        if (d > 0) {    //문제에서 어렵게 서술되었을 뿐 그냥 나눗셈 한다는 것. 음수, 양수 판별 불필요
            d--;
            sol(p, mn, mt, d, idx+1, rs/A[idx]);
            d++;
        }
    }

int main() {

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> P >> MN >> MT >> D;
    
    sol(P, MN, MT, D, 1, A[0]);
    
    cout << maxx << endl;
    cout << minn << endl;
    
}
