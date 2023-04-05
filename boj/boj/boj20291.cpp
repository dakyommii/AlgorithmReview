//
//  boj20291.cpp
//  boj
//  memory: 11004 KB
//  time: 120 ms
//  Created by 다곰 on 2023/04/05.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    
    map<string, int> mp;
    while(n--) {
        string s;
        cin >> s;
        
        for(int i=0;i<s.size();i++) {
            if(s[i]=='.') {
                string w=s.substr(i+1);
                
                mp[w]++;
                break;
            }
        }
    }
    
    for(auto it:mp) {
        cout << it.first << " " << it.second << '\n';
    }
    

}
