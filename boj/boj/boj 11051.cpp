//
//  boj 11051.cpp
//  boj
//  time: 4ms
//  memory: 5980 KB
//  Created by 다곰 on 2023/01/13.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    
    vector<vector<int>> v(n+1,vector<int>(n+1,0));
    
    v[0][0]=1;
    for(int i=1;i<=n;i++) {
        v[i][0]=1;
        for (int j=1; j<=i; j++) {
            v[i][j]=(v[i-1][j]+v[i-1][j-1]) %10007;
        }
    }
    
    
    cout << v[n][k] %10007 << endl;

}

