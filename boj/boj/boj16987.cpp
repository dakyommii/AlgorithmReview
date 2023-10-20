//
//  main.cpp
//  boj16987
//  memory: 2020 KB
//  time: 80 ms
//  Created by 다곰 on 2023/10/20.
//

#include <iostream>
#include <vector>
using namespace std;

int s[8]={0};
int w[8]={0};
int n,ans=0;
void dfs(int c) {
    if(c==n) {
        int cnt=0;
        for(int i=0;i<n;i++) {
            if(s[i]<=0) cnt++;
        }
        ans=max(ans,cnt);
        return;
    }
    
    // 현재가 깨지면 다음 계란 깨기
    if(s[c]<=0) {
        dfs(c+1);
    }
    else {
        bool broke=false;   // 모든 계란이 깨졌는지 확인하기 위한 flag
        for(int i=0;i<n;i++) {
            // 상대가 깨지면 다음 상대 깨기
            if(i==c||s[i]<=0) continue;

            s[c]-=w[i];
            s[i]-=w[c];
            
            broke=true;
            
            dfs(c+1);
            
            s[c]+=w[i];
            s[i]+=w[c];
        }
        
        // 모든 계란이 깨짐 -> 이전까지의 카운트를 정답으로 갱신하기 위해 탐색 종료
        // 이렇게 해야지 카운트를 갱신할 수 있음
        if(!broke) dfs(n);
    }
    
    
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> s[i] >> w[i];
    }
    
    dfs(0);
    
    cout << ans;
}

/*
틀린 제출을 할 때마다 턱걸이를 5회
각 계란의 내구도는 상대 계란의 무게만큼 깎이게 된다
내구도가 0 이하가 되는 순간 계란은 깨지게 된다.
왼->오로 깨기
마지막 계란을 깰때마다 최대값 갱신
*/
