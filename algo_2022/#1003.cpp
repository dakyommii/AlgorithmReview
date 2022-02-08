//
//  #1003.cpp
//  algo_2022
//
//  Created by yujeong on 2022/02/08.
//

#include <iostream>
#include <cstring>
using namespace std;

int cache[41]={0};

int fibonacci(int n) {
    if (n == 0 || n == 1){
        return cache[n];
    }
    else if (cache[n] == 0) {
        cache[n] = fibonacci(n-1) + fibonacci(n-2);
    }
    return cache[n];
}

int main(){
    int tc;
    cin >> tc;
    int num;
    while(tc--){
        memset(cache, 0, sizeof(cache));
        cin >> num;
        cache[1]=1;
        if (num-1 < 0){
            cout << 1;
        }
        else{
            cout << fibonacci(num-1);
        }
        
        cout << " " << fibonacci(num) << endl;
    }
}
