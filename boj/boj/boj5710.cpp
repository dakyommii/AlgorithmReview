//
//  boj5710.cpp
//  boj
//  memory: 2020 KB
//  time: 20 ms
//  Created by 다곰 on 2023/10/19.
//

#include <iostream>
#include <vector>
using namespace std;

int pay(int a) {
    int cnt=0;
    cnt+=min(a,100)*2;
    a-=100;
    if(a>0) {
        cnt+=min(a,9900)*3;
        a-=9900;
        if(a>0) {
            cnt+=min(a,(1000000-10000))*5;
            a-=(1000000-10000);
            
            if(a>0) cnt+=a*7;
        }
    }
        
    return cnt;
}

int amount(int a) {
    int cnt=0;
    cnt+=min(a,200)/2;
    a-=200;
    if(a>0) {
        cnt+=min(a,9900*3)/3;
        a-=9900*3;
        if(a>0) {
            cnt+=min(a,(1000000-10000)*5)/5;
            a-=(1000000-10000)*5;
            
            if(a>0) cnt+=a/7;
        }
    }
        
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(1) {
        int a,b;
        cin >> a >> b;
        
        if(a==0&&b==0) break;
        
        // 각각의 사용량 구하기
        int use=amount(a);
 
        int left=0, right=use/2;
        while(left<=right) {
            int mid=(left+right)/2;
            int af=pay(mid);
            int bf=pay(use-mid);
            
            
            if(bf-af==b) {
                cout << af <<endl;
                break;
            }
            if(bf-af>b) {
                left=mid+1;
            }
            else right=mid-1;
            
        }
    }
}
