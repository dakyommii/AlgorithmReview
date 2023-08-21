//
//  boj13397.cpp
//  boj
//  memory: 2020 KB
//  time: 0 ms
//  Created by 다곰 on 2023/08/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,m;
    
    cin>>n>>m;
    
    vector<int> v(n);
    int mx=0;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        mx=max(mx,v[i]);
    }
    
    int left=0,right=mx,ans=100001;
    while(left<=right) {
        int mid=(left+right)/2;
        
        int mn=v[0],cnt=1;
        mx=v[0];
        for(int i=1;i<n;i++) {

            mn=min(mn,v[i]);
            mx=max(mx,v[i]);
            
            if(mx-mn>mid) { // 구간 점수가 mid 보다 크면 구간 count -> 현재 인덱스부터 새로운 구간 시작하는 것
                cnt++;
                
                // 현재 구간부터 새로운 구간 시작하기 때문에 최대, 최소값 초기화
                mn=v[i];
                mx=v[i];
            }
        }

        if(cnt<=m) {
            ans=min(ans,mid);   // 구간점수 최소값으로 갱신
            right=mid-1;
        }
        else left=mid+1;
    }

    cout << ans << endl;
}

/*
n 개의 수를 m 개 이하 구간으로 나누기
구간 점수 최댓값을 최소
구간 점수 = 최댓값-최솟값

1. 전체 배열에서 최댓값-최솟값 구해서 이분탐색
2. 탐색한 구간 점수를 넘기지 않을 때까지 하나의 구간으로 취급
3. 구간 개수가 M 보다 많으면 구간 점수를 늘리기
4. 구간 개수가 M 보다 적으면 구간 점수 줄이기
*/

