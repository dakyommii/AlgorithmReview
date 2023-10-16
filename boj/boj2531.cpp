//
//  boj2531.cpp
//  boj
//  memory: 2020 KB
//  time: 8 ms
//  Created by 다곰 on 2023/10/16.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,d,k,c;
    int visit[3001]={0};
    cin >> n >> d >> k >> c;
    
    vector<int> sushi(n);
    bool cp=false;
    for(int i=0;i<n;i++) {
        cin >> sushi[i];
    }
    
    int st=0,e=k-1;
    
    int cnt=0;
    for(int i=0;i<k;i++) {
        if(visit[sushi[i]]==0) cnt++;
        visit[sushi[i]]++;
    }
    
    int ans=cnt;
    if(visit[c]==0) ans+=1;

    while(st<n) {
        if(st==0) {
            st++;
            e++;
            continue;
        }
        
        // 초밥 빼기
        visit[sushi[(st-1)%n]]--;
        if(visit[sushi[(st-1)%n]]==0) cnt--;
        
        // 초밥 더하기
        if(visit[sushi[e%n]]==0) cnt++;
        visit[sushi[e%n]]++;
        
        // 쿠폰 초밥 존재
        if(visit[c]==0) ans=max(cnt+1,ans); //접시에 없음
        else ans=max(ans,cnt);  // 접시에 있음
        
        // 갱신
        st++;
        e++;
        
    }
    
    cout << ans;
}




/*
임의 위치부터 k개 연속 먹으면 할인
쿠폰 -> 밸트에 없으면 만들어줌

최대=k+1
st,e 로 옮겨가면서 가짓수 세기 -> st가 끝까지 도달할 떄까지
존재 유무는 배열로 표시
*/
