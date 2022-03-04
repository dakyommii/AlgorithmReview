//
//  #1541.cpp
//  algo_2022
//
//  Created by yujeong on 2022/02/28.
//

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(){

    char expression[51] = "";
    cin >> expression;

    int cnt=0;

    vector<string> expre;

    char *ptr = strtok(expression, "-");    //첫번째 strtok 사용.

    while (ptr != NULL)              //ptr이 NULL일때까지 (= strtok 함수가 NULL을 반환할때까지)
    {
        expre.push_back(ptr);
        ptr = strtok(NULL, "-");     //자른 문자 다음부터 구분자 또 찾기
    }


    int temp=0;
    char ch[51];
    for (int i=0; i<expre.size(); i++) {
        cnt = 0;
        strcpy(ch, expre[i].c_str());
        char *ptr2 = strtok(ch, "+");    //첫번째 strtok 사용.

        while (ptr2 != NULL) {
            cnt += stoi(ptr2);
            ptr2 = strtok(NULL, "+");
        }
        if (i==0) {
            temp = cnt;
        }
        else temp = temp - cnt;

    }
    cout << temp<< endl;

    return 0;
}
