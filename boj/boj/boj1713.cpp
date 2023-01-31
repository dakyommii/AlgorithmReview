//
//  boj1713.cpp
//  boj
//  retry - struct 대신 pair 로 해보기
//  time: 0 ms
//  memory: 2024 KB
//  Created by 다곰 on 2023/01/30.
//

#include <iostream>
#include <map>

using namespace std;

int main() {
    int n,m;
    cin >> n;
    cin >> m;
    
    map<int,pair<int, int>> photo;  //사진틀에 있는 사진: map<사진번호,추천횟수,게시시간>

    for(int i=0;i<m;i++) {
        int idx;
        cin >> idx;
        
        // 아직 사진 틀에 없는 사진일 경우
        if (photo.find(idx)==photo.end()) {
            // 사진 틀에 공간 있을 경우
            if (photo.size()<n) {
                photo[idx].first=1;
                photo[idx].second=i;
            }
            else {
                pair<int,int> v;
                int num=photo.begin()->first;   // 사진틀 첫번째 사진 번호 가져오기
                v=photo.begin()->second;    //사진틀 <추천횟수,게시시간> 세트 가져오기
                
                // 추천횟수가 작은 사진 탐색
                for (auto it:photo) {
                    // 추천횟수가 작은 사진 찾으면 최소 사진 번호, 세트를 갱신하면서 탐색
                    if (it.second<v) {
                        num=it.first;
                        v=it.second;
                    }
                }
                
                // 최종적으로 지울 사진 지우고 새로운 사진으로 세팅
                photo.erase(num);
                photo[idx].first=1;
                photo[idx].second=i;
            }
        }
        // 이미 사진틀에 있는 사진일 경우
        else photo[idx].first++;
        
    }
    
    for (auto it:photo) {
        cout << it.first << " ";
    }
}

//{게시시간, 사진 번호,사진 추천 횟수} -> 사진 추천횟수 내림차순, 게시시간 오름차순
//사진 게시 여부 bool 함수
//-> true 이면 사진 추천 횟수만 증가
//-> false 이면 사진틀에 사진 넣기
