//
//  #2579_p.cpp
//  algo_2022
//
//  Created by yujeong on 2022/02/25.
//

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int cache[301];
int stairs[301];

int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> stairs[i];
    }
    cache[0] = 0;
    cache[1] = stairs[1];
    cache[2] = stairs[1] + stairs[2];
    for (int i = 3; i <= n; i++) {
        cache[i] = max(stairs[i] + cache[i-2], stairs[i] + stairs[i-1] + cache[i-3]);
    }
    cout << cache[n];
    return 0;
}
