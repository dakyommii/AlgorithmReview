//
//  boj1927.cpp
//  boj
//  memory: 2916 KB
//  time: 16 ms
//  Created by 다곰 on 2023/02/15.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    priority_queue<int,vector<int>,greater<int>> pq;
    cin >> n;
    
    while(n--) {
        int k;
        cin >> k;
        if(k==0) {
            if(pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(k);
        }
    }
}
