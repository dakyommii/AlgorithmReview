//
//  boj1644.cpp
//  boj
//  memory: 20732 KB
//  time: 48 ms
//  Created by 다곰 on 2023/02/24.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,end=0,start=0,ans=0,sum=0;
    cin >> n;
    
    if(n==1) {
        cout <<0;
        return 0;
    }
    vector<int> prime;
    
    vector<int> v(n+1,0);
    for(int i=2;i*i<=n;i++) {
        if(v[i]==0) {
            for(int j=i*i;j<=n;j+=i) {
                v[j]=1;
            }
        }
    }
    
    for(int i=2;i<=n;i++) {
        if(v[i]==0) prime.push_back(i);
    }
    
    while(end<=prime.size()) {
        if(sum<n) {
            sum+=prime[end];
            end++;
        }
        else {
            sum-= prime[start];
            start++;
        }
        
        if(sum==n) ans++;
    }
    
    cout << ans;
    
}
