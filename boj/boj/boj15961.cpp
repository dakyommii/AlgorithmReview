//
//  boj15961.cpp
//  boj
//  memory: 25460 KB
//  time: 264 ms
//  Created by 다곰 on 2023/09/06.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n,d,k,c;
    cin >> n >> d >> k >> c;
    
    vector<int> sushi(n);

    for(int i=0;i<n;i++) {
        cin >> sushi[i];
    }
    
    int st=0,end=k-1;
    
    vector<int> dish(n,0);
    int cnt=0;
    for(int i=st;i<=end;i++) {
        if(dish[sushi[i]]==0) cnt++;
        dish[sushi[i]]++;
    }
    
    int ans=cnt;
    if(dish[c]==0) ans++;

    while(st<n) {
        // 첫번째 초밥 빼고 다음 초밥 넣기
        dish[sushi[st]]--;
        if(dish[sushi[st]]==0) cnt--;
        end++;
        if(end>=n) end-=n;
        
        dish[sushi[end]]++;
        if(dish[sushi[end]]==1) cnt++;

        st++;
        
        // 쿠폰초밥 포함 확인
        if(dish[c]==0) {
            ans=max(ans,cnt+1);
        }
        else {
            ans=max(ans,cnt);
        }
        
        // k+1 이면 탐색 중단
        if(ans==k+1) break;
    }
    
    cout << ans << endl;
}

/*
k개의 조합 먹어보기 -> 회전가능하기 때문에 st가 초밥 개수보다 작을 경우까지
set로 가짓수 세기
가짓수가 최대일 경우 -> 추가 초밥을 포함하는지 확인해서 ans 갱신
가짓수의 가장 최대는 K+1이므로 k+1 존재하면 탐색 중단
*/

