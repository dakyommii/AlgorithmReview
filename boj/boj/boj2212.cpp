//
//  boj2212.cpp
//  boj
//  memory: 2236 KB
//  time: 4 ms
//  Created by 다곰 on 2023/08/04.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {

    int n,k;
    cin >> n;
    cin >> k;
    
    vector<int> v;
    for(int i=0;i<n;i++) {
        int c;
        cin >> c;
        v.push_back(c);
    }
    
    sort(v.begin(),v.end());
    
    priority_queue<int> pq;
    for(int i=1;i<n;i++) {
        pq.push(v[i]-v[i-1]);
    }
    
    int ans=0;
    
    int cnt=0;
    while(!pq.empty() && cnt<k-1) {
        pq.pop();
        cnt++;
    }
    
    while(!pq.empty()) {
        ans+=pq.top();
        pq.pop();
    }
    
    cout << ans << endl;
   
}
