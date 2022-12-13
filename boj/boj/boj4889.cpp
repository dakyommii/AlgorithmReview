//
//  boj4889.cpp
//  boj
//  memory: 2024 KB
//  time: 4 ms

//  Created by 다곰 on 2022/12/13.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int tc=0;
    
    while(1) {
        cin >> s;
        int cnt=0;
        int o=0;
        if(s[0]=='-') break;
        
        for(int i=0;i<s.size();i++) {
            if(s[i]=='}') {
                if(o==0) {
                    o++;
                    cnt++;
                }
                else o--;

            }
            else  o++;
        }
        
        cnt+=o/2;
        
        tc++;
        cout << tc << ". " << cnt << endl;
    }
}

/*
1. 여는 괄호가 없는데 닫는 괄호 나올 경우 -> 여는 괄호로 바꿔주고 stack에 넣기
2. 끝까지 했는데 여는 괄호 혹은 닫는 괄호가 남아있는 경우 하나 바꿔주기
*/
