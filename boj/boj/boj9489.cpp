//
//  boj9489.cpp
//  boj
//  memory: 5944 KB
//  time: 1108 ms
//  Created by 다곰 on 2023/08/01.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,k;
    while(1) {
        int parents[1000001];   // 각 노드의 부모 저장
        map<int,vector<int>> child; // 각 노드의 자식 저장
        int root;
        
        queue<int> q;
        
        memset(parents, 0, sizeof(parents));
        child.clear();
                
        cin >> n >> k;
        
        if(n==0 && k==0) break;
        
        cin >> root;
        
        if(k==root) {
            cout << 0 << endl;  // k가 루트노드이면 사촌이 없음
            continue;
        }

        q.push(root);
        
        int pre=0;  // 이전 노드 저장
        int par=root;   // 현재 노드의 부모 노드 저장

        for(int i=1;i<n;i++) {
            int cur;
            cin >> cur;
            
            // 첫 탐색이거나 현재 노드가 이전 노드와 같은 집합에 속하지 않는 노드이면 현재 노드의 부모 갱신
            if(pre==0 || pre+1!=cur) {
                par=q.front();
                q.pop();
            }
            
            parents[cur]=par;    // 현재 노드의 부모 저장
            
            // 부모의 자식에 현재 노드 저장
            vector<int> v;
        
            if(child.count(par)>0) v=child[par];
            v.push_back(cur);
            child[par]=v;

            q.push(cur);
            pre=cur;
        }
        
        
        int ans=0;
        par=parents[k];
        int grand=parents[par];
        vector<int> v;
        v=child[grand]; // 삼촌 vector
        for(int i=0;i<v.size();i++) {
            int c=v[i];  // 삼촌 노드
            
            if(c==par) continue;
            
            ans+=child[c].size();
        }
        
        cout << ans << endl;
    }
    
}

/*
n: 노드의 수
k: 사촌 수 구해야하는 노드 번호
수열: 첫번째 정수는 루트 노드,
n 과 k 모두 0이면 종료

각 노드의 부모 저장
깊이 별로 해당하는 노드 저장
각 노드의 존재 유무 저장
k 노드의 깊이 기록해서 k 노드와 같은 깊이이면서 부모가 같지 않는 노드 개수 count
*/
