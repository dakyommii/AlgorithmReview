//
//  boj9184.cpp
//  boj
//
//  Created by 다곰 on 2022/02/08.
//

#include <iostream>
using namespace std;

int a, b, c;
int dp[51][51][51];


int w(int a, int b, int c) {
    
    if(a<=0 || b <=0 || c<=0) return 1;
    if(dp[a][b][c] != 0) return dp[a][b][c];
    if(a>20|| b>20 || c>20) return dp[a][b][c] = w(20,20,20);
    if(a < b and b < c) return dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    else
        return dp[a][b][c] =w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);

}

int main() {

    while (1) {

        cin >> a >> b>> c;
        if(a == -1 && b==-1 && c==-1) break;
        
        cout << "w(" << a << ", " << b << ", " << c <<") = " << w(a,b,c) << endl;
    }

    
}
