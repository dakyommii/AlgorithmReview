//
//  boj13975.cpp
//  boj
//  memory: 18528 KB
//  time: 704 ms
//  Created by 다곰 on 2023/09/14.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int k;
        cin >> k;
        
        priority_queue<long long,vector<long long>,greater<>> pq;
        for(int i=0;i<k;i++) {
            long long n;
            cin >> n;
            pq.push(n);
        }
        
        long long ans=0;
        while(!pq.empty()) {
            long long sum=0;
            sum+=pq.top();
            pq.pop();
            
            if(pq.empty()) break;

            sum+=pq.top();
            pq.pop();
            ans+=sum;
            pq.push(sum);
        }

        cout << ans << endl;
    }
}

/*
합치는 비용: 두 파일 크기의 합
*/
