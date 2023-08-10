//
//  boj21758.cpp
//  boj
//  memory: 2804 KB
//  time: 40 ms
//  Created by 다곰 on 2023/08/10.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> honey(n+1);
    vector<int> hsum(n+1);

    for(int i=1;i<=n;i++) {
        cin >> honey[i];
        hsum[i]=hsum[i-1]+honey[i];
    }
    
    int mx=0;
    // 벌-벌-꿀통
    for(int i=2;i<n;i++) {
        int v=(hsum[n]-hsum[i])+(hsum[n]-honey[i]-honey[1]);
        mx=max(mx,v);
    }
    
    // 벌-꿀통-벌
    for(int i=2;i<n;i++) {
        int v=(hsum[i]-honey[1])+(hsum[n-1]-hsum[i-1]);
        mx=max(mx,v);
    }
    
    // 꿀통-벌-벌
    for(int i=2;i<n;i++) {
        int v=(hsum[n-1]-honey[i])+hsum[i-1];
        mx=max(mx,v);
    }
    
    cout << mx << endl;
    
}

/*
서로 다른 두 곳에 벌 한마리씩, 다른 한 장소에 벌통 두기
벌: 벌통으로 날아가면서 모든 칸에서 꿀 따기, 시작한 장소에서는 벌이 꿀을 아예 못 땀
최대 꿀 양 계산


*/
