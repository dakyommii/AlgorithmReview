//
//  boj10816.cpp
//  boj
//
//  Created by 다곰 on 2022/04/01.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,c,m;
    
    cin >> n;

    while (n--) {
        cin >> c;
        v.push_back(c);
    }
    
    sort(v.begin(),v.end());

    cin >> m;

    while (m--) {
        cin >> c;
        cout << upper_bound(v.begin(), v.end(), c) - lower_bound(v.begin(), v.end(), c) << " ";

    }
    
}

/*
 배열로 할 경우, 메모리 변화 확인 필요
 */
