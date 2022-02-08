//
//  #9184_plus.cpp
//  algo_2022
//
//  Created by yujeong on 2022/02/08.
//

#include <iostream>
#include <cstring>
using namespace std;

int cache[21][21][21];

int w(int a, int b, int c){

    if (a <= 0 || b <= 0 || c <= 0){
        return 1;
    }
    
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
    
    if(cache[a][b][c] == 0) {
        if (a < b && b < c) return cache[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);

        else return cache[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
        
    }
        
    return cache[a][b][c];
}


int main(){
    
    int a=0, b=0, c=0;
    
    while(true){
        memset(cache, 0, sizeof(cache));
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) return 0;
        else {cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;}    }
}
