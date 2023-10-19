//
//  boj3226.cpp
//  boj
//  memory: 2024 KB
//  time: 0 ms
//  Created by 다곰 on 2023/10/19.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt=0;
    while(n--) {
        string s;
        int m;
        cin >> s >> m;
        
        int st=stoi(s.substr(0,2))*60+stoi(s.substr(3));

        // 시작 시간 7~19
        int ans=0;
        if(st>=7*60 && st<=19*60) {
            
            // 19 넘어서 종료
            if(st+m>19*60) ans=(19*60-st)*10+((st+m)-19*60)*5;
            else ans=m*10;
        }
        // 시작 시간 19~7
        else {
            // 시작 시간 24시 이전
            if(st>19*60&&st<24*60) {
                if(st+m>=24*60) ans=((24*60-st)+((st+m)-24*60))*5;
                else ans=m*5;
            }
            // 아님
            else {
                // 7 넘어서 종료
                if(st+m>7*60) ans=(7*60-st)*5+((st+m)-7*60)*10;
                else ans=m*5;
            }
        }

        cnt+=ans;
    }
    
    cout << cnt;
}

/*
7~19 1분 10원
19~7: 1분 5
전화시작 시간, 통화시간 주어짐 전화요금 구하기
*/
