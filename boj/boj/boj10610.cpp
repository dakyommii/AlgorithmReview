//
//  boj10610.cpp
//  boj
//  memory: 2300 KB
//  time: 4 ms
//  Created by 다곰 on 2023/03/03.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int sum=0;
    string s;
    cin >> s;
    
    bool ava=false;
    for (int i=0; i<s.size(); i++) {
        if (s[i]=='0') ava=true;
        sum+=(s[i]-'0');
    }
    
    if (ava && sum%3==0) {
        sort(s.rbegin(), s.rend());
        cout << s;
    }
    else cout << -1;
    
    
}
