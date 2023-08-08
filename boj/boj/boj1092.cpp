//
//  boj1092.cpp
//  boj
//  memory: 2156 KB
//  time: 920 ms
//  Created by 다곰 on 2023/08/08.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,m;
    cin >> n;
    
    vector<int> crain;
    for(int i=0;i<n;i++) {
        int k;
        cin >> k;
        crain.push_back(k);
    }
    
    cin >> m;
    
    vector<int> box;
    for(int i=0;i<m;i++) {
        int k;
        cin >> k;
        box.push_back(k);
    }
    
    sort(crain.begin(),crain.end(),greater<>());
    sort(box.begin(),box.end(),greater<>());
    
    if(box[0]>crain[0]) {
        cout << -1 << endl;
        return 0;
    }
    
    int ans=0;
    
    while (!box.empty()) {
        bool exist=false;
        for(int i=0;i<n;i++) {
            for(int j=0;j<box.size();j++) {
                if(crain[i]>=box[j]) {
                    box.erase(box.begin()+j);
                    exist=true;
                    break;
                }
            }
        }
        if(exist) ans++;
        
    }
    
    cout << ans << endl;
        
    
}

/*
n: 크레인 개수
배열: 크레인의 무게 제한
m: 박스 수
배열: 각 박스의 무게 -> 우선순위 큐

1분에 박스 하나씩 배에 실을 수 있음
모든 박스를 배로 옮기는 소요 시간 최솟값, 모든 박스를 옮길 수 없으면 -1

9 8 6
7 4 5 2 2

20 19
19 16 16 14 12 5 1

32 28 25 23
32 27 24 20 18 16 10 7 5 2

무게 무거운 것부터 무거운 크레인에 배정
이번 차례에 실지 못하면 큐에 따로 넣어두고 다음 차례에 넣기
가장 무거운 크레인에도 실지 못하면 -1
크레인 한 바퀴 실으면 시간 1 지남

*/
