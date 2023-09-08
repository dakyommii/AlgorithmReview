//
//  boj14675.cpp
//  boj
//
//  Created by 다곰 on 2023/09/08.
//

/* 트리에서 모든 간선은 단절선, 단절점은 리프노드 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,q;
    cin >> n;
    
    vector<int> v(n+1,0);
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        v[a]++;
        v[b]++;
    }
    
    cin >> q;
    for(int i=0;i<q;i++) {
        int t,k;
        cin >> t >> k;
        
        if(t==1 && v[k]<2) cout << "no" << '\n';
        else cout << "yes" << '\n';
    }
}

/*
단절점: 정점과 연결된 간선이 2개이상?
단절선: 리프 노드와 연결된 것이 아닐 경우
t=1 -> k번 정점이 단절점인가
t=2 -> k번째 간선이 단절 선인가

1: 2
2: 1 3
3: 2 4
4: 3 5
5: 4
*/
