//
//  boj2331.cpp
//  boj
//  memory: 2208 KB
//  time: 0 ms
//  Created by 다곰 on 2022/10/29.
//

#include <iostream>
#include <vector>

using namespace std;
vector<int> d;

int isloop(int n) {
    for (int i=0; i<d.size(); i++) {
        if(d[i]==n) return i;
    }
    return -1;
}

int main() {
    
    int a, p;
    cin >> a>> p;
    
    d.push_back(a);
    int idx=0;
    while (1) {
        int k=0;
        int b=d[idx];
        while (b%10!=0 || b/10!=0) {
            k+=pow(b%10, p);
            b=b/10;
        }
        
        int ans=isloop(k);
        if(ans>-1) {
            cout <<ans;
            break;
            
        }
        
        idx++;
        d.push_back(k);
    }
    
    
}
