//
//  boj15903.cpp
//  boj
//  time: 0ms
//  Created by 다곰 on 2022/07/15.
//

#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
    int n, m;
    ll num,x,y,ans=0;
    priority_queue<ll,vector<ll>,greater<ll>> pq;    //우선순위 큐 오름차순 정렬
    
    cin >> n >> m;
    
    while (n--) {
        cin >> num;
        pq.push(num);
    }
    
    
    while (m--) {
        x=pq.top();
        pq.pop();

        y=pq.top();
        pq.pop();

        pq.push(x+y);
        pq.push(x+y);

    }

    while (!pq.empty()) {
        ans+=pq.top();
        pq.pop();
    }

    cout << ans;

}
