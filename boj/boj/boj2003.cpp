//
//  boj2003.cpp
//  boj
//  Retry
//  memory: 2020 KB
//  time: 4 ms
//  Created by 다곰 on 2023/02/06.
//

#include <iostream>
using namespace std;

int main() {
    int n,m,cnt=0;
    int board[10001];
    cin >> n >> m;
    
    for(int i=0;i<n;i++) {
        cin >> board[i];
    }
    
    int start=0,end=0,sum=0;
    
    // end가 끝에 도달하는 시점의 부분합이 조건을 충족하지 못하면 더 이상 조건을 충족할 수 없는 것이기 때문에 end만 끝에 도달했는지 확인해도 ㄱㅊ
    while(end <=n) {
        
        // 조건보다 작으면 end 늘려주기: 부분합 키우기
        if(sum<m) sum+=board[end++];
        // 조건보다 크면 start 늘려주기: 부분합 줄이기
        else if(sum>=m) sum-=board[start++];
        
        if (sum==m) cnt++;
        
    }
    
    cout << cnt;
}
