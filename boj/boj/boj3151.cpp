//
//  boj3151.cpp
//  boj
//  memory: 2180 KB
//  time: 1736 ms
//  Created by 다곰 on 2023/11/15.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    long long ans=0;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());

    for(int i=0;i<v.size()-1;i++) {
        for(int j=i+1;j<v.size();j++) {
            int sum=v[i]+v[j];

            auto st=lower_bound(v.begin()+j+1,v.end(),-1*sum)-v.begin();
            auto ed=upper_bound(v.begin()+j+1,v.end(),-1*sum)-v.begin();

            ans+=ed-st;
        }

    }

    cout << ans;
}

