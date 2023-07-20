//
//  boj20924.cpp
//  boj
//  memory: 66436 KB
//  time: 140 ms
//  Created by 다곰 on 2023/07/20.
//

#include <iostream>
#include <vector>

using namespace std;

struct node {
    int dst;
    int d;
};

vector<node> arr[2000001];
bool visit[2000001]={false};
int tr=0,br=0,cnt=0,st;

void find_trunk(int a) {

    if(arr[a].size()>2) {
        st=a;
        return;
    }
    
    visit[a]=true;
    
    for(int i=0;i<arr[a].size();i++) {
        node nd=arr[a][i];
        
        if(visit[nd.dst]) continue;
        
        tr+=nd.d;
        find_trunk(nd.dst);
    }
}

void find_branch(int a) {
    visit[a]=true;
    if(arr[a].size()==1) {
        br=max(cnt,br);
        return;
    }
    
    for(int i=0;i<arr[a].size();i++) {
        node nd=arr[a][i];
        
        if(visit[nd.dst]) continue;
        
        cnt+=nd.d;
        find_branch(nd.dst);
        cnt-=nd.d;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,r,a,b,d;
    
    cin >> n >> r;
    
    for(int i=0;i<n-1;i++) {
        cin >> a >> b >> d;
        arr[a].push_back({b,d});
        arr[b].push_back({a,d});
    }
    
    // 몸통 없는 경우: 루트 노드의 자식이 여러개
    if(arr[r].size()>=2) st=r;
    else find_trunk(r);    // 몸통 있는 경우
    
    // 가지 길이 찾기
    find_branch(st);
    
    cout << tr <<" " << br;
}
