//
//  #13305.cpp
//  algo_2022
//
//  Created by yujeong on 2022/02/28.
//

#include <iostream>
using namespace std;

long long city[100001][2];

int main(){
    int n;
    cin >> n;
    
    // 도로의 길이
    for (int i=0; i<n-1; i++) {
        cin >> city[i][1];
    }
    
    // 주유소의 리터당 가격
    for (int i=0; i<n; i++) {
        cin >> city[i][0];
    }
    
    long long temp = city[0][0];
    long long price = temp*city[0][1];
    for (int i=1; i<=n; i++) {
        if (temp<city[i][0]) {
            // 뒤에 애만큼 가주고 temp는 유지
            price += temp*city[i][1];
        }
        else{
            // temp 변경
            temp = city[i][0];
            price += temp*city[i][1];
        }
    }
    
    cout << price << endl;
    
    return 0;
}

