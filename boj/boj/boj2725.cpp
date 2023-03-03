//
//  boj2725.cpp
//  boj
//  memory: 2024 KB
//  time: 20 ms
//  Created by 다곰 on 2023/03/01.
//

#include <iostream>
using namespace std;

int res[1001];

int gcd(int a, int b) {
    if (b==0) return a;
    else return gcd(b,a%b);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    res[1]=3;
    for (int i=2; i<=1000; i++) {
        int cnt=0;
        for (int j=1; j<i; j++) {
            if (gcd(i,j)==1) cnt++;
            res[i]=res[i-1]+cnt*2;
        }
    }
    
    int c;
    cin >> c;
    while(c--) {
        int n;
        cin >> n;
        
        cout << res[n] << '\n';
    }
}

/*
x가 0인 경우 1 count
y가 0인 경우 1 count

x, y 모두 1 이상일 경우에 한해
y/x 의 값을 set 에 추가
*/
