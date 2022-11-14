//
//  swea 1983.cpp
//  swea
//
//  Created by 다곰 on 2022/11/14.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, double>a,pair<int, double>b) {
    return a.second >b.second;
}

int main() {
    
    int T;
    int test_case=1;
    string score[10]={"A+","A0","A-","B+","B0","B-","C+","C0","C-","D0"};
    
    cin >> T;
    
    while (T--) {
        int n,k;
        cin >> n >> k;
        
        vector<pair<int, double>> v;
        for (int i=0; i<n; i++) {
            int mid, fin, hw;
            cin >> mid >> fin >> hw;
            v.push_back(make_pair(i, mid*0.35+fin*0.45+hw*0.2));
        }
        
        sort(v.begin(), v.end(), cmp);
        
        cout << "#" << test_case << " ";
        test_case++;
        
        for (int i=0; i<n; i++) {
            if(v[i].first==k-1) {
                cout << score[i/(n/10)] << endl;
                break;
            }
        }
    }
    
}

//* string score[10]; -> 총점 미리 저장

//1. pair로 인덱스, 총점 계산해서 입력
//2. 총점 기준 내림차순 정렬
//3. 순서/(k/10) 에 해당하는 점수가 정답
