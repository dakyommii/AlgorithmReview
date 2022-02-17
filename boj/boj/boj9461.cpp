//
//  boj9461.cpp
//  boj
//
//  Created by 다곰 on 2022/02/17.
//

#include <iostream>
using namespace std;

long long cache[101];

long long p(int n) {
    if(cache[n]) return cache[n];
    else return cache[n] = p(n-5)+p(n-1);
}

int main() {
    int t,n;
    cin >> t;
    
    cache[1] = 1;
    cache[2] = 1;
    cache[3] = 1;
    cache[4] = 2;
    cache[5] = 2;
    
    while (t--) {
        cin >> n;
        cout << p(n) << endl;
    }
    
}
