//
//  boj6588.cpp
//  boj
//  memory: 2996 KB
//  time: 72 ms
//  Created by 다곰 on 2023/02/21.
//

#include <iostream>
using namespace std;
#define MAX 1000000

bool visit[MAX]={0};

void chk() {
    for (int i=2; i*i<=MAX; i++) {
        if (visit[i]==0) {
            for (int j=i*i; j<=MAX; j+=i) {
                visit[j]=1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    chk();
    
    while(1) {
        int n;
        cin >> n;
        if(n==0) break;
        bool exist=false;
        
        int a=-1,b=-1;
        for(int i=1;i<n/2;i++) {
            a=2*i+1;
            b=n-a;
            if(!visit[a]&&!visit[b]) {
                cout << n << " = " << a << " + " << b <<"\n";
                exist=true;
                break;
            }
        }
        
        if(!exist) cout << "Goldbach's conjecture is wrong.\n";

    }
}
