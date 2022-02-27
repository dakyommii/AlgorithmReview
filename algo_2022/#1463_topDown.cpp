//
//  #1463.cpp
//  algo_2022
//
//  Created by yujeong on 2022/02/25.
//


#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


int n;
int cache[1000001];

int solve(int num){
    if (num == 1) return cache[1];

    if (cache[num] <= 0) {
        
        // 오직 3의 배수
        if (num % 3 == 0 && num%2 != 0) {
            int a = num / 3;
            int b = num - 1;
            cache[num] = 1+ min(solve(a), solve(b));
        }

        // 오직 2의 배수
        else if (num % 2 == 0 && num%3 != 0) {
            int a = num / 2;
            int b = num - 1;
            cache[num] = 1+ min(solve(a), solve(b));

        }

        // 6의 배수
        else if (num % 2 == 0 && num%3==0)  cache[num] = 1+ min(solve(num/2), solve(num/3));

        // 해당 안됨
        else {
            cache[num] =1+ solve(num - 1);
        }
    }

    return cache[num];
}

int main(){
    cin >> n;
    memset(cache, 0, sizeof(cache));

    cache[1] = 0;
    cache[2] = 1;
    cout << solve(n);

    return 0;
}
