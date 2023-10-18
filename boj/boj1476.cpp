//
//  boj1476.cpp
//  boj
//
//  Created by 다곰 on 2023/10/18.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    int e,s,m;
    cin >> e >> s >> m;

    int y=1;

    while(1) {
        if(((y-e)%15==0)&&((y-s)%28==0)&&((y-m)%19==0)) break;
        y++;
    }
    
    cout << y;
}

/*
e: 지구 1~15
s: 태양 1~28
m: 달 1~19
1년이 지나면 1씩 증가

1 2 3
지구=1,16,17
태양=2,30,38,
달= 3,22,41

지구 값에서 15씩 더한 값 을 지구, 태양, 달을 나눴을 때 나머지가 각각의 값과 같으면 정답

*/
