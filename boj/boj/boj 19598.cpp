//
//  boj 19598.cpp
//  boj
//  time: 144ms
//  Created by 다곰 on 2022/07/15.
//

#include <iostream>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(pair<int,int> &a, pair<int,int> &b) {
        return a.second>b.second;
    }
};

int main() {
    int n, s, e;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> wq;   //대기 큐 - fist 기준 오름차순 정렬
    priority_queue<pair<int, int>,vector<pair<int,int>>,cmp> iq;  //회의중 큐 - second 오름차순 정렬
    
    cin >> n;
    while (n--) {
        cin >> s >> e;
        wq.push({s,e});
    }
    
    int ans=0;
    
    while (!wq.empty()) {
        
        //회의 처음 시작할 경우 or 가장 빨리 시작할 수 있는 회의가 가장 빨리 끝나는 회의 시간보다 빠를 때 -> 새로운 회의실 열어야 함
        if(iq.empty()||wq.top().first < iq.top().second) ans++;
        else iq.pop();  //그 이외의 경우, 기존 회의실에서 이어서 하면 되기 때문에 회의실 열 필요없음

        //회의실을 새로 열던지 이어서 하던지 대기 중이던 회의는 어쨌든 시작
        iq.push({wq.top().first,wq.top().second});
        wq.pop();
        
    }
    
    cout << ans;    //최종적으로 연 회의실 개수 - 최소값
}
