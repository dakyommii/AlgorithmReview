//
//  boj3020.cpp
//  boj
//  memory: 3564 KB
//  time: 80 ms
//  Created by 다곰 on 2023/02/15.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, h;
    cin >> n >> h;
    vector<int> up; //석순
    vector<int> down;   //종유석
    for(int i=0;i<n;i++) {
        int k;
        cin >> k;
        if(i%2==0) up.push_back(k);
        else down.push_back(k);
    }
    
    sort(up.begin(),up.end());
    sort(down.begin(),down.end());
    
    int cnt=0;
    int ans=0x3f3f3f3f;
    for (int i=1; i<=h; i++) {
        // 현재 구간 값보다 같거나 큰 높이를 가진 석순은 파괴되어야 하기 때문에 현재 구간 값이 처음 등장하는 인덱스를 석순 개수에서 빼줘야 함
        // 석순 개수 - i와 같거나 큰 값이 처음 등장하는 인덱스
        int uCnt=up.size()-(lower_bound(up.begin(), up.end(),i)-up.begin());
        
        // 종유석은 위에서 내려오는 것이기 때문에 h-i보다 큰 높이를 가진 종유석은 현재 구간에서 파괴되어야 하므로 h-i보다 큰 값이 처음 등장하는 인덱스를 종유석 개수에 빼줘야 함
        // 종유석 개수 - (h-i)보다 큰 값이 처음 등장하는 인덱스
        int dCnt=down.size()-(upper_bound(down.begin(), down.end(),h-i)-down.begin());
        ans=min(ans, uCnt+dCnt);
    }
    
    for (int i=1; i<=h; i++) {
        int uCnt=up.size()-(lower_bound(up.begin(), up.end(),i)-up.begin());
        int dCnt=down.size()-(upper_bound(down.begin(), down.end(),h-i)-down.begin());
        
        if (uCnt+dCnt==ans) cnt++;
    }
    
    cout << ans << " " << cnt;
}
