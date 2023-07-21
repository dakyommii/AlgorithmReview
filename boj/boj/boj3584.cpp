//
//  boj3584.cpp
//  boj
//  memory: 3884 KB
//  time: 12 ms
//  Created by 다곰 on 2023/07/21.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> arr[10001]; // tree 저장 위한 인접리스트
int depth[10001];   // 노드 깊이 저장
int parents[10001]; // 각 노드의 부모 저장?
bool visit[10001]={false};  // 노드 방문 여부

// 노드 깊이와 부모 설정
void dfs(int node, int d) {
    visit[node]=true;
    depth[node]=d;
    
    // 현재 노드와 연결된 노드 중에 자식 노드 탐색
    // 아직 방문하지 않은 노드는 자식 노드이고 이미 방문한 노드는 부모 노드
    for(int i=0;i<arr[node].size();i++) {
        int next=arr[node][i];
        if(visit[next]) continue;
        parents[next]=node; // 다음 방문할 노드(자식 노드)의 부모 노드를 현재 노드로 기록
        dfs(next,d+1);  // 자식 노드로 이동하고 깊이 늘려주기
    }
}

// 최소 공통 조상 찾기
int lca(int a, int b) {
    if(a==b) return a;  // 두 노드가 같으면 현재 노드가 공통 조상
    // 두 노드의 깊이가 같으면서 아직 공통 조상을 찾지 못하면 이어서 탐색: 부모 노드층에서 공통 조상 찾아야함
    if(depth[a]==depth[b]) return lca(parents[a],parents[b]);
    else if(depth[a]>depth[b]) return lca(parents[a],b);    // a 노드의 깊이가 더 깊으면 a 의 부모 계층과 b를 비교해서 계층 맞춰서 탐색
    else return lca(a,parents[b]);  // 그 반대
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--) {
        memset(arr, 0, sizeof(arr));
        memset(depth, 0, sizeof(depth));
        memset(parents, 0, sizeof(parents));
        memset(visit, 0, sizeof(visit));
        
        int n,a,b;
        cin >> n;
        
        bool is_child[10001]={false};
        
        for(int i=0;i<n-1;i++) {
            cin >> a >> b;
            arr[b].push_back(a);
            arr[a].push_back(b);
            is_child[b]=true;
        }
        
        cin >> a >> b;
        
        // 루트 노드 찾기
        int r=0;
        for(int i=1;i<=n;i++) {
            if(!is_child[i]) {
                r=i;
                break;
            }
        }
        
        dfs(r,0);   // 루트노드부터 시작해서 깊이 탐색
        
        cout << lca(a, b) << endl;
 
    }
}
