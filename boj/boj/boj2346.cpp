//
//  boj2346.cpp
//  boj
//  time: 40ms
//  Created by 다곰 on 2022/07/15.
//

#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n,num;
    deque<int> dq;  //풍선에 들어간 값 저장한 덱
    deque<int> idx; //초기 순서 저장한 덱

    cin >> n;

    int k=0;
    while (n--) {
        cin >> num;
        dq.push_back(num);
        k++;
        idx.push_back(k);
    }
    
    int b=0,flag=1;
    while (!dq.empty()) {
        b=dq.front();   //풍선값 저장
        
        //음수, 양수 구분 위한 flag 설정
        if (b<0) flag=-1;
        else {  //양수의 경우 front를 pop하고 시작하기 때문에 이동할 자리를 하나 빼 줌
            flag=1;
            b-=1;
        }
        
        //front값 pop하고 pop한 인덱스 출력
        dq.pop_front();
        cout << idx.front() << endl;
        idx.pop_front();
        
        //풍선 값 만큼 자리 이동+인덱스 자리도 동일하게 이동
        for (int i=0; i<b*flag; i++) {
            if(flag>0) {
                k=dq.front();
                dq.push_back(k);
                
                k=idx.front();
                idx.push_back(k);
                
                dq.pop_front();
                idx.pop_front();
                
                
            }
            else {
                k=dq.back();
                dq.push_front(k);
                
                k=idx.back();
                idx.push_front(k);
                
                dq.pop_back();
                idx.pop_back();
            }
        }
    }



}
