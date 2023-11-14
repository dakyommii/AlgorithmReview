//
//  boj5622.cpp
//  boj
//  memory: 2024 KB
//  time: 0 ms
//  Created by 다곰 on 2023/11/14.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int ans=0;
    for(int i=0;i<s.size();i++) {
        if(s[i]>='A' && s[i]<='C') ans+=3;
        else if(s[i]>='D' && s[i]<='F') ans+=4;
        else if(s[i]>='G' && s[i]<='I') ans+=5;
        else if(s[i]>='J' && s[i]<='L') ans+=6;
        else if(s[i]>='M' && s[i]<='O') ans+=7;
        else if(s[i]>='P' && s[i]<='S') ans+=8;
        else if(s[i]>='T' && s[i]<='V') ans+=9;
        else if(s[i]>='W' && s[i]<='Z') ans+=10;
    }
    
    cout << ans;
}

/*
시계방향으로 숫자를 금속핀에 맞추기
숫자1은 2초 걸리고 1보다 큰 수는 1초씩 더 걸림

*/
