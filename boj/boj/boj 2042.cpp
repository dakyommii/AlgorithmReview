//
//  boj 2042.cpp
//  boj
//  memory: 26236 KB
//  time: 236 ms
//  Created by 다곰 on 2023/01/10.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long arr[1000001];

long long init(vector<long long>& tree,int node, int start, int end) {
    
    // 초기 데이터
    if(start==end) return tree[node]=arr[start];
    
    int mid=(start+end)/2;
//    long long left=init(tree,2*node, start, mid);    // 왼쪽 트리 재귀
//    long long right=init(tree,2*node+1, mid+1, end); // 오른쪽 트리 재귀
    
//    tree[node]=left+right;  // 현재 노드 = 왼쪽 자식 노드 + 오른쪽 자식 노드
    
    return tree[node]=init(tree,2*node, start, mid)+init(tree,2*node+1, mid+1, end);
}

long long sum(vector<long long>& tree,int node, int start, int end, int left, int right) {
    
    /*
        1. 구간합 시작 인덱스가 현재 노드가 포함하는 범위 마지막 인덱스보다 큰 경우
        2. 구간합 마지막 인덱스가 현재 노드가 포함하는 범위 시작 인덱스보다 작은 경우
        -> 구간합 범위를 현재 노드가 포함하지 않았기 때문에 이 노드 아래로는 탐색하지 않기
     */
    if (left > end || right < start) return 0;
    
    /*
        구간합 범위에 현재 노드가 포함하는 범위가 모두 포함될 경우
        -> 현재 노드 값 return
        -> 이 경우에 포함되지 않을 경우는 범위가 걸쳐있는 경우이기 때문에 이어서 탐색을 해봐야 하는 경우
     */
    if (left <=start && end <=right) return tree[node];
    
    int mid=(start+end)/2;  // 현재 노드의 범위 중앙값
//    long long leftRes=sum(tree,node*2, start, mid, left, right);
//    long long rightRes=sum(tree,node*2+1, mid+1, end, left, right);
    
    return sum(tree,node*2, start, mid, left, right)+sum(tree,node*2+1, mid+1, end, left, right);
}

void update(vector<long long>& tree,int node, int start, int end, int index, long long value) {
    // 바꾸려는 인덱스가 현재 노드 범위에 포함되지 않을 경우
    if(index < start || index > end) return;
    tree[node]=tree[node]+value;
    
    // 현재 노드가 변경할 인덱스가 아니라면 자식 노드들도 갱신해줘야 하기 때문에 업데이트 마저 하기
    if (start!=end) {
        int mid = (start+end)/2;
        update(tree,node*2, start, mid, index, value);
        update(tree,node*2+1, mid+1, end, index, value);
    }
}

int main() {
    ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    
    int h=ceil(log2(n));
    int size=1 << (h+1);
    vector<long long> tree(size);

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    init(tree,1,0,n-1);
    
    int c=m+k;
    while (c--) {
        int a,b;
        long long c;
        cin >> a >> b >> c;
        
        if (a==1) { // swap
            long long v = c-arr[b-1];
            update(tree,1, 0, n-1, b-1, v);
            arr[b-1]=c;
        }
        else {  // 구간합
            cout << sum(tree,1, 0, n-1, b-1, c-1) << '\n';
        }
    }
    
}


