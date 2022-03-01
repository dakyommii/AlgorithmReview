//
//  boj1931.cpp
//  boj
//
//  Created by 다곰 on 2022/03/01.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> arr;

/*2차원 vector 안쪽 인수를 기준으로 오름차순 정렬*/
bool cmp(vector<int> &v1, vector<int> &v2) {
    if(v1[1] == v2[1]) return v1[0]<v2[0];
    else return v1[1] < v2[1];
}

int main() {
    int n, end, cnt=0;
    cin >> n;
    arr.assign(n, vector<int>(2,0));    //2차원 vector 동적 할당

    for (int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1];
    sort(arr.begin(),arr.end(),cmp);    //정렬

    /*정렬한 결과 첫번째에 온다는 것은 끝나는 시간이 가장 빠르다는 뜻이므로 일단 저장하고 시작*/
    cnt++;
    end = arr[0][1];

    //2번째 수부터 탐색
    for (int i = 1; i < n; i++) {
        if(arr[i][0] >= end) {
            cnt++;
            end=arr[i][1];
        }
    }
    cout << cnt;
}
