//
//  #9461.cpp
//  algo_2022
//
//  Created by yujeong on 2022/02/13.
//

#include <iostream>
#include <cstring>

using namespace std;
long long cache[101];

long long solve(int num){
    
    // 처음
    if (cache[num] < 0) return cache[num] = solve(num-2)+solve(num-3);
    
    return cache[num];
    
}

int main(){
    int tc;
    cin >> tc;
    
    while(tc--){
        memset(cache, -1, sizeof(cache));
        cache[0] = 0;
        cache[1] = 1;
        cache[2] = 1;
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
}

