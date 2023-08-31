//
//  boj2141.cpp
//  boj
//  memory: 4356 KB
//  time: 124 ms
//  Created by 다곰 on 2023/08/31.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<pair<int,int>> town;
    vector<long long> sum(n,0);
    for(int i=0;i<n;i++) {
        int x,a;
        cin >> x >> a;
        town.push_back({x,a});
    }
    
    sort(town.begin(),town.end());
    
    sum[0]=town[0].second;
    for(long long i=1;i<n;i++) {
        sum[i]=sum[i-1]+town[i].second;
    }
    
    int left=0, right=n-1, ans=1000000001;
    while (left<=right) {
        int mid=(left+right)/2;
        
        // 왼쪽이 더 크면 왼쪽으로 이동
        if(sum[mid]>=sum[n-1]-sum[mid]) {
            right=mid-1;
            ans=min(ans,town[mid].first);
        }
        else {
            left=mid+1;
        }
    }
    
    cout << ans << endl;
    
}
