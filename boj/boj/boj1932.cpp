//
//  boj1932.cpp
//  boj
//  time: 44 ms
//  memory: 2880 KB
//  Created by 다곰 on 2023/01/20.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int tri[501][501];
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            cin >> tri[i][j];
        }
    }
    
    for (int i=n; i>1; i--) {
        for (int j=1; j<i; j++) {
            tri[i-1][j]=max(tri[i][j]+tri[i-1][j],tri[i][j+1]+tri[i-1][j]);
        }
    }
    
    cout << tri[1][1] << endl;
}
