//
//  boj7453.cpp
//  boj
//  memory: 329852 KB
//  time: 4244 ms
//  Created by 다곰 on 2023/02/07.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long num[4001][4];
    for(int i=0;i<n;i++) {
        cin >> num[i][0] >> num[i][1] >> num[i][2] >> num[i][3];
    }
    
    vector<long long> ab;
    vector<long long> cd;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            ab.push_back(num[i][0]+num[j][1]);
            cd.push_back(num[i][2]+num[j][3]);
        }
    }
    
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    
    long long cnt=0;
    for(int i=0;i<ab.size();i++) {
        long long key=ab[i];
        auto it=lower_bound(cd.begin(),cd.end(),-key);
        auto it2=upper_bound(cd.begin(),cd.end(),-key);

        cnt+=it2-it;
    }
    
    cout << cnt;
}
