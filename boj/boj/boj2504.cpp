//
//  boj2504.cpp
//  boj
//  memory: 2024 KB
//  time: 0 ms
//  Created by 다곰 on 2023/02/10.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    stack<char> st;
    int ans=0,tmp=1;
    
    for(int i=0;i<s.size();i++) {
        if (s[i]=='(') {    // 가중치 2 괄호 생성
            tmp*=2;
            st.push('(');
        }
        else if(s[i]=='[') {    // 가중치 3 괄호 생성
            tmp*=3;
            st.push('[');
        }
        else if(s[i]==')') {    // 가중치 2 닫는 괄호일 때
            if (st.empty() || st.top()!='(') {  // 여는 괄호 없거나 스택이 비어있으면 예외처리
                ans=0;
                break;
            }
            else if(s[i-1]=='(') {  // 바로 () 완성
                ans+=tmp;   // 괄호 열 때 이미 가중치 계산해뒀기 때문에 바로 ans에 더하기
                tmp /=2;    // 다시 tmp값 초기화
                st.pop();
            }
            else {  // 나머지는 괄호 짝 안에 다른 괄호 있었던 경우이므로 해당 괄호 열 때 곱했던 가중치 초기화
                tmp/=2;
                st.pop();
            }
        }
        else if(s[i]==']') {    // 가중치 3 닫는 괄호일 때
            if (st.empty() || st.top()!='[') {  // 여는 괄호 없거나 스택이 비어있으면 예외처리
                ans=0;
                break;
            }
            else if(s[i-1]=='[') {  // 바로 () 완성
                ans+=tmp;   // 괄호 열 때 이미 가중치 계산해뒀기 때문에 바로 ans에 더하기
                tmp /=3;    // 다시 tmp값 초기화
                st.pop();
            }
            else {  // 나머지는 괄호 짝 안에 다른 괄호 있었던 경우이므로 해당 괄호 열 때 곱했던 가중치 초기화
                tmp/=3;
                st.pop();
            }
        }
    }
    
    if (!st.empty()) ans=0;
    
    cout << ans <<'\n';
    
}
