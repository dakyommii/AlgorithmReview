//
//  boj1541.cpp
//  boj
//
//  Created by 다곰 on 2022/03/01.
//- 부호 사이의 수식을 묶어주는 것이 관건

#include <iostream>
#include <string>
using namespace std;


int main() {
    
    string s;   //입력받은 수식
    int op = 1; //부호 저장
    int num=0, ans=0;   //num: 숫자 저장공간, ans: 최종정답
    cin >> s;
    
    for (int i = 0; i < s.size(); i++) {
        //부호 만나면 이전까지 저장한 숫자들 더해주고 num 초기화
        if (s[i] == '+') {
            ans+=num;
            num=0;
        }
        else if(s[i]=='-') {
            op=-1;  //- 부호 만나면 그 뒤의 숫자들은 다시 - 부호 만나거나 수식의 끝에 도달할 때까지 모두 -부호 인식 flag
            ans+=num;
            num=0;
        }
        else {  //부호를 구분해주어야하므로 부호도 num값에 곱해주고 더해줌. 이전에 저장된 숫자들에는 10 곱해주고 새롭게 만난 숫자들은 부호 곱해서 더해줌
            num = 10*num+ (s[i]-'0')*op;
        }
    }
    
    ans+=num;   //마지막에 저장된 숫자 최종 정답에 더해줌
    
    cout << ans;
    

}
