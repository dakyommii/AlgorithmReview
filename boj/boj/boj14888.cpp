//
//  boj14888.cpp
//  boj
//  memory: 2020 KB
//  time: 0 ms
//  Created by 다곰 on 2023/11/20.
//

#include <iostream>
using namespace std;

int op[4]={0};
int num[12];
int mx=-1e9-1,mn=1e9+1,n;

void dfs(int cur, int sum) {

    if(cur==n) {
        mx=max(mx,sum);
        mn=min(mn,sum);
        return;
    }
    
    for(int i=0;i<4;i++) {
        if(op[i]>0) {
            op[i]--;

            if(i==0) dfs(cur+1,sum+num[cur]);
            else if(i==1) dfs(cur+1,sum-num[cur]);
            else if(i==2) dfs(cur+1,sum*num[cur]);
            else {
                if(sum>0) dfs(cur+1,sum/num[cur]);
                else if(sum<0) dfs(cur+1,abs(sum)/num[cur]*(-1));
                else dfs(cur+1,sum);
            }
            
            op[i]++;
        }
    }
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> num[i];
    for(int i=0;i<4;i++) cin >> op[i];
    
    dfs(1,num[0]);
    
    cout << mx <<'\n';
    cout << mn << '\n';
}
