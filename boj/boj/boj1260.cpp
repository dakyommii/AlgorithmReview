//
//  boj1260.cpp
//  boj
//  memory: 3000 KB
//  time: 8 ms
//  Created by 다곰 on 2022/10/28.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

bool arr[1001][1001]={false};
bool visit[1001]={false};
int n;

void dfs(int s) {
    cout << s <<" ";
    for(int i=1;i<=n;i++) {

        if(i==s || !arr[s][i]) continue;
        if(!visit[i]) {
            visit[i]=true;
            dfs(i);
        }
    }
}

void bfs(int s) {
    queue<int> pq;
    pq.push(s);
    visit[s]=true;
    while (!pq.empty()) {
        int c=pq.front();
        pq.pop();
        cout << c << " ";
        for(int i=1;i<=n;i++) {

            if(i==c || !arr[c][i]) continue;
            if(!visit[i]) {
                visit[i]=true;
                pq.push(i);
            }
        }
    }
    
}

int main() {
    int m,v;
    cin >> n >> m >>v;
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        
        arr[a][b]=true;
        arr[b][a]=true;
        
    }
    
    visit[v]=true;
    dfs(v);
    cout << endl;
    memset(visit, false, sizeof(visit));

    bfs(v);
}
