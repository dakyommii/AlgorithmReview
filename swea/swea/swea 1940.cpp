//
//  swea 1940.cpp
//  swea
//  memory: 13,372 KB
//  time: 17 ms
//  Created by 다곰 on 2022/11/19.
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
        int cur=0;
        int ans=0;
        while (n--) {
            int com, spd;
            cin >> com;
            if (com==0) {
                ans+=cur;
                continue;
            }
            cin >> spd;
            
            if(com==1) cur+=spd;
            else {
                cur-=spd;
                if(cur<0) cur=0;

            }
            ans+=cur;

        }

        cout << "#" << test_case << " " << ans << endl;
        test_case++;
    }
    
    return 0;
}
//
//0: 유지
//1: 가속
//2: 감속
//
//최종적으로 이동한 거리 계산
//초기 속도: 0
//속도가 음수가 되면 그냥 0

