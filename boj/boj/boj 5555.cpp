//
//  boj 5555.cpp
//  boj
//  memory: 2024 KB
//  time: 0 ms

//  Created by 다곰 on 2022/12/13.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s,ini;
    int n,cnt=0;
    
    cin >> s;
    cin >> n;
    
    string arr[100];
    while(n--) {
        cin >> ini;
        string str=ini;
        str+=ini;
        
        if(str.find(s)<str.size()) {
            cnt++;
        }
    }
    
    cout << cnt << endl;
}

/*
input
문자열: s
반지 개수: n
각 반지 이니셜 10자 입력

반지가 이어져 있으니까 그냥 20자로 붙여버리기..?
*/
