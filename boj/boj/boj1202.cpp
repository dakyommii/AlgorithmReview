//
//  boj1202.cpp
//  boj
//  memroy: 10224 KB
//  time: 472 ms
//  Created by 다곰 on 2022/07/12.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct value {
    int m;
    int v;
};

bool cmp(value a, value b) {
    return a.m < b.m;
}

int main() {
    int n,k;
    long long ans=0;
    vector<int> bag;
    vector<value> jwerly;
    priority_queue<int> pq;
    cin >> n >> k;

    while(n--) {
        int m,v;
        cin >> m >> v;
        jwerly.push_back({m,v});
    }

    while(k--) {
        int b;
        cin >> b;
        bag.push_back(b);
    }

    sort(bag.begin(), bag.end());
    sort(jwerly.begin(), jwerly.end(), cmp);

    int idx=0;

    for (int i=0; i<bag.size(); i++) {
        while (idx<jwerly.size() && jwerly[idx].m<=bag[i]) {
            pq.push(jwerly[idx++].v);
        }

        if (!pq.empty()) {
            ans+=pq.top();
            pq.pop();
        }

    }

    cout << ans;

}

