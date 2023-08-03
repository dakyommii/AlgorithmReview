//
//  boj11000.cpp
//  boj
//  memory: 5224 KB
//  time: 68 ms
//  Created by 다곰 on 2023/08/04.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        if(a.first==b.first) return a.second>b.second;
        return a.first>b.first;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> wait;
    priority_queue<int,vector<int>,greater<>> fin;
    cin >> n;
    while(n--) {
        int s,t;
        
        cin >> s >> t;
        wait.push({s,t});
    }
    
    fin.push(wait.top().second);
    wait.pop();

    while (!wait.empty()) {
        // 강의실 추가
        if(wait.top().first>=fin.top()) fin.pop();

        fin.push(wait.top().second);
        wait.pop();
    }
    
    cout << fin.size() << endl;
}

/*
s: 시작시간
t: 종료 시간
s, t는 long long
최소 강의실 사용해서 모든 수업 끝내기
시작 시간 - 종료 시간 빠른 순서로 오름차순 정렬: 우선순위 큐
현재 강의 중인 강의실: 종료시간 빠른 순으로 우선순위 큐로 정렬
현재 강의 중인 강의실과 강의실 개수가 같다면 강의실을 추가해야함
*/
