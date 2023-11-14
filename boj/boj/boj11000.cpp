//
//  boj11000.cpp
//  boj
//  memory: 5224 KB
//  time: 64 ms
//  Created by 다곰 on 2023/08/04.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,s,t;
    cin >> n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    for(int i=0;i<n;i++) {
        cin >> s >> t;
        pq.push({s,t});
    }
    
    priority_queue<int,vector<int>,greater<>> eq;
    int ans=0;
    while(!pq.empty()) {
        t=pq.top().second;
        s=pq.top().first;
        pq.pop();

        if(!eq.empty() && eq.top()<=s) {
            eq.pop();
            eq.push(t);
        }
        else {
            eq.push(t);
            ans++;
        }
    }
    
    cout << ans;
}

// s에 시작헤ㅐ서 t에 끝남
// 시작 시간이 빠른 순으로 정렬
// 끝나는 시간을 큐에 push하는데 top과 비교해서 현재 시작 강의의 시작 시간이 top보다 빠르면 push하고 count
