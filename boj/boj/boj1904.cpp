//
//  boj1904.cpp
//  boj
//
//  Created by 다곰 on 2022/02/11.
//

#include <iostream>
using namespace std;

int cache[1000001];

int dp(int n) {
    
    if (cache[n]) return cache[n];
    else return cache[n]=(dp(n-2)+dp(n-1))%15746;

}

int main() {
    int n;
    
    cin >> n;
    
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 3;
    
    cout << dp(n);
    
}
