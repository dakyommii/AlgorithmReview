//
//  boj9935.cpp
//  boj
//  memory: 7796 KB
//  time: 52 ms
//  Created by 다곰 on 2023/10/30.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s,b;
    cin >> s;
    cin >> b;
    
    string ans="";

    for(int i=0;i<s.size();i++) {
        ans+=s[i];
        if(ans.back()==b.back() && ans.size()>=b.size()) {
            string str="";
            for(int j=b.size()-1;j>=0;j--) {
                if(ans.back()==b[j]) {
                    ans.pop_back();
                    str+=b[j];
                }
                else {
                    reverse(str.begin(), str.end());
                    ans+=str;
                    break;
                }
            }
        }
    }
    
    if(ans.empty()) cout << "FRULA";
    else cout << ans;
}

/*
폭발 문자열이 폭발하면 그 문자는 문자열에서 사라지며, 남은 문자열은 합쳐지게 된다.
폭발은 폭발 문자열이 문자열에 없을 때까지 계속된다.
남아있는 문자가 없는 경우가 있다. 이때는 "FRULA"를 출력한다.
남은 문자열을 출력

1. 문자열 사이즈가 0이 될 떄까지 반복
2. 문자열을 탐색하면서 폭발 문자 첫 글자와 같으면 폭발 문자 개수만큼 문자가 같은지 확인
    1) 문자가 같으면 문자열 없애고 문자열 붙인 후에 현재 위치보다 하나 앞에서 다시 탐색
    2) 아니면 이어서 탐색
*/
