//
//  boj17073.cpp
//  boj
//  memory: 31380 KB
//  time: 280 ms
//  Created by 다곰 on 2023/03/29.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,w;
    vector<int> tree[500001];
    
    cin >> n >> w;
    
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    int cnt=0;
    for(int i=2;i<=n;i++) {
        if(tree[i].size()==1) cnt++;
    }
    
    cout.precision(10);
    cout << w/(double)cnt;
}
