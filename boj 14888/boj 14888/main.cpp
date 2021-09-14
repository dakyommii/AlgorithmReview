//
//  main.cpp
//  boj 14888
//
//  Created by 다곰 on 2021/09/13.
//

#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;

int N;
int minn = INF, maxx = -INF;
int A[12], op[4];

void sol(int idx, int rs) {
    //모든 연산자 사용해 A 수열 연산했을 때 최대, 최소 값 갱신하고 return
    if (idx == N) {
        //모든 연산자를 사용해서 연산하고 나면 최소, 최대값 판별 후 저장
        minn = min(minn, rs);
        maxx = max(maxx, rs);
        return;
    }
        //덧셈
        if (op[0] > 0) {
            op[0]--;    //연산자 사용
            sol(idx+1, rs+A[idx]);
            op[0]++;    //sol이 return됐을 때는 끝까지 연산자 사용해 연산한 경우이므로 backtracking 으로 이어서 다른 방법도 시도해보기 위해 다시 더해줌
        }
    
        //뺄셈
        if (op[1] > 0) {
            op[1]--;
            sol(idx+1, rs-A[idx]);
            op[1]++;
        }
    
        //곱셈
        if (op[2] > 0) {
            op[2]--;
            sol(idx+1, rs*A[idx]);
            op[2]++;
        }
    
        //나눗셈
        if (op[3] > 0) {    //문제에서 어렵게 서술되었을 뿐 그냥 나눗셈 한다는 것. 음수, 양수 판별 불필요
            op[3]--;
            sol(idx+1, rs/A[idx]);
            op[3]++;
        }
    }

int main() {

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < 4; i++) cin >> op[i];
    
    sol(1, A[0]);
    
    cout << maxx << endl;
    cout << minn << endl;
    
}
