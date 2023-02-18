//
//  boj1735.cpp
//  boj
//  memory: 2020 KB
//  time: 0 ms
//  Created by 다곰 on 2023/02/18.
//

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}

int main() {
    int a1,a2,b1,b2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    
    // 최대공약수
    int g=gcd(a2*b2,a1*b2+b1*a2);

    cout << (a1*b2+b1*a2)/g << " " << (a2*b2)/g;
}

// 두 분모의 최소공배수로 통분
// 약분할 때는 분모와 분모의 최대공약수로 각각 나눠주기 -> 최대공약수가 1일 떄까지
// 최대공약수, 최소공배수는 재귀로 구하기
