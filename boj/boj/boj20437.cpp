//
//  boj20437.cpp
//  boj
//  memory: 2024 KB
//  time: 24 ms

//  Created by 다곰 on 2022/12/13.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        string w;
        int k;
        
        cin >> w;
        cin >> k;
        
        vector<vector<int>>v(26);
        
        for(int i=0;i<w.size();i++) {
            int k=w[i]-97;
            v[k].push_back(i);
        }
        
        int r1=10001,r2=-1;
        for (int i=0; i<v.size(); i++) {
            if (v[i].size()>=k) {
                for (int j=0; j+k-1<v[i].size(); j++) {
                    int sub=v[i][j+k-1]-v[i][j]+1;
                    r1=min(r1,sub);
                    r2=max(r2,sub);
                }
            }
            
        }
        if (r1==10001 && r2==-1) cout << -1 << endl;
        else cout << r1 << " " << r2 << endl;
        
//        if (r1==10001 && r2==-1) cout << -1 << endl;
           
    }
}

//1. 같은 문자를 k개 포함하는 최소길이 문자열
//2. 같은 문자를 k개 포함하면서 문자열의 첫번째, 마지막 문자가 같은 연속 문자열 길이 구하기
//
//t: 문자열 게임 수
//w: 문자열
//k: 정수
