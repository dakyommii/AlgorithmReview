//
//  boj 1922.cpp
//  boj
//  time: 104 ms
//  memory: 4340 KB
//  Created by 다곰 on 2022/11/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct com {
    int a;    //출발 컴퓨터
    int b;    // 도착 컴퓨터
    int c;    //비용
};

bool cmp(com &x, com&y) {
    if(x.c==y.c) return x.a<y.a;
    
    return x.c<y.c;
}

vector<int> visit;

// 부모 가져오기
int getParent(int node) {
    if(visit[node]==node) return node;
    else return visit[node]=getParent(visit[node]);
}

// 합집합
void unionParent(int a, int b) {
    a=getParent(a);
    b=getParent(b);
    
    if (a!=b) visit[a]=b;
}

// 부모 같은지 확인
bool findParent(int a, int b) {
    if (getParent(a)==getParent(b)) return true;
    else return false;
}

int main() {
    int n, m,a,b,c;
    cin >> n >> m;
    
    vector<com> v;
    for(int i=0;i<m;i++) {
        cin >> a>> b>>c;
        
        v.push_back({a,b,c});
    }
    
    sort(v.begin(),v.end(),cmp);

    visit.push_back(-1);
    for (int i=1; i<=n; i++) {
        visit.push_back(i);
    }
    
    int ans=0;
    for(int i=0;i<v.size();i++) {
        a=v[i].a;
        b=v[i].b;
        c=v[i].c;
        
        // 부모가 다를 경우 합집합으로 묶어주기 -> 이외의 경우는 이미 합집합이므로 사이클 피하기 위해 skip
        if (!findParent(a, b)) {
            ans+=c;
            unionParent(a, b);
        }
           
    }

    cout << ans << endl;

}

/*
n: 컴퓨터 수
m: 간선 수
컴퓨터 연결 비용
a(컴퓨터2),b(컴퓨터2),c(비용)
    
a==b 이면 사이클 되므로 skip
   
비용을 기준으로 정렬

방문한 a,b는 visit 처리하고 c는 answer에 추가, 방문한 간선 -> 이 과정 수행시 cnt++
cnt 값이 전체 컴퓨터 개수와 동일하면 모든 컴퓨터 방문한 것이므로 종료

b가 방문한 노드거나 사이클이 되면 skip
*/
