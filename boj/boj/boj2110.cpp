//
//  boj2110.cpp
//  boj
//  memory: 2084 KB
//  time: 132 ms
//  Created by 다곰 on 2023/08/17.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,c;
    cin >> n >> c;
    
    vector<int> x(n);
    for(int i=0;i<n;i++) {
        cin >> x[i];
    }
    
    sort(x.begin(),x.end());
    
    int left=1,right=x[n-1],ans=0;
    while (left<=right) {
        int cnt=1;  // 첫번째 집에 1개 설치
        int mid=(left+right)/2;
        int first=x[0]; // 공유기 설치 위치
        for(int i=1;i<x.size();i++) {
            if(x[i]-first>=mid) {
                first=x[i];
                cnt++;  // 공유기 count
            }
        }
        
        if(cnt>=c) {
            ans=mid;
            left=mid+1;
        }
        else {
            right=mid-1;
        }
    
    }
    
    cout << ans << endl;
}

/*
n: 집 개수
c: 공유기 개수
배열: 집의 좌표
*/
