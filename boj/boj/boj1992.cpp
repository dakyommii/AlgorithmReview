//
//  boj1992.cpp
//  boj
//  memory: 2028 KB
//  time: 0 ms
//  Created by 다곰 on 2023/11/14.
//

#include <iostream>
#include <vector>
using namespace std;

string board[64];

void press(int x, int y, int len) {
    
    char ch=board[x][y];
    for(int i=0;i<len;i++) {
        for(int j=0;j<len;j++) {
            if(board[x+i][y+j]!=ch) {
                cout << '(';
                press(x,y,len/2);
                press(x,y+len/2,len/2);
                press(x+len/2,y,len/2);
                press(x+len/2,y+len/2,len/2);
                cout << ')';
                return;
            }
        }
    }
    
    cout << ch;
}

int main() {
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++) {
        cin >> board[i];
    }
    
    press(0,0,n);
    
}
