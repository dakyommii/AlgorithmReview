//
//  boj1654.cpp
//  boj
//  memory: 2020 KB
//  time: 8 ms
//  Created by 다곰 on 2023/08/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long k,n;
    cin >> k >> n;
    
    long long mx=0;
    vector<long long> v(k);
    for(int i=0;i<k;i++) {
        cin >> v[i];
        mx=max(mx,v[i]);
    }

    sort(v.begin(),v.end());
    
    long long l=1, r=mx,m,ans=0;

    while(l<=r) {
        m=(l+r)/2;
        long long cnt=0;
        for(int i=0;i<k;i++) {
            cnt+=v[i]/m;
        }

        // 개수가 작으면 길이 범위를 더 줄여서 탐색하기 위해 Mid 값 앞으로 Right 를 옮겨줘서 Mid 앞 범위 탐색
        if(cnt<n) r=m-1;
        // 개수가 크면 Mid 값 앞으로 Left 를 옮겨줘서 Mid 뒤 범위 중에서 개수가 작아질 때까지 최대값을 정답에 갱신
        else if(cnt>=n) {
            l=m+1;
            ans=max(ans,m);
        }
    }
    
    cout << ans << endl;

}

/*
n 개의 랜선 만들기
k개 랜선 보유
n 개의 같은 길이의 랜선으로 만들기
*/
