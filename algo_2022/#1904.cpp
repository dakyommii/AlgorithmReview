//
//  #1904.cpp
//  algo_2022
//
//  Created by yujeong on 2022/02/09.
//

#include <iostream>
#include <cstring>

using namespace std;
const int MOD = 15746;
int cache[1000001];

int solve(int n){
    if (n == 0 || n == 1) return cache[n]%MOD;
    
    else if (cache[n] == 0) return cache[n] = (solve(n-1) + solve(n-2))%MOD;

    return cache[n];
}

int main(){
    int n;
    cin >> n;
    memset(cache, 0, sizeof(cache));
    cache[0] = 1;
    cache[1] = 1;
    
    cout << solve(n);
    
}
