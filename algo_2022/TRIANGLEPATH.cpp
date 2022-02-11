//
//  TRIANGLEPATH.cpp
//  algo_2022
//
//  Created by yujeong on 2022/02/09.
//

#include <iostream>
#include <cstring>

using namespace std;

int n;
int triangle[101][101];
int cache[101][101];

int solve(int x, int y){
    
    if (x>=n || y >=n) return 0;
    
    else if (cache[x][y] <= 0) return cache[x][y] = triangle[x][y] + max(solve(x,y+1), solve(x+1, y+1));
    
    return cache[x][y];
}

int main(){
    int tc;
    cin >> tc;
    
    while (tc--) {
        cin >> n;
        memset(cache, 0, sizeof(cache));
        for (int i=0; i<n; i++) {
            for (int j=0; j<=i; j++) {
                cin >> triangle[j][i];
            }
        }
        
        cout << solve(0,0) << endl;
    }

    
}
