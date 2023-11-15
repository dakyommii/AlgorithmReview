//
//  boj1806.cpp
//  boj
//  time: 32ms
//  memory: 2412 KB
//  Created by 다곰 on 2023/01/09.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,s;
    cin >> n >> s;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    
    int l=0,r=0,len=1e9;
    long long sum=0;
    while(l<=r&&l<n) {
        
        if(sum>=s) {
            len=min(len,r-l);
            sum-=v[l];
            l++;
        }
        else if(r==n) break;
        else {
            sum+=v[r];
            r++;
        }
    }
    
    if(len==1e9) cout << 0;
    else cout << len;
}
