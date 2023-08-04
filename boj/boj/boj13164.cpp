//
//  boj13164.cpp
//  boj
//  memroy: 5104 KB
//  time: 212 ms
//  Created by 다곰 on 2023/08/04.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    priority_queue<int> pq;
    
    int pre=0;
    int ans=0;
    for(int i=0;i<n;i++) {
        int c;
        cin >> c;
        if(i>0) {
            ans+=(c-pre);
            pq.push(c-pre);
        }
        pre=c;
    }
    
    
    int cnt=0;
    while(!pq.empty() && cnt<k-1) {
        ans-=pq.top();
        pq.pop();
        cnt++;
    }
    
    cout << ans << endl;
}
