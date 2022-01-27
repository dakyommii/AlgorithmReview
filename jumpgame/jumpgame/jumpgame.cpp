//
//  main.cpp
//  jumpgame
//
//  Created by 다곰 on 2022/01/26.
//

#include <iostream>
#include <cstring>
using namespace std;

int c,n;
int arr[100][100];
int v[100][100];

int sol(int a, int b) {
    
    if (a == n-1 && b == n-1) return 1; //마지막 자리까지 가면 끝
    if(a >=n || b >=n) return 0;    //out of range 방지
        
    int& r = v[a][b]; //방문 여부를 ret에 받아옴 -> *왜 참조인지는 모르겠음*
    if(r!=-1) return r; //이미 방문한 곳이면 나오기
    
    int k = arr[a][b];  //해당 위치 크기 받아오기
    
    return r = (sol(a,b+k) || sol(a+k,b));
}

int main() {
    ios_base::sync_with_stdio(false);
        cin.tie(NULL);

    cin >> c;
    while (c--) {
        memset(v, -1, sizeof(v));   //아직 방문 전이면 무조건 -1
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j  = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        
        if (sol(0,0) == 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
