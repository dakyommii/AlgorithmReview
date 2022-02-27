//
//  #1463_bottomUp.cpp
//  algo_2022
//
//  Created by yujeong on 2022/02/25.
//

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


int n;
int cache[1000001];

int main(){
    cin >> n;
    memset(cache, 0, sizeof(cache));

    cache[1] = 0;
    cache[2] = 1;
    for (int i=3; i<=n; i++) {
        cache[i] = cache[i-1] + 1;
        if (i%3 == 0) cache[i] = min(1+ cache[i/3], cache[i]);
        if (i%2 == 0) cache[i] = min(1+ cache[i/2], cache[i]);
    }
    cout << cache[n];

    return 0;
}


