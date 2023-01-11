//
//  boj1655.cpp
//  boj
//  time: 36ms
//  memory: 2792 KB
//  Created by 다곰 on 2022/07/12.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    priority_queue <int> max;    //작은 것들 중 max - 내림차순
    priority_queue<int,vector<int>,greater<int>> min;    //큰 것들 중 min - 오름차순
    
    int num;
    for(int i=1;i<=n;i++) {
        cin >> num;
        
        // size가 같을 때 max에 무조건 넣어주도록 하면 첫번째 try에 예외처리 가능
        // 어차피 size가 같으면 이번 try는 홀수개라는 뜻이기 때문에 한쪽이 많아져도 상관없음
        // -> 그 다음에 한 쪽이 크다면 max가 클 것이기 때문에 else 에 min에 push 해서 균형 맞출 수 있음
        if(max.size()==min.size()) max.push(num);
        else min.push(num);
        
        // max와 min의 순서가 맞지 않을 경우 swap
        if(!max.empty() && !min.empty() && max.top()>min.top()) {
            int mx,mn;
            mx=max.top();
            mn=min.top();
            
            max.pop();
            min.pop();
            
            min.push(mx);
            max.push(mn);
        }
        
        cout << max.top() << '\n';
    }
}
