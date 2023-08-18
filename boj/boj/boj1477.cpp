//
//  boj1477.cpp
//  boj
//  memory: 2024 KB
//  time: 0 ms
//  Created by 다곰 on 2023/08/18.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,m,l;
    cin >> n >> m >> l;
    
    vector<int> v(n+2);
    v.push_back(0);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    v.push_back(l);
    
    sort(v.begin(),v.end());
    
    
    int left=1,right=l-1,ans=1000;
    while(left<=right) {
        int mid=(left+right)/2;
        
        int cnt=0;
        
        for(int i=1;i<v.size();i++) {
            cnt+=((v[i]-v[i-1])/mid);
            if(cnt>0) {
                if((v[i]-v[i-1])%mid==0) cnt-=1;
            }
            
        }

        if(cnt>m) {
            left=mid+1;
        }
        else {
            ans=min(ans,mid);
            right=mid-1;
        }

    }
    
    cout << ans << endl;
}
