//
//  #1149.cpp
//  algo_2022
//
//  Created by yujeong on 2022/02/13.
//

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int cache[1001][3];
int color[1001][3];


int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int cnt=0; cnt<3; cnt++) {
            cin >> color[i][cnt];   // i번째 집에 cnt번 색깔에 해당하는 비용
        }
    }

    cache[0][0] = color[0][0];
    cache[0][1] = color[0][1];
    cache[0][2] = color[0][2];

    for (int i=1; i<=n; i++) {
        cache[i][0] = min(cache[i-1][1], cache[i-1][2]) + color[i][0];
        cache[i][1] = min(cache[i-1][0], cache[i-1][2]) + color[i][1];
        cache[i][2] = min(cache[i-1][0], cache[i-1][1]) + color[i][2];
    }

    int mini = min(cache[n][0], cache[n][1]);
    mini = min(mini, cache[n][2]);
    cout << mini;
}


