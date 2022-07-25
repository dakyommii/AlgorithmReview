//
//  boj1021.cpp
//  boj
//  time: 0ms
//  Created by 다곰 on 2022/07/22.
//

#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int main() {
    int n, m,l=0,r=0;
    queue<int> q;   //원소 위치 저장한 큐
    deque<int> dq;  //N개의 원소 포함하고 있는 양방향 순환 큐
    
    cin >> n >> m;
    
    int num;
    while (m--) {
        cin >> num;
        q.push(num);
    }
    
    //순환 큐에는 1부터 N까지의 숫자로 채움
    for (int i=0; i<n; i++) {
        dq.push_back(i+1);
    }
    
    int cnt=0;
    while (!q.empty()) {
        //첫번째 원소가 찾으려는 원소 큐의 우선순위 원소(front 원소)와 같은 경우
        if (dq.front()==q.front()) {
            q.pop();
            dq.pop_front();

        }
        else {
            for (int i=1; i<dq.size(); i++) {
                if(dq.at(i)==q.front()) {
                    l=i;
                    break;
                }
            }
            
            for (int i=0; i<dq.size(); i++) {
                if(dq.at(dq.size()-(i+1))==q.front()) {
                    r=i;
                    break;
                }
            }
            
            //왼쪽과 더 가깝거나 양방향 모두와 가까울 경우, 왼쪽으로 이동: front의 값을 back으로 옮김
            if(l<=r) {
                num=dq.front();
                dq.push_back(num);
                dq.pop_front();
            }
            else {  //오른쪽과 더 가까울 경우, 오른쪽으로 이동: back의 값을 front로 옮김
                num=dq.back();
                dq.push_front(num);
                dq.pop_back();
            }
            l=0;r=0;    //left, right 거리 초기화
            cnt++;  //값을 옮겨준 후 cnt 더해줌
        }
        
        
    }
    
    cout << cnt << endl;
    

}
