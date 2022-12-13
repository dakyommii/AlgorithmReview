//
//  boj1244.cpp
//  boj
//  memory: 2020 KB
//  time: 0 ms
//  Created by 다곰 on 2022/12/13.
//

#include <iostream>

using namespace std;

int main() {
    int s,st;
    bool onoff[100];
    
    cin >> s;
    for(int i=1;i<=s;i++) {
        int k;
        cin >> k;
        onoff[i]=k;
    }
    
    cin >> st;
    
    while(st--) {
        int g, num;
        cin >> g >> num;
        
        if(g==1) {
            for(int i=1;i*num<=s;i++) onoff[i*num]=!onoff[i*num];

        }
        else {
            onoff[num]=!onoff[num];
            int idx=1;
            while(num-idx>0 && num+idx<=s) {
                if(onoff[num-idx]==onoff[num+idx]) {
                    onoff[num-idx]=!onoff[num-idx];
                    onoff[num+idx]=!onoff[num+idx];
                    idx++;
                }
                else break;
            }
        }
    }
    
    for(int i=1;i<=s;i++) {
        cout << onoff[i];
        if(i!=s) cout << " ";
        if(i%20==0) cout << endl;
    }
}

/*
남: 자기가 받은 수의 배수인 스위치 상태 바꾸기
여: 자기 번호 스위치 중심으로 좌우 대칭이 성립하는 범위까지 스위치 상태 바꾸기

input
1. 스위치 개수: s
2. 각 스위치 상태 -> bool onoff[100];
3. 학생 수: st
4. 성별: g, 받은 수: num

output
스위치 상태 return
    
1. 남자(1): 배수 인덱스의 스위치 바꾸기
2. 여자(2):
    1) 해당 숫자 인덱스 스위치 바꾸기
    2) 좌우대칭 성립하면 해당 인덱스 스위치 바꾸기
    3) 성립하지 않으면 break
*/
    
