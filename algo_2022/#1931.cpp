//
//  #1931.cpp
//  algo_2022
//
//  Created by yujeong on 2022/02/27.
//

#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;


int main(){
    int n;
    cin >> n;
    
    vector<pair<int, int>> time;
    int a,b;
    
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        time.push_back(pair<int, int>(b, a));
    }
    
    sort(time.begin(), time.end()); // 빨리 끝나는 시간부터 정렬
    

    int temp = time[0].first;
    int cnt=1;
    for (int i=1; i<n; i++) {
        if (temp <= time[i].second) {
            // 만약 temp(앞에 끝난 시간)보다 time[i].second(뒤에 시작 시간)이 큰 경우 cnt++ 하고 temp 바꾸기
            cnt++;
            temp = time[i].first;
        }
        
    }
    
    cout << cnt;
    
}


