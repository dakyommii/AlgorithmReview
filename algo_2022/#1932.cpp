//
//  #1932.cpp
//  algo_2022
//
//  Created by yujeong on 2022/02/25.
//

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int cache[501][501];
int tri[501][501] = {0,};

int n;

int solve(int x, int y){
    
    if (y >= n || x >= n) return 0;
    
    if (cache[x][y] < 0) {
        return cache[x][y] = max(solve(x,y+1), solve(x+1,y+1)) + tri[x][y];
    }
    
    return cache[x][y];
}

int main(){
    cin >> n;
    
    memset(cache, -1, sizeof(cache));
    
    for (int i=0; i<n; i++)
        for (int j=0; j<=i; j++)
            cin >> tri[j][i];
    
    cout << solve(0, 0);
    return 0;
}
