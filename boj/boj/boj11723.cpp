//
//  boj11723.cpp
//  boj
//  memory: 2024 KB
//  time: 692 ms
//  Created by 다곰 on 2023/09/15.
//

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string cmd;
    int m,x;
    cin >> m;
    int s[21]={0};
    
    while(m--) {
        cin >> cmd;

        if(cmd=="add") {
            cin >> x;
            s[x]=1;
        }
        else if(cmd=="remove") {
            cin >> x;
            s[x]=0;
        }
        else if(cmd=="check") {
            cin >> x;
            cout <<s[x] << '\n';
        }
        else if(cmd=="toggle") {
            cin >> x;
            if(s[x]==1) s[x]=0;
            else s[x]=1;
        }
        else if(cmd=="all") {
            for(int i=1;i<=20;i++) s[i]=1;
        }
        else if(cmd=="empty") {
            memset(s,0,sizeof(s));
        }
    }
}
