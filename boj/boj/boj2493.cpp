//
//  boj2493.cpp
//  boj
//  memory: 6000 KB
//  time: 292 ms
//  Created by 다곰 on 2023/11/02.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n+1,0);

    for(int i=1;i<=n;i++) {
        cin >> v[i];
    }
    
    stack<int> st;
    for(int i=1;i<=n;i++) {
        bool exist=false;
        if(!st.empty()) {
            while(!st.empty()) {
                int idx=st.top();
                if(v[idx]>v[i]) {
                    cout << idx << " ";
                    exist=true;
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        
        if(st.empty() || !exist){
            st.push(i);
            cout << 0 <<" ";
        }

    }
}

// 현재까지 가장 큰 탑 인덱스를 dp에 저장
// 현재 이전까지 가장 큰 탑이 현재 탑보다 작으면 0
// 아니면 현재 이전까지 가장 큰 탑 현재 에 dp에 저장
