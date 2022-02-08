//
//  boj1003.cpp
//  boj
//
//  Created by 다곰 on 2022/01/30.
//

#include <iostream>
using namespace std;

int cnt[41] = {0,1,};   //dp배열

int fibonacci(int n) {
    if (n == 0 || n == 1) return cnt[n];
    else if(cnt[n] == 0) return cnt[n] = fibonacci(n-1) + fibonacci(n-2);
    return cnt[n];
}


int main() {
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        if (n == 0) {
            cout << "1 0" << endl;
        }
        else
            cout << fibonacci(n-1) << " " << fibonacci(n) << endl;
    }
    
}
