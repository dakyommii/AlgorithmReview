//
//  boj21921.cpp
//  boj
//  memory: 3000 KB
//  time: 96 ms
//  Created by 다곰 on 2023/09/04.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,x,mx=0,cnt=0;
    
    cin >> n >> x;
    
    vector<int> visitors(n);
    for(int i=0;i<n;i++) {
        cin >> visitors[i];
        if(i<x) cnt+=visitors[i];
    }
    
    int st=0,end=x-1,total=1;
    mx=max(mx,cnt);
    while(end<n) {
        cnt-=visitors[st];
        st++;
        end++;
        if(end==n) break;
        cnt+=visitors[end];
        if(mx==cnt) total++;
        else if(cnt>mx) {
            total=1;
            mx=cnt;
        }
    }
    
    if(mx==0) cout << "SAD" << endl;
    else {
        cout << mx << endl;
        cout << total << endl;
    }
}
