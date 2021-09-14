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

    while ((p + mn + mt + d ) > 0) {
        if (idx >= N) break;
        //덧셈
        if (p > 0) {
            cout << "덧" << endl;
            rs += A[idx];
            sol(--p, mn, mt, d, ++idx, rs);
            
         
            
        }
        //뺄셈
        if (mn > 0) {
            cout << "뺄" << endl;
            rs -= A[idx];
            
            sol(p, --mn, mt, d, ++idx, rs);
          
           
            
        }
        //곱셈
        if (mt > 0) {
            cout << "곲" << endl;
            rs *= A[idx];
            
            sol(p, mn, --mt, d, ++idx, rs);
          
            
        }
        //나눗셈
        if (d > 0) {
            cout << "나" << endl;
            if (rs < 0) {   //음수를 양수로 나눌 때 양수로 바꾸고 몫을 음수로 바꾸기
                rs = -rs / A[idx];
                rs -= rs;
            }
            else  rs /= A[idx];
            
            sol(p, mn, mt, --d, ++idx, rs);
          
        }
        
    }
    
    if (minn == 0 && maxx == 0) minn = maxx = rs;
    else {
        //모든 연산자를 사용해서 연산하고 나면 최소, 최대값 판별 후 저장
        minn = min(minn, rs);
        cout << "민"<< endl;
        maxx = max(maxx, rs);
        cout << "맧" << endl;
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
