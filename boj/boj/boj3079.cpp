//
//  boj3079.cpp
//  boj
//  memory: 3572 KB
//  time: 116 ms
//  Created by 다곰 on 2023/04/13.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    
    vector<long long> t;

    for(int i=0;i<n;i++) {
        long long k;
        cin >> k;
        t.push_back(k);
    }
    
    sort(t.begin(),t.end());
    
    long long ans=0;
    long long left=1;
    long long right=t[0]*m;
    
    while(left<=right) {
        long long mid=(right+left)/2;
        
        long long sum=0;

        for(int i=0;i<n;i++) {
            sum+= (mid/t[i]);
        }
        
        if(sum<m) {
            left=mid+1;
        }
        else {
            ans=mid;
            right=mid-1;
        }
        
    }
    
    cout << ans << endl;
}

/*
m: 인원
n: 입국심사대
배열: 입국심사시간
최소 심사시간 구하기
*/
