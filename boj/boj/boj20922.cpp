//
//  boj20922.cpp
//  boj
//  memory: 6588 KB
//  time: 80 ms
//  Created by 다곰 on 2023/09/04.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,k;
    cin >> n >>k;
    vector<int>v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    
    int s=0,e=0,len=0;
    int visit[1000001]={0};
    while(e<n) {
       if(visit[v[e]]<k) {
           visit[v[e]]++;
           e++;
           len=max(len,e-s);
       }
        else if(visit[v[e]]==k){
            visit[v[s]]--;
            s++;
        }
    }
    
    cout << len;
}
