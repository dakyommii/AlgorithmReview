//
//  boj13549.cpp
//  boj
//  memory: 3072 KB
//  time: 4 ms
//  Created by 다곰 on 2023/03/20.

#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int main() {
    int n,k;
    long long ans[100001];  // 최단시간 저장 배열
    cin >> n >> k;
    
    // ans 최대값으로 초기화
    for(int i=0;i<100001;i++) {
        ans[i]=INF;
    }
    
    // 오름차순 정렬
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    
    // 시작 위치인 n은 0초 걸림
    pq.push({0,n});
    ans[n]=0;
    
    while(!pq.empty()) {
        long long cnt=pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        
        // 기존에 저장된 시간보다 적을 때만 갱신하고 pq 에 넣어주기
        // k 위치가 n 보다 작은 경우 존재할 수 있기 때문에 음수로 가는 것을 방지하기 위해 다음 위치가 0 이상, 100001 미만인지 확인
        if((cur-1<100001 && cur-1>=0)&&(cnt+1<ans[cur-1])) {
            pq.push({cnt+1,cur-1});
            ans[cur-1]=cnt+1;
        }
        
        if((cur+1<100001)&&(cnt+1<ans[cur+1])) {
            pq.push({cnt+1,cur+1});
            ans[cur+1]=cnt+1;
        }
        
        if((2*cur<100001)&&(cnt<ans[2*cur]) ) {
            pq.push({cnt,2*cur});
            ans[2*cur]=cnt;
        }
        
        // ans 가 갱신되면 그 값이 최소값이기 때문에 break
        if(ans[k]!=INF) break;
        
    }
    
    cout << ans[k];
}

/*
k+1 을 초과하는 위치는 아예 저장하지 않음
n=5 -> (4,1),(6,1),(10,0)
---
n=10 -> (9,1),(11,1)
n=4 -> (3,2), (5,2), (8,1)
n=6 -> (7,2),(12,1)
n=8 -> (16,1)
n=9 -> (18,1)
*/
