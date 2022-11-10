//
//  boj 1717.cpp
//  boj
//  memory: 8292 KB
//  time: 44 ms
//  Created by 다곰 on 2022/11/10.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> parents;

// 부모 노드를 확인하는 함수
int find(int node) {
    //집합이 자기 자신이면 return
    if(parents[node]==node) return node;
    else return parents[node]=find(parents[node]);
}

// 합집합은 부모 노드의 노드를 바꿔주기만 하기
void uni(int a, int b) {
    int pa=find(a);
    int pb=find(b);
    parents[pb]=pa;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m,flag,a,b;
    cin >> n >> m;
    

    for (int i=0; i<=n; i++) parents.push_back(i);

    
    for (int i=0; i<m; i++) {
        cin >> flag >> a >> b;
        
        if(flag==0) {
            uni(a,b);
        }
        else if(find(a)==find(b)) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}

//n: 노드 개수
//m: 연산 개수
//
//0 이면 집합 합치기
//1 이면 두 원소가 같은 집합인지 확인

//* int parents[] -> 처음에는 각 노드 값으로 초기화
//* vector<vector<int>> u -> n+1 개로 초기화, u[idx] 에 idx push

//1. a==b 이거나 parents가 같으면 이미 같은 집합이므로 1일 경우에만 YES 출력하고 continue
//2. 0일 경우:
//    a==b 이거나 parents가 같으면 이미 같은 집합이므로 continue
//    b의 parents가 자기 자신이면 parents[b]=parents[a] 로 변경
//    b의 parents가 자기 자신이 아닐 경우, 같은 parents 가진 parents도 모두 parents[a]로 변경
//3. 1일 경우: NO 출력
