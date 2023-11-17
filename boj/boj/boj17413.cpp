//
//  boj17413.cpp
//  boj
//  memory: 2448 KB
//  time: 4 ms
//  Created by 다곰 on 2023/11/17.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    string s="",res="",rev="";

    getline(cin, s);
    
    bool open=false;
    for(int i=0;i<s.size();i++) {
        if(s[i]=='<') {
            open=true;
            reverse(rev.begin(),rev.end());
            res+=rev+'<';
            rev="";
        }
        else if(s[i]=='>') {
            open=false;
            res+='>';
        }
        else if(!open&&s[i]==' ') {
            reverse(rev.begin(),rev.end());
            res+=rev+' ';
            rev="";
        }
        else if(open){
            res+=s[i];
        }
        else {
            rev+=s[i];
        }
        
    }
    
    if(!rev.empty()) {
        reverse(rev.begin(), rev.end());
        res+=rev;
    }
    
    cout << res;

}
