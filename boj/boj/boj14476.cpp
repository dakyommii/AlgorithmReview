//
//  boj14476.cpp
//  boj
//  memory: 13620 KB
//  time: 164 ms
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
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,lgcd[1000010],rgcd[1000010],v[1000010];
    cin >> n;
    
    for(int i=1;i<=n;i++) {
        cin >> v[i];
    }

    for (int i=1; i<=n; i++) lgcd[i]=gcd(v[i],lgcd[i-1]);
    for(int i=n;i>=1;i--) rgcd[i]=gcd(v[i],rgcd[i+1]);
    
    int dNum=-1;
    int bigGcd=0;
    for (int i=1; i<=n; i++) {
        int gcdRes=gcd(lgcd[i-1], rgcd[i+1]);
        if (bigGcd<gcdRes && (v[i]%gcdRes!=0)) {
            bigGcd=gcdRes;
            dNum=v[i];
        }
    }
    
    if (dNum==-1) cout << -1;
    else cout << bigGcd << " " << dNum;
}

// n 개의 정수 중에서 하나의 숫자를 뺴서 최대공약수 찾기
// 이때의 최대공약수가 k의 약수가 되면 안됨
