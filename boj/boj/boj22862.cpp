//
//  boj22862.cpp
//  boj
//  memory: 5928 KB
//  time: 448 ms
//  Created by 다곰 on 2023/09/04.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >>k;
    vector<int> num(n);
    for(int i=0;i<n;i++) {
        cin >> num[i];
    }
    
    int st=0,end=0,cnt=0,ans=0;
    while (end<n) {
        if(cnt>k) {
            if(num[st]%2==1) cnt--;
            st++;
        }
        else {
            if(num[end]%2==1) cnt++;
            end++;
        }
        
        if(cnt<=k) ans=max(ans,end-st-cnt);
    }
    
    cout << ans << endl;
    
}

/*
start= 처음 짝수 위치
end=k번 이하로 자르고 도달할 수 있는 짝수 위치

*/
