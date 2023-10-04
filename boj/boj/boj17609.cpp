//
//  boj17609.cpp
//  boj
//  memory: 2704 KB
//  time: 24 ms
//  Created by 다곰 on 2023/10/04.
//

#include <iostream>
#include <string>
using namespace std;

int dfs(string s, int l, int r, int cnt) {
    
    while(l<r) {
        if(s[l]!=s[r]) {
            if(cnt==0) {
                if(dfs(s,l+1,r,1)==0 || dfs(s,l,r-1,1)==0 ) return 1;
                return 2;
            }
            else return 2;
        }
        else {
            l++;
            r--;
        }
        
    }
    return 0;

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    
    while(t--) {
        string s;
        cin >> s;
//        cout << s << endl;
        cout << dfs(s,0,s.size()-1,0) << endl;
    }
    
}
/*
같은 문자가 나올 때까지
*/
